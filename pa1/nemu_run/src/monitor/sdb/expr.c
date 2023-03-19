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
#include <stdlib.h>

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
 TK_NEGATIVESIGN = 251,
 TK_NOT = 250,
 TK_POINTER = 249,
 TK_NUMBER = 248,
 TK_HEXNUMBER = 247,
 TK_REGISTER = 246,
 TK_MARK = 245,
 TK_EXOR = 244,
 TK_POSITIVESIGN = 243,
 TK_PLUS = 242,
 TK_MINUS = 241,
 TK_MULTIPLY = 240,
 TK_DIVIDE = 239,
 TK_LEFT_PARENTHESES = 238,
 TK_RIGHT_PARENTHESES = 237,
 TK_MOD = 236, 
};

bool check_parentheses_balance(); // Used in expr()
bool check_parentheses_valid(); // Used in give_priority_no_parentheses()
bool check_left_token_is_number_or_bool(int check_index);
bool check_right_token_is_number_or_bool(int check_index);
void process_operator_token();
void give_priority();
void give_priority_no_parentheses();
void give_sub_priority();
int bool_to_int(bool bool_value);
bool valid_call;

int process_add(int add_operator_index);
int process_minus(int minus_operator_index);
int process_multiply(int multiply_operator_index);
int process_devide(int devide_operator_index);
int process_equal(int equal_operator_index);
int process_not_equal(int not_equal_operator_index);
int process_and(int and_operator_index);
int process_or(int or_operator_index);
int process_exor(int exor_operator_index);
int process_not(int not_operator_index);
int process_mod(int mod_operator_index);
int process_negative_sign(int negative_sign_operator_index);
int process_positive_sign(int positive_sign_operator_index);
int process_pointer_dereference(int pointer_dereference_index);

void expr_init();
void init_tokens();
void init_operator_tokens();
void init_operator_tokens_no_parentheses();
void init_execute_history();

char* calculate_one_round(bool success_calculate_one_round_call);

char* expr_main_loop(char* token_input, bool *success_main_loop, bool *finished);

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
  int sub_priority_level;
} operator_tokens_no_parentheses[32];

struct ExecuteHistory
{
  const char *result_token_history;
  bool success_history;
  bool finished_history;
  int that_round_operator_token_no_narentheses_index;
  int that_round_token_index;
} execution_histories[32];

int nr_operator_tokens_no_parentheses = 0;
int nr_operator_token = 0;
int nr_execution_histories = 0;

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE}, // Spaces
  {"0x[0-9,a-f]+", TK_HEXNUMBER}, // Hex Numbers
  {"[0-9]+", TK_NUMBER}, // Dec Numbers
  {"\\$[a-z0-9]{1,31}", TK_REGISTER}, // Register Names
  {"\\(", TK_LEFT_PARENTHESES}, // Left Parenthesis IS_OPERATOR_TOKEN
  {"\\)", TK_RIGHT_PARENTHESES}, // Right Parenthesis IS_OPERATOR_TOKEN
  {"\\*", TK_MULTIPLY}, // Multiply IS_OPERATOR_TOKEN
  {"\\/", TK_DIVIDE}, // Devide IS_OPERATOR_TOKEN
  {"\\+", TK_PLUS}, // Plus IS_OPERATOR_TOKEN
  {"\\-", TK_MINUS}, // Minus IS_OPERATOR_TOKEN
  {"\\//", TK_MOD}, // Mod IS_OPERATOR_TOKEN
  {"==", TK_EQ}, // Equal IS_OPERATOR_TOKEN
  {"!=", TK_NEQ}, // Not Equal IS_OPERATOR_TOKEN
  {"&&", TK_AND}, // And IS_OPERATOR_TOKEN
  {"\\|\\|", TK_OR}, // Or IS_OPERATOR_TOKEN
  {"!", TK_NOT}, // Not IS_OPERATOR_TOKEN
  {"\\^", TK_EXOR}, // Exor IS_OPERATOR_TOKEN
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

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
  return;
}

