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
} optimized_tokens[32];

int nr_optimized_token = 0;
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
  return;
}

void init_operator_tokens()
{
  // TODO
  return;
}

void init_operator_tokens_no_parentheses()
{
  // TODO
  return;
}

void init_optimized_tokens()
{
  // TODO
  return;
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

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        // printf("make_token() Check Point #4\n");
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
            break;
          }
          case TK_EQ:
          {
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NOT;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_AND:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_OR:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_OR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_POINTER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_POINTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_BINNUMBER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_BINNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_OCTNUMBER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_OCTNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NUMBER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_NUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_HEXNUMBER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_HEXNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_REGISTER:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_REGISTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_MARK:
          {
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
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_RIGHT_PARENTHESES;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_MULTIPLY:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MULTIPLY;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_DIVIDE:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_DIVIDE;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_PLUS:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_PLUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token = nr_token + 1;
            break;
          }
          case TK_MINUS:
          {
            memset(tokens[nr_token].str,0,sizeof(tokens[nr_token].str));
            tokens[nr_token].type = TK_MINUS;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
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

  for(int display_index = 0; display_index < nr_token; display_index = display_index + 1)
  {
    // NOTHING
  }

  if(check_parentheses(0, nr_token - 1))
  {
    // NOTHING
  }
  else
  {
    // NOTHING
  }

  return true;
}

void give_priority()
{
  for(int give_priority_index = 0; give_priority_index < nr_operator_token; give_priority_index = give_priority_index + 1)
  {
    switch(operator_tokens[give_priority_index].token_type)
    {
      case TK_OR:
      {
        operator_tokens[give_priority_index].priority = 1;
        break;
      }
      case TK_AND:
      {
        operator_tokens[give_priority_index].priority = 2;
        break;
      }
      case TK_EQ:
      {
        operator_tokens[give_priority_index].priority = 3;
        break;
      }
      case TK_NEQ:
      {
        operator_tokens[give_priority_index].priority = 3;
        break;
      }
      case TK_PLUS:
      {
        operator_tokens[give_priority_index].priority = 4;
        break;
      }
      case TK_MINUS:
      {
        operator_tokens[give_priority_index].priority = 4;
        break;
      }
      case TK_MULTIPLY:
      {
        operator_tokens[give_priority_index].priority = 5;
        break;
      }
      case TK_DIVIDE:
      {
        operator_tokens[give_priority_index].priority = 5;
        break;
      }
      case TK_NOT:
      {
        operator_tokens[give_priority_index].priority = 6;
        break;
      }
    }
  }
  for(int operator_token_print_index = 0; operator_token_print_index < nr_operator_token; operator_token_print_index = operator_token_print_index + 1)
  {
    // NOTHING
  }
  return;
}

void give_priority_no_parentheses()
{
  int local_highest_priority = -1;
  for(int current_scan_local_highest_priority_index = 1; current_scan_local_highest_priority_index < nr_operator_token - 1; current_scan_local_highest_priority_index = current_scan_local_highest_priority_index + 1)
  {
    if(operator_tokens[current_scan_local_highest_priority_index].priority > local_highest_priority)
    {
      local_highest_priority = operator_tokens[current_scan_local_highest_priority_index].priority;
    }
  }
  if(local_highest_priority < 0)
  {
    assert(0);
  }
  return;
}

int bool_to_int(bool bool_value)
{
  if(bool_value)
  {
    return 1;
  }
  return 0;
}

bool check_left_token_is_number_or_bool(int check_index)
{
  if(tokens[check_index - 1].type == TK_BINNUMBER || tokens[check_index - 1].type == TK_OCTNUMBER || tokens[check_index - 1].type == TK_NUMBER || tokens[check_index - 1].type == TK_HEXNUMBER)
  {
    return true;
  }
  return false;
}

bool check_right_token_is_number_or_bool(int check_index)
{
  if(tokens[check_index + 1].type == TK_BINNUMBER || tokens[check_index + 1].type == TK_OCTNUMBER || tokens[check_index + 1].type == TK_NUMBER || tokens[check_index + 1].type == TK_HEXNUMBER)
  {
    return true;
  }
  return false;
}

int process_add(int add_operator_index)
{
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
  int process_devide_answer = 0;
  int left_token_index = devide_operator_index - 1;
  int right_token_index = devide_operator_index + 1;
  int left_token_int_value = atoi(tokens[left_token_index].str);
  int right_token_int_value = atoi(tokens[right_token_index].str);
  process_devide_answer = left_token_int_value / right_token_int_value;
  return process_devide_answer;
}

int process_equal(int equal_operator_index)
{
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
  int process_and_answer = 0;
  int left_token_index = and_operator_index - 1;
  int right_token_index = and_operator_index + 1;
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
  return process_and_answer;
}

int process_or(int or_operator_index)
{
  int process_or_answer = 0;
  int left_token_index = or_operator_index - 1;
  int right_token_index = or_operator_index + 1;
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
  return process_or_answer;
}

int process_not(int not_operator_index)
{
  int process_not_answer = 0;
  int right_token_index = not_operator_index + 1;
  int right_token_int_value = atoi(tokens[right_token_index].str);
  if(right_token_int_value == 1)
  {
    process_not_answer = 0;
  }
  else
  {
    process_not_answer = 1;
  }
  return process_not_answer;
}

bool check_parentheses(int left_index, int right_index)
{
  int left_right_balance = 0;

  if(tokens[left_index].type != TK_LEFT_PARENTHESES)
  {
    return false;
  }

  if(tokens[right_index].type != TK_RIGHT_PARENTHESES)
  {
    return false;
  }

  for(int current_index = left_index; current_index <= right_index; current_index = current_index + 1)
  {
    if(tokens[current_index].type == TK_LEFT_PARENTHESES)
    {
      left_right_balance = left_right_balance + 1;
    }
    if(tokens[current_index].type == TK_RIGHT_PARENTHESES)
    {
      left_right_balance = left_right_balance - 1;
    }
    if(current_index != right_index && left_right_balance == 0)
    {
      return false;
    }
  }

  if(left_right_balance == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool check_parentheses_balance()
{
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
  return false;
}

void process_operator_token()
{
  int current_index_of_operator_tokens = 0;
  nr_operator_token = 0;
  for(int current_scanning_index = 0; current_scanning_index < nr_token; current_scanning_index = current_scanning_index + 1)
  {
    if(tokens[current_scanning_index].type != TK_BINNUMBER && tokens[current_scanning_index].type != TK_OCTNUMBER && tokens[current_scanning_index].type != TK_NUMBER && tokens[current_scanning_index].type != TK_HEXNUMBER)
    {
      operator_tokens[current_index_of_operator_tokens].position = current_scanning_index;
      operator_tokens[current_index_of_operator_tokens].token_type = tokens[current_scanning_index].type;
      operator_tokens[current_index_of_operator_tokens].regex = tokens[current_scanning_index].str;
      operator_tokens[current_index_of_operator_tokens].priority = 0;
      current_index_of_operator_tokens = current_index_of_operator_tokens + 1;
      nr_operator_token = nr_operator_token + 1;
    }
    else
    {
      // NOTHING
    }
  }
  return;
}

int find_dominant_operator(int left, int right, bool *expr_valid_call)
{
  return 0;
}

u_int64_t eval(int p, int q)
{
  if(valid_call == false)
  {
    printf("Invalid Call\n");
    return 0;
  }
  if(q > p)
  {
    valid_call = false;
    printf("Invalid eval() call\n");
    return 0;
  }
  if(p == q)
  {
    u_int64_t number = 0;
    if(tokens[p].type == TK_NUMBER)
    {
      sscanf(tokens[p].str, "%ld", &number);
      return number;
    }
    if(tokens[p].type == TK_HEXNUMBER)
    {
      sscanf(tokens[p].str, "%lx", &number);
      return number;
    }
    if(tokens[p].type == TK_OCTNUMBER)
    {
      sscanf(tokens[p].str, "%lo", &number);
      return number;
    }
    return number;
  }
  u_int64_t answer = 0;
  if(check_parentheses(p, q) == true)
  {
    return eval(p + 1, q - 1);
  }
  else
  {
    assert(0);
  }
  return answer;
}

word_t expr(char *e, bool *success) {
  if(!check_parentheses_balance())
  {
    *success = false;
    valid_call = false;
    return 0;
  }
  if (!make_token(e)) {
    *success = false;
    valid_call = false;
    return 0;
  }
  valid_call = true; // Prob: if this line is not annotated, it will cause Segmentation fault
  *success = true;
  u_int64_t expr_ans = eval(0, nr_token - 1);
  process_operator_token();
  give_priority();
  give_priority_no_parentheses();

  printf("Evaluate Success, Ans (Hex): %lx, Ans (Dec): %ld, Ans (Oct): %lo\n", expr_ans, expr_ans, expr_ans);
  return 0;
}