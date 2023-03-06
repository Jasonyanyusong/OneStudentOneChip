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
bool check_parentheses_valid(); // Used in give_priority_no_parentheses()
bool check_left_token_is_number_or_bool(int check_index);
bool check_right_token_is_number_or_bool(int check_index);
void process_operator_token();
void give_priority();
void give_priority_no_parentheses();
int bool_to_int(bool bool_value);
bool valid_call;
int nr_operator_token;
int nr_optimized_token;

bool expr_print_instruction = true;
bool expr_print_debug = true;
bool expr_print_checkpoint = true;
bool expr_print_assertpoint = true;
void set_expr_print_instruction(bool target_expr_print_instruction);
void set_expr_print_debug(bool target_expr_print_debug);
void set_expr_print_checkpoint(bool target_expr_print_checkpoint);
void set_expr_print_assertpoint(bool target_expr_print_assertpoint);
char* decimal_number_to_binary_string(int number);
int find_dominant_operator(int left, int right, bool *expr_valid_call);

int process_add(int add_operator_index);
int process_minus(int minus_operator_index);
int process_multiply(int multiply_operator_index);
int process_devide(int devide_operator_index);
int process_equal(int equal_operator_index);
int process_not_equal(int not_equal_operator_index);
int process_and(int and_operator_index);
int process_or(int or_operator_index);
int process_not(int not_operator_index);

void expr_init();
void init_tokens();
void init_operator_tokens();
void init_operator_tokens_no_parentheses();
void init_optimized_tokens();

struct OperatorToken
{
  const char *regex;
  int token_type;
  int priority;
  int position;
} operator_tokens[32];

struct OperatorTokenNoParentheses
{
  const char *regex;
  int token_type;
  int priority_level;
  int position;
} operator_tokens_no_parentheses[32];

struct OptimizedToken
{
  int type;
  char str[32];
} optimized_tokens_a[32], optimized_tokens_b[32];

int nr_optimized_token = 0;
int nr_operator_tokens_no_parentheses = 0;
int nr_operator_token = 0;

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE}, // Spaces
  {"0x[0-9,a-f]+", TK_HEXNUMBER}, // Hex Numbers
  {"0o[0-7]+", TK_OCTNUMBER}, // Oct Numbers
  {"0b[0-1]+", TK_BINNUMBER}, // Bin Numbers
  {"[0-9]+", TK_NUMBER}, // Dec Numbers
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

char* decimal_number_to_binary_string(int number)
{
  // TODO
  return NULL;
}

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

void expr_init()
{
  init_tokens();
  init_operator_tokens();
  init_operator_tokens_no_parentheses();
  init_optimized_tokens();
  return;
}

void init_tokens()
{
  // TODO
  for(int init_tokens_index = 0; init_tokens_index < 32; init_tokens_index = init_tokens_index + 1)
  {
    memset(tokens[init_tokens_index].str,0,sizeof(tokens[init_tokens_index].str));
    tokens[init_tokens_index].type = -1;
    // TODO
  }
  return;
}

void init_operator_tokens()
{
  // TODO
  for(int init_operator_tokens_index = 0; init_operator_tokens_index < 32; init_operator_tokens_index = init_operator_tokens_index + 1)
  {
    operator_tokens[init_operator_tokens_index].regex = NULL;
    operator_tokens[init_operator_tokens_index].position = -1;
    operator_tokens[init_operator_tokens_index].priority = -1;
    operator_tokens[init_operator_tokens_index].token_type = -1;
    // TODO
  }
  return;
}

void init_operator_tokens_no_parentheses()
{
  // TODO
  for(int init_operator_tokens_no_parentheses_index = 0; init_operator_tokens_no_parentheses_index < 32; init_operator_tokens_no_parentheses_index = init_operator_tokens_no_parentheses_index + 1)
  {
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].regex = NULL;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].position = -1;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].priority = -1;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].token_type = -1;
    // TODO
  }
  return;
}