void init_tokens()
{
  nr_token = 0;
  for(int init_tokens_index = 0; init_tokens_index < 32; init_tokens_index = init_tokens_index + 1)
  {
    memset(tokens[init_tokens_index].str,0,sizeof(tokens[init_tokens_index].str));
    tokens[init_tokens_index].type = -1;
  }
  return;
}

void init_operator_tokens()
{
  nr_operator_token = 0;
  for(int init_operator_tokens_index = 0; init_operator_tokens_index < 32; init_operator_tokens_index = init_operator_tokens_index + 1)
  {
    operator_tokens[init_operator_tokens_index].regex = NULL;
    operator_tokens[init_operator_tokens_index].position = -1;
    operator_tokens[init_operator_tokens_index].priority = -1;
    operator_tokens[init_operator_tokens_index].token_type = -1;
  }
  return;
}

void init_operator_tokens_no_parentheses()
{
  nr_operator_tokens_no_parentheses = 0;
  for(int init_operator_tokens_no_parentheses_index = 0; init_operator_tokens_no_parentheses_index < 32; init_operator_tokens_no_parentheses_index = init_operator_tokens_no_parentheses_index + 1)
  {
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].regex = NULL;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].position = -1;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].priority_level = -1;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].token_type = -1;
    operator_tokens_no_parentheses[init_operator_tokens_no_parentheses_index].sub_priority_level = -1;
  }
  return;
}

