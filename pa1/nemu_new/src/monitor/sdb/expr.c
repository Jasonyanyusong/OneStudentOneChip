/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "sdb.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <string.h>

// Tesk Token #1: p 0x8000 + 123 - 6 * (5 + 4)
// Test Token #2: p 123 + 456 + 789
// Test Token #3: p 123+456+789
// Test Token #4: p 0x8000 + 123
// Test Token #5: p 0x8fff + 0x1234

enum {
 TK_NOTYPE = 256,
 TK_EQ = 255,
 TK_NEQ = 254,
 TK_AND = 253,
 TK_OR = 252,
 TK_NOT = 250,
 TK_POINTER = 249,
 TK_NUMBER = 248,
 TK_HEXNUMBER = 247,
 TK_REGISTER = 246,
 TK_MARK = 245,
 TK_OCTNUMBER = 244,
 TK_BINNUMBER = 243,
 TK_PLUS = 242,
 TK_MINUS = 241,
 TK_MULTIPLY = 240,
 TK_DIVIDE = 239,
 TK_LEFT_PARENTHESES = 238,
 TK_RIGHT_PARENTHESES = 237,
};

bool check_parentheses(int left_index, int right_index); // Used in eval()
bool check_parentheses_balance(); // Used in expr()
void process_operator_token();
bool valid_call;

bool expr_print_instruction = true;
bool expr_print_debug = true;
bool expr_print_checkpoint = true;
bool expr_print_assertpoint = true;
void set_expr_print_instruction(bool target_expr_print_instruction);
void set_expr_print_debug(bool target_expr_print_debug);
void set_expr_print_checkpoint(bool target_expr_print_checkpoint);
void set_expr_print_assertpoint(bool target_expr_print_assertpoint);

struct OperatorToken
{
  const char *regex;
  int token_type;
  int priority;
  int position;
} operator_tokens[32];

int nr_operator_token = 0;

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE}, // Spaces
  {"0x[0-9,a-f]+", TK_HEXNUMBER}, // Hex Numbers
  {"[0-9]+", TK_NUMBER}, // Dec Numbers
  {"0o[0-7]+", TK_OCTNUMBER}, // Oct Numbers
  {"0b[0-1]+", TK_BINNUMBER}, // Bin Numbers
  {"\\$[a-z]{2,3}", TK_REGISTER}, // Register Names
  {"\\(", TK_LEFT_PARENTHESES}, // Left Parenthesis IS_OPERATOR_TOKEN
  {"\\)", TK_RIGHT_PARENTHESES}, // Right Parenthesis IS_OPERATOR_TOKEN
  {"\\*", TK_MULTIPLY}, // Multiply IS_OPERATOR_TOKEN
  {"\\/", TK_DIVIDE}, // Devide IS_OPERATOR_TOKEN
  {"\\+", TK_PLUS}, // Plus IS_OPERATOR_TOKEN
  {"\\-", TK_MINUS}, // Minus IS_OPERATOR_TOKEN
  {"==", TK_EQ}, // Equal IS_OPERATOR_TOKEN
  {"!=", TK_NEQ}, // Not Equal IS_OPERATOR_TOKEN
  {"&&", TK_AND}, // And IS_OPERATOR_TOKEN
  {"\\|\\|", TK_OR}, // Or IS_OPERATOR_TOKEN
  {"!", TK_NOT}, // Not IS_OPERATOR_TOKEN
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

void set_expr_print_instruction(bool target_expr_print_instruction)
{
  expr_print_instruction = target_expr_print_instruction;
  if(expr_print_instruction)
  {
    printf("expr_print_instruction: ON\n");
  }
  else
  {
    printf("expr_print_instruction: OFF\n");
  }
  return;
}

void set_expr_print_debug(bool target_expr_print_debug)
{
  expr_print_debug = target_expr_print_debug;
  if(expr_print_debug)
  {
    printf("expr_print_debug: ON\n");
  }
  else
  {
    printf("expr_print_debug: OFF\n");
  }
  return;
}

void set_expr_print_checkpoint(bool target_expr_print_checkpoint)
{
  expr_print_checkpoint = target_expr_print_checkpoint;
  if(expr_print_checkpoint)
  {
    printf("expr_print_checkpoint: ON\n");
  }
  else
  {
    printf("expr_print_checkpoint: OFF\n");
  }
  return;
}

void set_expr_print_assertpoint(bool target_expr_print_assertpoint)
{
  expr_print_assertpoint = target_expr_print_assertpoint;
  if(expr_print_assertpoint)
  {
    printf("expr_print_assertpoint: ON\n");
  }
  else
  {
    printf("expr_print_assertpoint: OFF\n");
  }
  return;
}