void init_optimized_tokens()
{
  // TODO
  for(int init_optimized_tokens_index = 0; init_optimized_tokens_index < 32; init_optimized_tokens_index = init_optimized_tokens_index + 1)
  {
    memset(optimized_tokens_a[init_optimized_tokens_index].str,0,sizeof(optimized_tokens_a[init_optimized_tokens_index].str));
    memset(optimized_tokens_b[init_optimized_tokens_index].str,0,sizeof(optimized_tokens_b[init_optimized_tokens_index].str));
    optimized_tokens_a[init_optimized_tokens_index].type = -1;
    optimized_tokens_b[init_optimized_tokens_index].type = -1;
    // TODO
  }
  return;
}

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
              printf("[EXPR CHECKPOINT: static bool make_token(char *e)] CKPT #04: switch (rules[i].token_type) to DEFAULT\n");
            }
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_EQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NEQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NOT;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_OR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_POINTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_BINNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_OCTNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_HEXNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_REGISTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MARK;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_LEFT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_RIGHT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MULTIPLY;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_DIVIDE;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_PLUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MINUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(expr_print_debug)
            {
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_start is \"%s\"\n", substr_start);
              printf("[EXPR DEBUG: static bool make_token(char *e)] substr_len is \"%d\"\n", substr_len);
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

void give_priority()
{
  // Give priority ignoring the parentheses
  // Current Precidency Level: (No Parentheses Considered)
  // 1) Or 2) AND 3) EQ/NEQ 4) PLUS/MINUS 5) MULTIPLY/DEVIDE 6) NOT
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: void give_priority()] CKPT #01: Enter function\n");
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: void give_priority()] nr_operator_token = %d\n", nr_operator_token);
  }
  for(int give_priority_index = 0; give_priority_index < nr_operator_token; give_priority_index = give_priority_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: void give_priority()] CKPT #02: Enter give priority loop at give_priority_index = %d\n", give_priority_index);
    }
    switch(operator_tokens[give_priority_index].token_type)
    {
      case TK_OR:
      {
        // Precidency Level: 1
        operator_tokens[give_priority_index].priority = 1;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_OR operator, set priority to 1\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_AND:
      {
        // Precidency Level: 2
        operator_tokens[give_priority_index].priority = 2;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_AND operator, set priority to 2\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_EQ:
      {
        // Precidency Level: 3
        operator_tokens[give_priority_index].priority = 3;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_EQ operator, set priority to 3\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_NEQ:
      {
        // Precidency Level: 3
        operator_tokens[give_priority_index].priority = 3;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_NEQ operator, set priority to 3\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_PLUS:
      {
        // Precidency Level: 4
        operator_tokens[give_priority_index].priority = 4;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_PLUS operator, set priority to 4\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_MINUS:
      {
        // Precidency Level: 4
        operator_tokens[give_priority_index].priority = 4;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_MINUS operator, set priority to 4\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_MULTIPLY:
      {
        // Precidency Level: 5
        operator_tokens[give_priority_index].priority = 5;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_MULTIPLY operator, set priority to 5\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_DIVIDE:
      {
        // Precidency Level: 5
        operator_tokens[give_priority_index].priority = 5;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_DIVIDE operator, set priority to 5\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
      case TK_NOT:
      {
        // Precidency Level: 6
        operator_tokens[give_priority_index].priority = 6;
        if(expr_print_debug)
        {
          printf("[EXPR DEBUG: void give_priority()] found a TK_NOT operator, set priority to 6\n");
          printf("[EXPR DEBUG: void give_priority()] give_priority_index = %d\n", give_priority_index);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].position = %d\n", operator_tokens[give_priority_index].position);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].priority = %d\n", operator_tokens[give_priority_index].priority);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].regex = \"%s\"\n", operator_tokens[give_priority_index].regex);
          printf("[EXPR DEBUG: void give_priority()] operator_tokens[give_priority_index].token_type = %d\n", operator_tokens[give_priority_index].token_type);
        }
        break;
        // TODO
      }
    }
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: void give_priority()] nr_operator_token = %d\n", nr_operator_token);
  }
  for(int operator_token_print_index = 0; operator_token_print_index < nr_operator_token; operator_token_print_index = operator_token_print_index + 1)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: void give_priority()] Operator Token Number: %4d, Position: %4d, Token Type: %4d, Token String: \"%s\", Priority: %4d\n", operator_token_print_index, operator_tokens[operator_token_print_index].position, operator_tokens[operator_token_print_index].token_type, operator_tokens[operator_token_print_index].regex, operator_tokens[operator_token_print_index].priority);
    }
  }
  return;
}