void init_execute_history()
{
  nr_execution_histories = 0;
  for(int init_execute_history_index = 0; init_execute_history_index < 32; init_execute_history_index = init_execute_history_index + 1)
  {
    execution_histories[init_execute_history_index].result_token_history = NULL;
    execution_histories[init_execute_history_index].success_history = false;
    execution_histories[init_execute_history_index].finished_history = false;
    execution_histories[init_execute_history_index].that_round_operator_token_no_narentheses_index = -1;
    execution_histories[init_execute_history_index].that_round_token_index = -1;
  }
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        switch (rules[i].token_type) 
        {
          default:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NOTYPE:
          {
            // Case No.1
            break;
          }
          case TK_EQ:
          {
            // Case No.2
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_EQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NEQ:
          {
            // Case No.3
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NEQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NOT:
          {
            // Case No.4
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NOT;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_AND:
          {
            // Case No.5
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_OR:
          {
            // Case No.6
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_OR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_POINTER:
          {
            // Case No.7
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_POINTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NUMBER:
          {
            // Case No.10
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_HEXNUMBER:
          {
            // Case No.11
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_HEXNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            // We convert TK_HEXNUMBER to TK_NUMBER for easy of calculation
            int convert_to_int;
            sscanf(tokens[nr_token].str, "%x", &convert_to_int);
            sprintf(tokens[nr_token].str, "%d", convert_to_int);
            tokens[nr_token].type = TK_NUMBER;
            nr_token = nr_token + 1;
            break;
          }
          case TK_REGISTER: // !!! Special Case
          {
            // Case No.12
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_REGISTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_MARK:
          {
            // Case No.13
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MARK;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_LEFT_PARENTHESES:
          {
            // Case No.14
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_LEFT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_RIGHT_PARENTHESES:
          {
            // Case No.15
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_RIGHT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_MULTIPLY:
          {
            // Case No.16
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MULTIPLY;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if((tokens[nr_token - 1].type != TK_NUMBER && tokens[nr_token - 1].type != TK_HEXNUMBER) || nr_token == 0)
            {
              tokens[nr_token].type = TK_POINTER;
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_DIVIDE:
          {
            // Case No.17
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_DIVIDE;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_PLUS:
          {
            // Case No.18
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_PLUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(tokens[nr_token - 1].type != TK_NUMBER && tokens[nr_token - 1].type != TK_HEXNUMBER)
            {
              tokens[nr_token].type = TK_POSITIVESIGN;
            }
            nr_token = nr_token + 1;
            break;
          }
          case TK_MINUS:
          {
            // Case No.19
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MINUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            if(tokens[nr_token - 1].type != TK_NUMBER && tokens[nr_token - 1].type != TK_HEXNUMBER)
            {
              tokens[nr_token].type = TK_NEGATIVESIGN;
            }
            nr_token = nr_token + 1;
            break;
          }
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      Log("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  return true;
}

void give_priority()
{
  // Give priority ignoring the parentheses
  // Previous (1st version) Precidency Level: (No Parentheses Considered)
  // 1) Or 2) AND 3) EQ/NEQ 4) PLUS/MINUS 5) MULTIPLY/DEVIDE 6) NOT
  // Current (2nd version) Precidency Level: (No Parentheses Considered)
  // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
  for(int give_priority_index = 0; give_priority_index < nr_operator_token; give_priority_index = give_priority_index + 1)
  {
    switch(operator_tokens[give_priority_index].token_type)
    {
      case TK_OR:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 1
        operator_tokens[give_priority_index].priority = 1;
        break;
      }
      case TK_EXOR:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 2
        operator_tokens[give_priority_index].priority = 2;
        break;
      }
      case TK_AND:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 3
        operator_tokens[give_priority_index].priority = 3;
        break;
      }
      case TK_EQ:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 4
        operator_tokens[give_priority_index].priority = 4;
        break;
      }
      case TK_NEQ:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 4
        operator_tokens[give_priority_index].priority = 4;
        break;
      }
      case TK_PLUS:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 5
        operator_tokens[give_priority_index].priority = 5;
        break;
      }
      case TK_MINUS:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 5
        operator_tokens[give_priority_index].priority = 5;
        break;
      }
      case TK_MULTIPLY:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 6
        operator_tokens[give_priority_index].priority = 6;
        break;
      }
      case TK_DIVIDE:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 6
        operator_tokens[give_priority_index].priority = 6;
        break;
      }
      case TK_MOD:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 6
        operator_tokens[give_priority_index].priority = 6;
        break;
      }
      case TK_NOT:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 7
        operator_tokens[give_priority_index].priority = 7;
        break;
      }
      case TK_POSITIVESIGN:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 7
        operator_tokens[give_priority_index].priority = 7;
        break;
      }
      case TK_NEGATIVESIGN:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 7
        operator_tokens[give_priority_index].priority = 7;
        break;
      }
      case TK_POINTER:
      {
        // Current (2nd version) Precidency Level: (No Parentheses Considered)
        // 1) OR 2) EXOR 3) AND 4) EQ/NEQ 5) PLUS/MINUS 6) MULTIPLY/DEVIDE/MOD 7) NOT/POSITIVESIGN/NEGATIVESIGN 8) POINTER
        // Precidency Level: 7
        operator_tokens[give_priority_index].priority = 8;
        break;
      }
    }
  }
  return;
}

void give_priority_no_parentheses()
{
  // In function give_priority() we just give pripority ignoring the parentheses, now we need to add them back
  int local_highest_priority = 0;
  for(int current_scan_local_highest_priority_index = 1; current_scan_local_highest_priority_index < nr_operator_token - 1; current_scan_local_highest_priority_index = current_scan_local_highest_priority_index + 1)
  {
    if(operator_tokens[current_scan_local_highest_priority_index].priority > local_highest_priority)
    {
      local_highest_priority = operator_tokens[current_scan_local_highest_priority_index].priority;
    }
  }
  if(local_highest_priority < 0)
  {
    // Invalid
    assert(0);
  }
  if(!check_parentheses_valid())
  {
    // Invalid
    assert(0);
  }
  int give_priority_no_parentheses_parentheses_level = 0;
  for(int give_priority_no_parentheses_increase_priority_index = 0; give_priority_no_parentheses_increase_priority_index < nr_operator_token; give_priority_no_parentheses_increase_priority_index = give_priority_no_parentheses_increase_priority_index + 1)
  {
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type == TK_LEFT_PARENTHESES)
    {
      give_priority_no_parentheses_parentheses_level = give_priority_no_parentheses_parentheses_level + 1;
    }
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type == TK_RIGHT_PARENTHESES)
    {
      give_priority_no_parentheses_parentheses_level = give_priority_no_parentheses_parentheses_level - 1;
    }
    if(operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type != TK_LEFT_PARENTHESES && operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type != TK_RIGHT_PARENTHESES)
    {
      operator_tokens[give_priority_no_parentheses_increase_priority_index].priority = operator_tokens[give_priority_no_parentheses_increase_priority_index].priority + give_priority_no_parentheses_parentheses_level * local_highest_priority;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].position = operator_tokens[give_priority_no_parentheses_increase_priority_index].position;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].priority_level = operator_tokens[give_priority_no_parentheses_increase_priority_index].priority;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].regex = operator_tokens[give_priority_no_parentheses_increase_priority_index].regex;
      operator_tokens_no_parentheses[nr_operator_tokens_no_parentheses].token_type = operator_tokens[give_priority_no_parentheses_increase_priority_index].token_type;
      nr_operator_tokens_no_parentheses = nr_operator_tokens_no_parentheses + 1;
    }
  }
  return;
}