bool get_expr_print_instruction()
{
  return expr_print_instruction;
}
bool get_expr_print_debug()
{
  return expr_print_debug;
}
bool get_expr_print_checkpoint()
{
  return expr_print_checkpoint;
}
bool get_expr_print_assertpoint()
{
  return expr_print_assertpoint;
}

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #01\n");
    }
    for (i = 0; i < NR_REGEX; i ++) {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #02\n");
      }
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        if(expr_print_checkpoint)
        {
          printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #03\n");
        }
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        // printf("make_token() Check Point #4\n");
        switch (rules[i].token_type) 
        {
          default:
          {
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #04\n");
            }
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Use Default\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_NOTYPE:
          {
            // Case No.1
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #05\n");
            }
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_NOTYPE TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] TK_NOTYPE will be thrown away directly\n");
            }
            break;
          }
          case TK_EQ:
          {
            // Case No.2
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #06\n");
            }
            tokens[nr_token].type = TK_EQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_EQ TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_NEQ:
          {
            // Case No.3
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #07\n");
            }
            tokens[nr_token].type = TK_NEQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_NEQ TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_NOT:
          {
            // Case No.4
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #08\n");
            }
            tokens[nr_token].type = TK_NOT;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_NOT TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_AND:
          {
            // Case No.5
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #09\n");
            }
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_AND TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_OR:
          {
            // Case No.6
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #10\n");
            }
            tokens[nr_token].type = TK_OR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_OR TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_POINTER:
          {
            // Case No.7
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #11\n");
            }
            tokens[nr_token].type = TK_POINTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_POINTER TOKEN\n");

              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_BINNUMBER:
          {
            // Case No.8
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #12\n");
            }
            tokens[nr_token].type = TK_BINNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_BINNUMBER TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_OCTNUMBER:
          {
            // Case No.9
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #13\n");
            }
            tokens[nr_token].type = TK_OCTNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_OCTNUMBER TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_NUMBER:
          {
            // Case No.10
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #14\n");
            }
            tokens[nr_token].type = TK_NUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_NUMBER TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_HEXNUMBER:
          {
            // Case No.11
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #15\n");
            }
            tokens[nr_token].type = TK_HEXNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_HEXNUMBER TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_REGISTER: // !!! Special Case
          {
            // Case No.12
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #16\n");
            }
            tokens[nr_token].type = TK_REGISTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_REGISTER TOKEN\n");

              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_MARK:
          {
            // Case No.13
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #17\n");
            }
            tokens[nr_token].type = TK_MARK;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_MARK TOKEN\n");

              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_LEFT_PARENTHESES:
          {
            // Case No.14
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #18\n");
            }
            tokens[nr_token].type = TK_LEFT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_LEFT_PARENTHESES TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_RIGHT_PARENTHESES:
          {
            // Case No.15
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #19\n");
            }
            tokens[nr_token].type = TK_RIGHT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_RIGHT_PARENTHESES TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_MULTIPLY:
          {
            // Case No.16
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #20\n");
            }
            tokens[nr_token].type = TK_MULTIPLY;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_MULTIPLY TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_DIVIDE:
          {
            // Case No.17
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #21\n");
            }
            tokens[nr_token].type = TK_DIVIDE;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_DIVIDE TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_PLUS:
          {
            // Case No.18
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #22\n");
            }
            tokens[nr_token].type = TK_PLUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_PLUS TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_MINUS:
          {
            // Case No.19
            if(expr_print_checkpoint)
            {
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #23\n");
            }
            tokens[nr_token].type = TK_MINUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] Found a TK_MINUS TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] This is a OPERATOR_TOKEN\n");
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].type is: %d\n", tokens[nr_token].type);
              printf("[EXPR DEBUG: static bool make_token(char *e)] tokens[nr_token].str is: \"%s\"\n", tokens[nr_token].str);
            }
            nr_token = nr_token + 1;
            break;
          }
        }
        if(expr_print_checkpoint)
        {
          printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #24\n");
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #25\n");
      }
      Log("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  // Debug Point: Print Tokens
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #26\n");
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: static bool make_token(char *e)] Token Numbers (Decimal): %d\n", nr_token);
  }
  for(int display_index = 0; display_index < nr_token; display_index = display_index + 1)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: static bool make_token(char *e)] Token Number: %4d, Token Type (Decimal ID): %4d, Token String: \"%s\"\n", display_index, tokens[display_index].type, tokens[display_index].str);
    }
  }

  // Debug Point: Check Parentheses
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #27\n");
  }
  for(int left_scan_index = 0; left_scan_index < nr_token; left_scan_index = left_scan_index + 1)
  {
    for(int right_scan_index = left_scan_index + 1; right_scan_index < nr_token; right_scan_index = right_scan_index + 1)
    {
      if(check_parentheses(left_scan_index, right_scan_index))
      {
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: static bool make_token(char *e)] Paired Success, Left Index: %d, Right Index: %d\n", left_scan_index, right_scan_index);
        }
      }
      else
      {
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: static bool make_token(char *e)] Paired Failed, Left Index: %d, Right Index: %d\n", left_scan_index, right_scan_index);
        }
      }
    }
  }

  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #28\n");
  }
  
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: static bool make_token(char *e)] Start Only Two Side Parentheses Check\n");
  }
  // Debug Point: Only Two Side Parentheses Check
  if(check_parentheses(0, nr_token - 1))
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: static bool make_token(char *e)] Left: %d, Right: %d. Only Two Side Parentheses Check MATCHED\n", 0, nr_token - 1);
    }
  }
  else
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: static bool make_token(char *e)] Left: %d, Right: %d. Only Two Side Parentheses Check FAILED\n", 0, nr_token - 1);
    }
  }

  return true;
}