void give_priority_no_parentheses()
{
  // In function give_priority() we just give pripority ignoring the parentheses, now we need to add them back
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: void give_priority_no_parentheses()] CKPT #01: Enter function\n");
  }
  int local_highest_priority = 0;
  for(int current_scan_local_highest_priority_index = 1; current_scan_local_highest_priority_index < nr_operator_token - 1; current_scan_local_highest_priority_index = current_scan_local_highest_priority_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: void give_priority_no_parentheses()] CKPT #02: Enter scan local highest priority loop\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: void give_priority_no_parentheses()] enter loop, current_scan_local_highest_priority_index = %d\n", current_scan_local_highest_priority_index);
      printf("[EXPR DEBUG: void give_priority_no_parentheses()] enter loop, current local_highest_priority = %d\n", local_highest_priority);
    }
    if(operator_tokens[current_scan_local_highest_priority_index].priority > local_highest_priority)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] at index %4d, find priority %4d, higher than local_highest_priority %4d\n", current_scan_local_highest_priority_index, operator_tokens[current_scan_local_highest_priority_index].priority , local_highest_priority);
      }
      local_highest_priority = operator_tokens[current_scan_local_highest_priority_index].priority;
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] set local_highest_priority to %4d\n", local_highest_priority);
      }
    }
  }
  if(local_highest_priority < 0)
  {
    // Invalid
    if(expr_print_assertpoint)
    {
      printf("[EXPR ASSERTPOINT: void give_priority_no_parentheses()] ASPT #01: local_highest_priority < 0\n");
    }
    assert(0);
  }
  if(!check_parentheses_valid())
  {
    // Invalid
    if(expr_print_assertpoint)
    {
      printf("[EXPR ASSERTPOINT: void give_priority_no_parentheses()] ASPT #02: !check_parentheses_valid()\n");
    }
    assert(0);
  }
  int give_priority_no_parentheses_parentheses_level = 0;
  for(int give_priority_no_parentheses_increase_priority_index = 0; give_priority_no_parentheses_increase_priority_index < nr_operator_token; give_priority_no_parentheses_increase_priority_index = give_priority_no_parentheses_increase_priority_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: void give_priority_no_parentheses()] CKPT #03: Enter increase priority loop\n");
    }
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type == TK_LEFT_PARENTHESES)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Find a TK_LEFT_PARENTHESES at index %d\n", give_priority_no_parentheses_increase_priority_index);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Previous give_priority_no_parentheses_parentheses_level = %d, Current give_priority_no_parentheses_parentheses_level = %d\n", give_priority_no_parentheses_parentheses_level, give_priority_no_parentheses_parentheses_level + 1);
      }
      give_priority_no_parentheses_parentheses_level = give_priority_no_parentheses_parentheses_level + 1;
    }
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type == TK_RIGHT_PARENTHESES)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Find a TK_RIGHT_PARENTHESES at index %d\n", give_priority_no_parentheses_increase_priority_index);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Previous give_priority_no_parentheses_parentheses_level = %d, Current give_priority_no_parentheses_parentheses_level = %d\n", give_priority_no_parentheses_parentheses_level, give_priority_no_parentheses_parentheses_level - 1);
      }
      give_priority_no_parentheses_parentheses_level = give_priority_no_parentheses_parentheses_level - 1;
    }
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type != TK_LEFT_PARENTHESES && operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type != TK_RIGHT_PARENTHESES)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Find a NON_PARENTHESES_TOKEN at index %d\n", give_priority_no_parentheses_increase_priority_index);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] Original priority: %d, new priority: %d\n", operator_tokens[give_priority_no_parentheses_increase_priority_index].priority, operator_tokens[give_priority_no_parentheses_increase_priority_index].priority + give_priority_no_parentheses_parentheses_level * local_highest_priority);
      }
      operator_tokens[give_priority_no_parentheses_increase_priority_index].priority = operator_tokens[give_priority_no_parentheses_increase_priority_index].priority + give_priority_no_parentheses_parentheses_level * local_highest_priority;
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: void give_priority_no_parentheses()] CKPT #04: Copy information about non_parentheses tokens to operator_tokens_no_parentheses[32]\n");
      }
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] operator_tokens_no_parentheses[%d].position = %d\n", nr_operator_tokens_no_parentheses, operator_tokens[give_priority_no_parentheses_increase_priority_index].position);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] operator_tokens_no_parentheses[%d].priority_level = %d\n", nr_operator_tokens_no_parentheses, operator_tokens[give_priority_no_parentheses_increase_priority_index].priority);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] operator_tokens_no_parentheses[%d].regex = \"%s\"\n", nr_operator_tokens_no_parentheses, operator_tokens[give_priority_no_parentheses_increase_priority_index].regex);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] operator_tokens_no_parentheses[%d].token_type = %d\n", nr_operator_tokens_no_parentheses, operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type);
        printf("[EXPR DEBUG: void give_priority_no_parentheses()] nr_operator_tokens_no_parentheses = %d\n", nr_operator_tokens_no_parentheses + 1);
      }
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].position = operator_tokens[give_priority_no_parentheses_increase_priority_index].position;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].priority_level = operator_tokens[give_priority_no_parentheses_increase_priority_index].priority;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].regex = operator_tokens[give_priority_no_parentheses_increase_priority_index].regex;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].token_type = operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type;
      nr_operator_tokens_no_parentheses = nr_operator_tokens_no_parentheses + 1;
    }
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: void give_priority_no_parentheses()] nr_operator_token = %d\n", nr_operator_token);
    for(int print_operator_token_index = 0; print_operator_token_index < nr_operator_token; print_operator_token_index = print_operator_token_index + 1)
    {
      printf("[EXPR DEBUG: void give_priority_no_parentheses()] Token Number: %2d, Position: %2d, Priority: %2d, Token String: \"%s\", Token Type: %d\n", print_operator_token_index, operator_tokens[print_operator_token_index].position, operator_tokens[print_operator_token_index].priority, operator_tokens[print_operator_token_index].regex, operator_tokens[print_operator_token_index].token_type);
    }
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: void give_priority_no_parentheses()] nr_operator_tokens_no_parentheses = %d\n", nr_operator_tokens_no_parentheses);
    for(int print_operator_token_no_parentheses_index = 0; print_operator_token_no_parentheses_index < nr_operator_tokens_no_parentheses; print_operator_token_no_parentheses_index = print_operator_token_no_parentheses_index + 1)
    {
      printf("[EXPR DEBUG: void give_priority_no_parentheses()] Token Number: %2d, Position: %2d, Priority: %2d, Token String: \"%s\", Token Type: %d\n", print_operator_token_no_parentheses_index, operator_tokens_no_parentheses[print_operator_token_no_parentheses_index].position, operator_tokens_no_parentheses[print_operator_token_no_parentheses_index].priority_level, operator_tokens_no_parentheses[print_operator_token_no_parentheses_index].regex, operator_tokens_no_parentheses[print_operator_token_no_parentheses_index].token_type);
    }
  }
  return;
}