void give_sub_priority()
{
  // Test Token for this function: p 1 + (2 + (3 + 4) + (5 + 6 + (7 * 8 * 9) + 10) * 11 + 12)
  // Now we give sub calculation priority by considering the position of operators
  int global_highest_priority = -1;
  for(int find_global_highest_priority_index = 0; find_global_highest_priority_index < nr_operator_tokens_no_parentheses; find_global_highest_priority_index = find_global_highest_priority_index + 1)
  {
    if(operator_tokens_no_parentheses[find_global_highest_priority_index].priority_level > global_highest_priority)
    {
      global_highest_priority = operator_tokens_no_parentheses[find_global_highest_priority_index].priority_level;
    }
  }
  for(int current_processing_global_priority = global_highest_priority; current_processing_global_priority > 0; current_processing_global_priority = current_processing_global_priority - 1)
  {
    int current_processing_local_priority = 0;
    for(int current_scanning_operator_tokens_no_parentheses_index = 0; current_scanning_operator_tokens_no_parentheses_index < nr_operator_tokens_no_parentheses; current_scanning_operator_tokens_no_parentheses_index = current_scanning_operator_tokens_no_parentheses_index + 1)
    {
      // First, we need to find out how many operators have the same global priority, by scanning each operator_token_no_parentheses and we count them
      if(operator_tokens_no_parentheses[current_scanning_operator_tokens_no_parentheses_index].priority_level == current_processing_global_priority)
      {
        current_processing_local_priority = current_processing_local_priority + 1;
      }
    }
    for(int current_scanning_operator_tokens_no_parentheses_index = 0; current_scanning_operator_tokens_no_parentheses_index < nr_operator_tokens_no_parentheses; current_scanning_operator_tokens_no_parentheses_index = current_scanning_operator_tokens_no_parentheses_index + 1)
    {
      // Second, we give the highest local priority to the first operator token with the same global priority, then we minus 1 to current_processing_local_priority
      if(operator_tokens_no_parentheses[current_scanning_operator_tokens_no_parentheses_index].priority_level == current_processing_global_priority)
      {
        operator_tokens_no_parentheses[current_scanning_operator_tokens_no_parentheses_index].sub_priority_level = current_processing_local_priority;
        current_processing_local_priority = current_processing_local_priority - 1;
      }
    }
  }
  return;
}

int bool_to_int(bool bool_value)
{
  // We received a bool value, convert it to 0 or 1
  if(bool_value)
  {
    return 1;
  }
  return 0;
}

bool check_left_token_is_number_or_bool(int check_index)
{
  if(tokens[check_index - 1].type == TK_NUMBER || tokens[check_index - 1].type == TK_HEXNUMBER)
  {
    return true;
  }
  return false;
}

bool check_right_token_is_number_or_bool(int check_index)
{
  if(tokens[check_index + 1].type == TK_NUMBER || tokens[check_index + 1].type == TK_HEXNUMBER)
  {
    return true;
  }
  return false;
}