bool check_parentheses(int left_index, int right_index)
{
  // Fail conditions:
  // 1): Left side is not parenthese, Example: "1 + (2 + 3)"
  // 2): Right side is not parenthese, Example: "(1 + 2) + 3"
  // 3): Balance before reaching end, Example: "(1 + ))"
  // 4): Not Balance after reaching end, Example: "(1 + (2 + 3)"

  int left_right_balance = 0;

  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #01\n");
  }

  if(tokens[left_index].type != TK_LEFT_PARENTHESES)
  {
    // Check Type I
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #02\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses(int left_index, int right_index)] At Tokens Index: %d, get Type I Fail, Left side is not parenthese\n", left_index);
    }
    return false;
  }

  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #03\n");
  }

  if(tokens[right_index].type != TK_RIGHT_PARENTHESES)
  {
    // Check Type II
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #04\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses(int left_index, int right_index)] At Tokens Index: %d, get Type II Fail, Right side is not parenthese\n", right_index);
    }
    return false;
  }

  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #05\n");
  }

  for(int current_index = left_index; current_index <= right_index; current_index = current_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #06\n");
    }
    if(tokens[current_index].type == TK_LEFT_PARENTHESES)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #07\n");
      }
      left_right_balance = left_right_balance + 1;
    }
    if(tokens[current_index].type == TK_RIGHT_PARENTHESES)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #08\n");
      }
      left_right_balance = left_right_balance - 1;
    }
    if(current_index != right_index && left_right_balance == 0)
    {
      // Check Type III
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #09\n");
      }
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: bool check_parentheses(int left_index, int right_index)] At Tokens Index: %d, get Type III Fail, Balance before reaching end\n", current_index);
      }
      return false;
    }
  }

  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #10\n");
  }

  if(left_right_balance == 0)
  {
    // Check Type IV
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #11\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses(int left_index, int right_index)] Check SUCCESS, parentheses are balanced!\n");
    }
    return true;
  }
  else
  {
    // Check Type IV
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses(int left_index, int right_index)] CKPT #12\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses(int left_index, int right_index)] At Tokens Index: %d, get Type IV Fail, Not Balance after reaching end\n", right_index);
    }
    return false;
  }
}

bool check_parentheses_balance()
{
  // This function is a more convenient version of check_parentheses(int left_index, int right_index)
  // With default left_index = 0 and right_index = nr_token - 1, and tolerence for Type I and Type II parentheses error
  // This can make it more efficient when the cmd_p command execute, for expr with different left parentheses count and right parentheses count, the cmd_p can quit immediately
  int check_parentheses_balance_left_count = 0;
  int check_parentheses_balance_right_count = 0;
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses_balance()] CKPT #01\n");
  }

  for(int current_check_index = 0; current_check_index < nr_token; current_check_index = current_check_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses_balance()] CKPT #02\n");
    }
    if(tokens[current_check_index].type == TK_LEFT_PARENTHESES)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: bool check_parentheses_balance()] CKPT #03\n");
      }
      check_parentheses_balance_left_count = check_parentheses_balance_left_count + 1;
    }
    if(tokens[current_check_index].type == TK_RIGHT_PARENTHESES)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: bool check_parentheses_balance()] CKPT #04\n");
      }
      check_parentheses_balance_right_count = check_parentheses_balance_right_count + 1;
    }
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: bool check_parentheses_balance()] get check_parentheses_balance_left_count = %d\n", check_parentheses_balance_left_count);
    printf("[EXPR DEBUG: bool check_parentheses_balance()] get check_parentheses_balance_right_count = %d\n", check_parentheses_balance_right_count);
  }
  if(check_parentheses_balance_left_count == check_parentheses_balance_right_count)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses_balance()] CKPT #05\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses_balance()] BALANCED\n");
    }
    return true;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: bool check_parentheses_balance()] NOT BALANCED\n");
  }
  return false;
}