int bool_to_int(bool bool_value)
{
  // We received a bool value, convert it to 0 or 1
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int bool_to_int(bool bool_value)] CKPT #01: Enter function\n");
  }
  if(bool_value)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: int bool_to_int(bool bool_value)] Get bool_value = true, return 1\n");
    }
    return 1;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int bool_to_int(bool bool_value)] Get bool_value = false, return 0\n");
  }
  return 0;
}

bool check_left_token_is_number_or_bool(int check_index)
{
  // TODO
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_left_token_is_number_or_bool(int check_index)] CKPT #01: Enter function\n");
  }
  if(tokens[check_index - 1].type == TK_BINNUMBER || tokens[check_index - 1].type == TK_OCTNUMBER || tokens[check_index - 1].type == TK_NUMBER || tokens[check_index - 1].type == TK_HEXNUMBER)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_left_token_is_number_or_bool(int check_index)] Token at %d (left) is one of the NUMBER type\n", check_index - 1);
    }
    return true;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: bool check_left_token_is_number_or_bool(int check_index)] Token at %d (left) is NOT one of the NUMBER type\n", check_index - 1);
  }
  return false;
}

bool check_right_token_is_number_or_bool(int check_index)
{
  // TODO
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_right_token_is_number_or_bool(int check_index)] CKPT #01: Enter function\n");
  }
  if(tokens[check_index + 1].type == TK_BINNUMBER || tokens[check_index + 1].type == TK_OCTNUMBER || tokens[check_index + 1].type == TK_NUMBER || tokens[check_index + 1].type == TK_HEXNUMBER)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_right_token_is_number_or_bool(int check_index)] Token at %d (right) is one of the NUMBER type\n", check_index - 1);
    }
    return true;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: bool check_right_token_is_number_or_bool(int check_index)] Token at %d (right) is NOT one of the NUMBER type\n", check_index - 1);
  }
  return false;
}