int process_add(int add_operator_index)
{
  // We recognized the add_operator, evaluate it
  int process_add_answer = 0;
  int left_token_index = add_operator_index - 1;
  int right_token_index = add_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_add_answer = left_token_int_value + right_token_int_value;
  return process_add_answer;
}

int process_minus(int minus_operator_index)
{
  // We recognized the minus_operator, evaluate it
  int process_minus_answer = 0;
  int left_token_index = minus_operator_index - 1;
  int right_token_index = minus_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_minus_answer = left_token_int_value - right_token_int_value;
  return process_minus_answer;
}

int process_multiply(int multiply_operator_index)
{
  // We recognized the multiply_operator, evaluate it
  int process_multiply_answer = 0;
  int left_token_index = multiply_operator_index - 1;
  int right_token_index = multiply_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_multiply_answer = left_token_int_value * right_token_int_value;
  return process_multiply_answer;
}

int process_devide(int devide_operator_index)
{
  // We recognized the devide_operator, evaluate it
  int process_devide_answer = 0;
  int left_token_index = devide_operator_index - 1;
  int right_token_index = devide_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_devide_answer = left_token_int_value / right_token_int_value;
  return process_devide_answer;
}

int process_mod(int mod_operator_index)
{
  // We recognized the mod_operator, evaluate it
  int process_mod_answer = 0;
  int left_token_index = mod_operator_index - 1;
  int right_token_index = mod_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  int integer_devide_answer = left_token_int_value / right_token_int_value;
  process_mod_answer = left_token_int_value - integer_devide_answer * right_token_int_value;
  return process_mod_answer;
}

int process_equal(int equal_operator_index)
{
  // We recognized the equal_operator, evaluate it
  int process_equal_answer = 0;
  int left_token_index = equal_operator_index - 1;
  int right_token_index = equal_operator_index + 1;
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
  return process_equal_answer;
}

int process_not_equal(int not_equal_operator_index)
{
  // We recognized the not_equal_operator, evaluate it
  int process_not_equal_answer = 0;
  int left_token_index = not_equal_operator_index - 1;
  int right_token_index = not_equal_operator_index + 1;
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
  return process_not_equal_answer;
}

int process_and(int and_operator_index)
{
  // We recognized the and_operator, evaluate it
  int process_and_answer = 0;
  int left_token_index = and_operator_index - 1;
  int right_token_index = and_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_and_answer = left_token_int_value & right_token_int_value;
  return process_and_answer;
}

int process_or(int or_operator_index)
{
  // We recognized the or_operator, evaluate it
  int process_or_answer = 0;
  int left_token_index = or_operator_index - 1;
  int right_token_index = or_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_or_answer = left_token_int_value | right_token_int_value;
  return process_or_answer;
}

int process_exor(int exor_operator_index)
{
  // We recognized the exor_operator, evaluate it
  int process_exor_answer = 0;
  int left_token_index = exor_operator_index - 1;
  int right_token_index = exor_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_exor_answer = left_token_int_value ^ right_token_int_value;
  return process_exor_answer;
}

int process_not(int not_operator_index)
{
  // We recognized the not_operator, evaluate it
  int process_not_answer = 0;
  int right_token_index = not_operator_index + 1;
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_not_answer = ~ right_token_int_value;
  return process_not_answer;
}

int process_positive_sign(int positive_sign_operator_index)
{
  // We recognized the positive_sign_operator, evaluate it
  int process_positive_sign_answer = 0;
  int right_token_index = positive_sign_operator_index + 1;
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_positive_sign_answer = 1 * right_token_int_value;
  return process_positive_sign_answer;
}

int process_negative_sign(int negative_sign_operator_index)
{
  // We recognized the negative_sign_operator, evaluate it
  int process_negative_sign_answer = 0;
  int right_token_index = negative_sign_operator_index + 1;
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_negative_sign_answer = -1 * right_token_int_value;
  return process_negative_sign_answer;
}