void process_operator_token()
{
  if(expr_print_debug)
  {
    printf("[EXPR CHECKPOINT: void process_operator_token()] CKPT #01\n");
  }
  return;
}

u_int64_t eval(int p, int q) // p = left index, q = right index
{
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #01 @@@@\n");
  }
  if(valid_call == false)
  {
    printf("Invalid Call\n");
    // OK
    return 0;
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #02 @@@@\n");
  }
  if(q > p)
  {
    valid_call = false;
    printf("Invalid eval() call\n");
    // OK
    return 0;
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #03 @@@@\n");
  }
  if(p == q)
  {
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #04 @@@@\n");
    }
    if(expr_print_debug)
    {
      //printf("~~~~ eval(p,q) call with p=q, will just return the number ~~~~\n");
    }
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #05 @@@@\n");
    }
    u_int64_t number = 0;
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #06 @@@@\n");
    }
    if(tokens[p].type == TK_NUMBER)
    {
      sscanf(tokens[p].str, "%ld", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #07 @@@@\n");
    }
    if(tokens[p].type == TK_HEXNUMBER)
    {
      sscanf(tokens[p].str, "%lx", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #08 @@@@\n");
    }
    if(tokens[p].type == TK_OCTNUMBER)
    {
      sscanf(tokens[p].str, "%lo", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      //printf("@@@@ u_int64_t eval(int p, int q) CKPT #09 @@@@\n");
    }
    // We should add more codes here.
    return number;
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #10 @@@@\n");
  }
  u_int64_t answer = 0;
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #11 @@@@\n");
  }
  if(check_parentheses(p, q) == true)
  {
    // OK
    return eval(p + 1, q - 1);
  }
  else
  {
    if(expr_print_assertpoint)
    {
      //printf("//// Assert Point #1 ////\n");
    }
    // We should do more things here.
    assert(0);
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ u_int64_t eval(int p, int q) CKPT #12 @@@@\n");
  }
  return answer;
}

word_t expr(char *e, bool *success) {
  //eval();
  if(expr_print_checkpoint)
  {
    //printf("@@@@ word_t expr(char *e, bool *success) CKPT #01 @@@@\n");
  }
  
  if(!check_parentheses_balance())
  {
    if(expr_print_checkpoint)
    {
      //printf("@@@@ word_t expr(char *e, bool *success) CKPT #02 @@@@\n");
    }
    *success = false;
    valid_call = false;
    if(expr_print_debug)
    {
      //printf("!!!! expr() exited because check_parentheses_balance() returned FALSE !!!!\n");
    }
    return 0;
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ word_t expr(char *e, bool *success) CKPT #03 @@@@\n");
  }

  if (!make_token(e)) {
    if(expr_print_checkpoint)
    {
      //printf("@@@@ word_t expr(char *e, bool *success) CKPT #04 @@@@\n");
    }
    *success = false;
    valid_call = false;
    return 0;
  }
  if(expr_print_checkpoint)
  {
    //printf("@@@@ word_t expr(char *e, bool *success) CKPT #05 @@@@\n");
  }
  valid_call = true; // Prob: if this line is not annotated, it will cause Segmentation fault

  *success = true;
  if(expr_print_checkpoint)
  {
    //printf("@@@@ word_t expr(char *e, bool *success) CKPT #06 @@@@\n");
  }
  u_int64_t expr_ans = eval(0, nr_token - 1);
  if(expr_print_checkpoint)
  {
    //printf("@@@@ word_t expr(char *e, bool *success) CKPT #07 @@@@\n");
  }

  printf("Evaluate Success, Ans (Hex): %lx, Ans (Dec): %ld, Ans (Oct): %lo\n", expr_ans, expr_ans, expr_ans);
  return 0;
}