int process_add(int add_operator_index)
{
  // We recognized the add_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_add(int add_operator_index)] CKPT #01: Enter function\n");
  }
  int process_add_answer = 0;
  int left_token_index = add_operator_index - 1;
  int right_token_index = add_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] add_operator_index = %d\n", add_operator_index);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_add_answer = left_token_int_value + right_token_int_value;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_add(int add_operator_index)] process_add_answer = %d\n", process_add_answer);
  }
  return process_add_answer;
}

int process_minus(int minus_operator_index)
{
  // We recognized the minus_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_minus(int minus_operator_index)] CKPT #01: Enter function\n");
  }
  int process_minus_answer = 0;
  int left_token_index = minus_operator_index - 1;
  int right_token_index = minus_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] add_operator_index = %d\n", minus_operator_index);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_minus_answer = left_token_int_value - right_token_int_value;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_minus(int minus_operator_index)] process_minus_answer = %d\n", process_minus_answer);
  }
  return process_minus_answer;
}

int process_multiply(int multiply_operator_index)
{
  // We recognized the multiply_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_multiply(int multiply_operator_index)] CKPT #01: Enter function\n");
  }
  int process_multiply_answer = 0;
  int left_token_index = multiply_operator_index - 1;
  int right_token_index = multiply_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] add_operator_index = %d\n", multiply_operator_index);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_multiply_answer = left_token_int_value * right_token_int_value;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_multiply(int multiply_operator_index)] process_multiply_answer = %d\n", process_multiply_answer);
  }
  return process_multiply_answer;
}

int process_devide(int devide_operator_index)
{
  // We recognized the devide_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_devide(int devide_operator_index)] CKPT #01: Enter function\n");
  }
  int process_devide_answer = 0;
  int left_token_index = devide_operator_index - 1;
  int right_token_index = devide_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] add_operator_index = %d\n", devide_operator_index);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_devide_answer = left_token_int_value / right_token_int_value;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_devide(int devide_operator_index)] process_devide_answer = %d\n", process_devide_answer);
  }
  return process_devide_answer;
}

int process_equal(int equal_operator_index)
{
  // We recognized the equal_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_equal(int equal_operator_index)] CKPT #01: Enter function\n");
  }
  int process_equal_answer = 0;
  int left_token_index = equal_operator_index - 1;
  int right_token_index = equal_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] add_operator_index = %d\n", equal_operator_index);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(left_token_int_value == right_token_int_value)
  {
    process_equal_answer = 1;
  }
  else
  {
    process_equal_answer = 0;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_equal(int equal_operator_index)] process_equal_answer = %d\n", process_equal_answer);
  }
  return process_equal_answer;
}