int process_pointer_dereference(int pointer_dereference_index)
{
  // We recognized the pointer_dereference_operator, evaluate it
  // Special Case, will change the code skeleton
  int process_pointer_dereference_answer = 0;
  int right_token_index = pointer_dereference_index + 1;
  bool pointer_dereference_success = false;
  process_pointer_dereference_answer = isa_reg_str2val(tokens[right_token_index].str + 1, &pointer_dereference_success);
  if(pointer_dereference_success)
  {
    return process_pointer_dereference_answer;
  }
  else
  {
    return 0;
  }
}

char* calculate_one_round(bool success_calculate_one_round_call)
{
  // First, find the highest priority and sub_priority, then get the index in tokens[32]
  int calculate_one_round_highest_priority = -1;
  int calculate_one_round_highest_sub_priority = -1;
  for (int calculate_one_round_highest_priority_scanning_index = 0; calculate_one_round_highest_priority_scanning_index < nr_operator_tokens_no_parentheses; calculate_one_round_highest_priority_scanning_index = calculate_one_round_highest_priority_scanning_index + 1)
  {
    if(operator_tokens_no_parentheses[calculate_one_round_highest_priority_scanning_index].priority_level > calculate_one_round_highest_priority)
    {
      calculate_one_round_highest_priority = operator_tokens_no_parentheses[calculate_one_round_highest_priority_scanning_index].priority_level;
    }
  }
  for (int calculate_one_round_highest_priority_scanning_index = 0; calculate_one_round_highest_priority_scanning_index < nr_operator_tokens_no_parentheses; calculate_one_round_highest_priority_scanning_index = calculate_one_round_highest_priority_scanning_index + 1)
  {
    if(operator_tokens_no_parentheses[calculate_one_round_highest_priority_scanning_index].priority_level == calculate_one_round_highest_priority)
    {
      if(operator_tokens_no_parentheses[calculate_one_round_highest_priority_scanning_index].sub_priority_level > calculate_one_round_highest_sub_priority)
      {
        calculate_one_round_highest_sub_priority = operator_tokens_no_parentheses[calculate_one_round_highest_priority_scanning_index].sub_priority_level;
      }
    }
  }
  int this_round_calculation_operator_token_index = -1;
  for(int scan_index = 0; scan_index < nr_operator_tokens_no_parentheses; scan_index = scan_index + 1)
  {
    if(operator_tokens_no_parentheses[scan_index].priority_level == calculate_one_round_highest_priority && operator_tokens_no_parentheses[scan_index].sub_priority_level == calculate_one_round_highest_sub_priority)
    {
      this_round_calculation_operator_token_index = scan_index;
    }
  }
  execution_histories[nr_execution_histories].that_round_operator_token_no_narentheses_index = this_round_calculation_operator_token_index;
  execution_histories[nr_execution_histories].that_round_token_index = operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position;
  // Scend, check the condition to make a success call, if not success, set success_calculate_one_round_call to false
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_DIVIDE && atoi(tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 1].str) == 0)
  {
    // Error: Divide by 0
    success_calculate_one_round_call = false;
    return NULL;
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type != TK_NOT && operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type != TK_POINTER && operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type != TK_NEGATIVESIGN && operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type != TK_POSITIVESIGN && tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position - 1].type != TK_HEXNUMBER && tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position - 1].type != TK_NUMBER)
  {
    // Error: Left is not a Dec or Hex number
    // This function will be implemented to only double side operator
    // Will ignore TK_NOT, TK_POINTER, TK_NEGATIVESIGN, TK_POSITIVESIGN
    success_calculate_one_round_call = false;
    return NULL;
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type != TK_POINTER && tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 1].type != TK_HEXNUMBER && tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 1].type != TK_NUMBER)
  {
    // Error: Right is not a Dec or Hex number
    // This function will be implemented to double side operator
    // Will ignore TK_POINTER
    success_calculate_one_round_call = false;
    return NULL;
  }
  // Third, implement specific calls to evaluate the result
  u_int64_t this_round_calculation_answer = 0;
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_PLUS)
  {
    this_round_calculation_answer = process_add(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_MINUS)
  {
    this_round_calculation_answer = process_minus(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_MULTIPLY)
  {
    this_round_calculation_answer = process_multiply(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_DIVIDE)
  {
    this_round_calculation_answer = process_devide(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_AND)
  {
    this_round_calculation_answer = process_and(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_OR)
  {
    this_round_calculation_answer = process_or(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_NOT)
  {
    this_round_calculation_answer = process_not(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_EXOR)
  {
    this_round_calculation_answer = process_exor(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_POINTER)
  {
    this_round_calculation_answer = process_pointer_dereference(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_NEGATIVESIGN)
  {
    this_round_calculation_answer = process_negative_sign(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  if(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].token_type == TK_POSITIVESIGN)
  {
    this_round_calculation_answer = process_positive_sign(operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position);
  }
  // Fourth, store the new result to a token, check if the token's left and right is a pair of parentheses, if so, remove it
  bool left_and_right_is_paired_parentheses = false;
  char* result_token = malloc(256);
  if(tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position - 2].type == TK_LEFT_PARENTHESES && tokens[operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 2].type == TK_RIGHT_PARENTHESES)
  {
    left_and_right_is_paired_parentheses = true;
  }
  for(int current_copying_tokens_index = 0; current_copying_tokens_index < nr_token; current_copying_tokens_index = current_copying_tokens_index + 1)
  {
    if(current_copying_tokens_index == operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position - 2 && left_and_right_is_paired_parentheses == true)
    {
      continue;
      // Do not copy
    }
    if(current_copying_tokens_index == operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position - 1)
    {
      continue;
      // Do not copy
    }
    if(current_copying_tokens_index == operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position)
    {
      sprintf(result_token + strlen(result_token), "%ld", this_round_calculation_answer);
      continue;
      // Do not copy
    }
    if(current_copying_tokens_index == operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 1)
    {
      continue;
      // Do not copy
    }
    if(current_copying_tokens_index == operator_tokens_no_parentheses[this_round_calculation_operator_token_index].position + 2 && left_and_right_is_paired_parentheses == true)
    {
      continue;
      // Do not copy
    }
    strcat(result_token, tokens[current_copying_tokens_index].str);
  }
  success_calculate_one_round_call = true;
  return result_token;
}

bool check_parentheses_balance()
{
  // This function is a more convenient version of check_parentheses(int left_index, int right_index)
  // With default left_index = 0 and right_index = nr_token - 1, and tolerence for Type I and Type II parentheses error
  // This can make it more efficient when the cmd_p command execute, for expr with different left parentheses count and right parentheses count, the cmd_p can quit immediately
  int check_parentheses_balance_left_count = 0;
  int check_parentheses_balance_right_count = 0;

  for(int current_check_index = 0; current_check_index < nr_token; current_check_index = current_check_index + 1)
  {
    if(tokens[current_check_index].type == TK_LEFT_PARENTHESES)
    {
      check_parentheses_balance_left_count = check_parentheses_balance_left_count + 1;
    }
    if(tokens[current_check_index].type == TK_RIGHT_PARENTHESES)
    {
      check_parentheses_balance_right_count = check_parentheses_balance_right_count + 1;
    }
  }
  if(check_parentheses_balance_left_count == check_parentheses_balance_right_count)
  {
    return true;
  }
  return false;
}

bool check_parentheses_valid()
{
  if(check_parentheses_balance())
  {
    // NOTHING
  }
  else
  {
    return false;
  }
  int check_parentheses_valid_left_parentheses_count = 0;
  int check_parentheses_valid_right_parentheses_count = 0;
  for(int check_inside_parentheses_valid_index = 0; check_inside_parentheses_valid_index < nr_token; check_inside_parentheses_valid_index = check_inside_parentheses_valid_index + 1)
  {
    if(tokens[check_inside_parentheses_valid_index].type == TK_LEFT_PARENTHESES)
    {
      check_parentheses_valid_left_parentheses_count = check_parentheses_valid_left_parentheses_count + 1;
    }
    if(tokens[check_inside_parentheses_valid_index].type == TK_RIGHT_PARENTHESES)
    {
      check_parentheses_valid_right_parentheses_count = check_parentheses_valid_right_parentheses_count + 1;
    }
    if(check_parentheses_valid_left_parentheses_count - check_parentheses_valid_right_parentheses_count < 0)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  return true;
}

void process_operator_token()
{
  // Test Token: p 11 + 2 * 3 - (4 + 1) * 10
  // We should do more things here 20230303
  int current_index_of_operator_tokens = 0;
  nr_operator_token = 0;
  for(int current_scanning_index = 0; current_scanning_index < nr_token; current_scanning_index = current_scanning_index + 1)
  {
    if(tokens[current_scanning_index].type != TK_NUMBER && tokens[current_scanning_index].type != TK_HEXNUMBER)
    {
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
      // NOTHING
    }
  }
  // To make debug easier, we print all operator tokens if expr_print_debug is true
  for(int operator_token_print_index = 0; operator_token_print_index < nr_operator_token; operator_token_print_index = operator_token_print_index + 1)
  {
    // NOTHING
  }
  return;
}

char* expr_main_loop(char* token_input, bool *success_main_loop, bool *finished)
{
  expr_init();
  if(!check_parentheses_valid())
  {
    // This function have both check inside valid and macro-valid
    *success_main_loop = false;
    *finished = false;
    return NULL;
  }
  if(!make_token(token_input))
  {
    *success_main_loop = false;
    *finished = false;
    return NULL;
  }
  if(nr_token == 1)
  {
    // The number of token is 1 means the calculation have finished, so just return result
    *success_main_loop = true;
    *finished = true;
    printf("Evaluate Success, Ans (Hex): %x, Ans (Dec): %d\n", atoi(tokens[0].str), atoi(tokens[0].str));
    return NULL;
  }
  if((nr_token == 2 && tokens[0].type == TK_NEGATIVESIGN) || (nr_token == 2 && tokens[0].type == TK_POSITIVESIGN))
  {
    // Treat as nr_token = 1 and finished token
    *success_main_loop = true;
    *finished = true;
    if(tokens[0].type == TK_NEGATIVESIGN)
    {
      printf("Evaluate Success, Ans (Hex): %x, Ans (Dec): %d, Ans (Oct): %o\n", -1 * atoi(tokens[1].str), -1 * atoi(tokens[1].str), -1 * atoi(tokens[1].str));
      return NULL;
    }
    if(tokens[0].type == TK_POSITIVESIGN)
    {
      printf("Evaluate Success, Ans (Hex): %x, Ans (Dec): %d, Ans (Oct): %o\n", atoi(tokens[1].str), atoi(tokens[1].str), atoi(tokens[1].str));
      return NULL;
    }
    *success_main_loop = false;
    printf("Evaluate Failed\n");
    return NULL;
  }
  else
  {
    process_operator_token();
    give_priority();
    give_priority_no_parentheses();
    give_sub_priority();
    *success_main_loop = true;
    execution_histories[nr_execution_histories].result_token_history = strndup(calculate_one_round(*success_main_loop), strlen(calculate_one_round(*success_main_loop)));
    return calculate_one_round(*success_main_loop);
  }
}

word_t expr(char *e, bool *success) {
  init_execute_history();
  execution_histories[nr_execution_histories].result_token_history = strndup(e, strlen(e));
  nr_execution_histories = nr_execution_histories + 1;
  bool success_expr = true;
  bool finished_expr = false;
  int expr_main_loop_execution_count = 0;
  u_int64_t expr_answer = 0;
  while(success_expr && !finished_expr)
  {
    e = expr_main_loop(e, &success_expr, &finished_expr);
    execution_histories[nr_execution_histories].finished_history = finished_expr;
    execution_histories[nr_execution_histories].success_history = success_expr;
    nr_execution_histories = nr_execution_histories + 1;
    expr_main_loop_execution_count = expr_main_loop_execution_count + 1;
  }
  *success = success_expr;
  expr_answer = atoi(execution_histories[nr_execution_histories - 2].result_token_history);
  return expr_answer;
}