int process_not_equal(int not_equal_operator_index)
{
  // We recognized the not_equal_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_not_equal(int not_equal_operator_index)] CKPT #01: Enter function\n");
  }
  int process_not_equal_answer = 0;
  int left_token_index = not_equal_operator_index - 1;
  int right_token_index = not_equal_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] add_operator_index = %d\n", not_equal_operator_index);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(left_token_int_value != right_token_int_value)
  {
    process_not_equal_answer = 1;
  }
  else
  {
    process_not_equal_answer = 0;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_not_equal(int not_equal_operator_index)] process_not_equal_answer = %d\n", process_not_equal_answer);
  }
  return process_not_equal_answer;
}

int process_and(int and_operator_index)
{
  // We recognized the and_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_and(int and_operator_index)] CKPT #01: Enter function\n");
  }
  int process_and_answer = 0;
  int left_token_index = and_operator_index - 1;
  int right_token_index = and_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] add_operator_index = %d\n", and_operator_index);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(left_token_int_value == 1 && right_token_int_value == 1)
  {
    process_and_answer = 1;
  }
  else
  {
    process_and_answer = 0;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_and(int and_operator_index)] process_and_answer = %d\n", process_and_answer);
  }
  return process_and_answer;
}

int process_or(int or_operator_index)
{
  // We recognized the or_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_or(int or_operator_index)] CKPT #01: Enter function\n");
  }
  int process_or_answer = 0;
  int left_token_index = or_operator_index - 1;
  int right_token_index = or_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] add_operator_index = %d\n", or_operator_index);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] left_token_index = %d\n", left_token_index);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] left token type : %d\n", tokens[left_token_index].type);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] left token string : \"%s\"\n", tokens[left_token_index].str);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(left_token_int_value == 1 || right_token_int_value == 1)
  {
    process_or_answer = 1;
  }
  else
  {
    process_or_answer = 0;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] left_token_int_value = %d\n", left_token_int_value);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_or(int or_operator_index)] process_or_answer = %d\n", process_or_answer);
  }
  return process_or_answer;
}

int process_not(int not_operator_index)
{
  // We recognized the not_operator, evaluate it
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: int process_not(int not_operator_index)] CKPT #01: Enter function\n");
  }
  int process_not_answer = 0;
  int right_token_index = not_operator_index + 1;
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] add_operator_index = %d\n", not_operator_index);
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] right_token_index = %d\n", right_token_index);
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] right token type : %d\n", tokens[right_token_index].type);
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] right token string : \"%s\"\n", tokens[right_token_index].str);
  }
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(right_token_int_value == 1)
  {
    process_not_answer = 0;
  }
  else
  {
    process_not_answer = 1;
  }
  if(expr_print_debug)
  {
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] right_token_int_value = %d\n", right_token_int_value);
    printf("[EXPR DEBUG: int process_not(int not_operator_index)] process_or_answer = %d\n", process_not_answer);
  }
  return process_not_answer;
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

bool check_parentheses_valid()
{
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses_valid()] CKPT #01: Enter function\n");
    printf("[EXPR CHECKPOINT: bool check_parentheses_valid()] CKPT #02: Check parentheses number balance\n");
  }
  if(check_parentheses_balance())
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses_valid()] check_parentheses_balance() SUCCESS\n");
    }
  }
  else
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses_valid()] check_parentheses_balance() FAILED\n");
    }
    return false;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: bool check_parentheses_valid()] CKPT #03: Check inside balance\n");
  }
  int check_parentheses_valid_left_parentheses_count = 0;
  int check_parentheses_valid_right_parentheses_count = 0;
  for(int check_inside_parentheses_valid_index = 0; check_inside_parentheses_valid_index < nr_token; check_inside_parentheses_valid_index = check_inside_parentheses_valid_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: bool check_parentheses_valid()] CKPT #04: In for loop for check inside balance\n");
    }
    if(tokens[check_inside_parentheses_valid_index].type == TK_LEFT_PARENTHESES)
    {
      check_parentheses_valid_left_parentheses_count = check_parentheses_valid_left_parentheses_count + 1;
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: bool check_parentheses_valid()] found a TK_RIGHT_PARENTHESES at index %2d, check_parentheses_valid_right_parentheses_count = %2d\n", check_inside_parentheses_valid_index, check_parentheses_valid_right_parentheses_count);
      }
    }
    if(tokens[check_inside_parentheses_valid_index].type == TK_RIGHT_PARENTHESES)
    {
      check_parentheses_valid_right_parentheses_count = check_parentheses_valid_right_parentheses_count + 1;
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: bool check_parentheses_valid()] found a TK_LEFT_PARENTHESES at index %2d, check_parentheses_valid_left_parentheses_count = %2d\n", check_inside_parentheses_valid_index, check_parentheses_valid_left_parentheses_count);
      }
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: bool check_parentheses_valid()] check_parentheses_valid_left_parentheses_count - check_parentheses_valid_right_parentheses_count = %d\n", check_parentheses_valid_left_parentheses_count - check_parentheses_valid_right_parentheses_count);
    }
    if(check_parentheses_valid_left_parentheses_count - check_parentheses_valid_right_parentheses_count < 0)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: bool check_parentheses_valid()] check inside balance FAILED\n");
      }
      return false;
    }
    else
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: bool check_parentheses_valid()] check inside balance SUCCESS\n");
      }
      return true;
    }
  }
  return false;
}

void process_operator_token()
{
  // Test Token: p 11 + 2 * 3 - (4 + 1) * 10
  // We should do more things here 20230303
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: void process_operator_token()] CKPT #01: Enter function\n");
  }
  int current_index_of_operator_tokens = 0;
  nr_operator_token = 0;
  for(int current_scanning_index = 0; current_scanning_index < nr_token; current_scanning_index = current_scanning_index + 1)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: void process_operator_token()] CKPT #02: In scanning tokens loop\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: void process_operator_token()] current_scanning_index = %d\n", current_scanning_index);
      printf("[EXPR DEBUG: void process_operator_token()] current_index_of_operator_tokens = %d\n", current_index_of_operator_tokens);
      printf("[EXPR DEBUG: void process_operator_token()] tokens[%d].type = %d\n", current_scanning_index, tokens[current_scanning_index].type);
      printf("[EXPR DEBUG: void process_operator_token()] tokens[%d].str = \"%s\"\n", current_scanning_index, tokens[current_scanning_index].str);
    }
    if(tokens[current_scanning_index].type != TK_BINNUMBER && tokens[current_scanning_index].type != TK_OCTNUMBER && tokens[current_scanning_index].type != TK_NUMBER && tokens[current_scanning_index].type != TK_HEXNUMBER)
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void process_operator_token()] find an operator token at nr_token index %d\n", current_scanning_index);
      }
      operator_tokens[current_index_of_operator_tokens].position = current_scanning_index;
      operator_tokens[current_index_of_operator_tokens].token_type = tokens[current_scanning_index].type;
      operator_tokens[current_index_of_operator_tokens].regex = tokens[current_scanning_index].str;
      operator_tokens[current_index_of_operator_tokens].priority = 0; // We set all Operator tokens to 0 first, and then we will change them in another function
      current_index_of_operator_tokens = current_index_of_operator_tokens + 1;
      nr_operator_token = nr_operator_token + 1;
      // Now the token is a operator token, implement codes to register them to operator_tokens
    }
    else
    {
      if(expr_print_debug)
      {
        printf("[EXPR DEBUG: void process_operator_token()] not an operator token at nr_token index %d, ignore in this scope\n", current_scanning_index);
      }
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: void process_operator_token()] nr_operator_token = %d\n", nr_operator_token);
    }
    // TODO
  }
  // To make debug easier, we print all operator tokens if expr_print_debug is true
  for(int operator_token_print_index = 0; operator_token_print_index < nr_operator_token; operator_token_print_index = operator_token_print_index + 1)
  {
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: void process_operator_token()] Operator Token Number: %4d, Position: %4d, Token Type: %4d, Token String: \"%s\", Priority: %4d\n", operator_token_print_index, operator_tokens[operator_token_print_index].position, operator_tokens[operator_token_print_index].token_type, operator_tokens[operator_token_print_index].regex, operator_tokens[operator_token_print_index].priority);
    }
  }
  return;
}

int find_dominant_operator(int left, int right, bool *expr_valid_call)
{
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: find_dominant_operator(int left, int right, bool *expr_valid_call)] CKPT #01: Enter function int find_dominant_operator(int left, int right, bool *expr_valid_call)\n");
  }
  // TODO
  return 0;
}

u_int64_t eval(int p, int q) // p = left index, q = right index
{
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #01: Enter function u_int64_t eval(int p, int q)\n");
  }
  if(valid_call == false)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #02: valid_call == false\n");
    }
    printf("Invalid Call\n");
    // OK
    return 0;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #03: Exit the \"if\" evaluation\n");
  }
  if(q > p)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #04: q > p\n");
    }
    valid_call = false;
    printf("Invalid eval() call\n");
    // OK
    return 0;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #05: Exit the \"if\" evaluation\n");
  }
  if(p == q)
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #06: p == q\n");
    }
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: u_int64_t eval(int p, int q)] eval(p,q) call with p=q, will just return the number\n");
    }
    u_int64_t number = 0;
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #07: created u_int64_t number with initial value = 0\n");
    }
    if(tokens[p].type == TK_NUMBER)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #08: tokens[%d].type == TK_NUMBER\n", p);
      }
      sscanf(tokens[p].str, "%ld", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #09\n");
    }
    if(tokens[p].type == TK_HEXNUMBER)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #08: tokens[%d].type == TK_HEXNUMBER\n", p);
      }
      sscanf(tokens[p].str, "%lx", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #11\n");
    }
    if(tokens[p].type == TK_OCTNUMBER)
    {
      if(expr_print_checkpoint)
      {
        printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #08: tokens[%d].type == TK_OCTNUMBER\n", p);
      }
      sscanf(tokens[p].str, "%lo", &number);
      return number;
    }
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #13\n");
    }
    // We should add more codes here.
    return number;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #14: Exit if evaluation of \"if(p == q)\"\n");
  }
  u_int64_t answer = 0;
  if(check_parentheses(p, q) == true)
  {
    // OK
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #15: check_parentheses(p, q) == true\n");
    }
    return eval(p + 1, q - 1);
  }
  else
  {
    if(expr_print_assertpoint)
    {
      printf("[EXPR ASSERTPOINT: u_int64_t eval(int p, int q)] ASPT #01: expr_print_checkpoint == false\n");
    }
    // We should do more things here.
    assert(0);
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: u_int64_t eval(int p, int q)] CKPT #16: End of function\n");
  }
  return answer;
}

word_t expr(char *e, bool *success) {
  expr_init();
  //eval();
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #01: Enter function word_t expr(char *e, bool *success)\n");
  }
  
  if(!check_parentheses_balance())
  {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #02: check_parentheses_balance() = false\n");
    }
    *success = false;
    valid_call = false;
    if(expr_print_debug)
    {
      printf("[EXPR DEBUG: word_t expr(char *e, bool *success)] expr() exited because check_parentheses_balance() returned FALSE\n");
    }
    return 0;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #03\n");
  }

  if (!make_token(e)) {
    if(expr_print_checkpoint)
    {
      printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #04\n");
    }
    *success = false;
    valid_call = false;
    return 0;
  }
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #05\n");
  }
  valid_call = true; // Prob: if this line is not annotated, it will cause Segmentation fault

  *success = true;
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #06\n");
  }
  u_int64_t expr_ans = eval(0, nr_token - 1);
  if(expr_print_checkpoint)
  {
    printf("[EXPR CHECKPOINT: word_t expr(char *e, bool *success)] CKPT #07\n");
  }
  process_operator_token();
  give_priority();
  give_priority_no_parentheses();

  printf("Evaluate Success, Ans (Hex): %lx, Ans (Dec): %ld, Ans (Oct): %lo\n", expr_ans, expr_ans, expr_ans);
  return 0;
}