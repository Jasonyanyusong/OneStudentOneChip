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
 TK_NOTYPE = 256, TK_EQ = 255, TK_NEQ = 254, TK_AND = 253, TK_OR = 252, TK_NOT = 250, TK_POINTER = 249, TK_NUMBER = 248, TK_HEXNUMBER = 247, TK_REGISTER = 246, TK_MARK = 245,
  /* TODO: Add more token types */
  // THIS TODO FINISHED
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  // THIS TODO FINISHED

  {" +", TK_NOTYPE}, // spaces
  //{" +", TK_NOTYPE}, // tab
  {"0x[0-9,a-f]+", TK_HEXNUMBER}, // Hex Numbers
  {"[0-9]+", TK_NUMBER}, // Dec Numbers
  {"\\$[a-z]{2,3}", TK_REGISTER}, // Register Names
  {"\\(", '('}, // Left Parenthesis
  {"\\)", ')'}, // Right Parenthesis
  {"\\*", '*'}, // Multiply
  {"\\/", '/'}, // Devide
  {"\\+", '+'}, // Plus
  {"\\-", '-'}, // Minus
  {"==", TK_EQ}, // Equal
  {"!=", TK_NEQ}, // Not Equal
  {"&&", TK_AND}, // And
  {"\\|\\|", TK_OR}, // Or
  {"!", '!'}, // Not

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

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    // printf("make_token() Check Point #1\n");
    for (i = 0; i < NR_REGEX; i ++) {
      // printf("make_token() Check Point #2\n");
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        // printf("make_token() Check Point #3\n");
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
            printf("&&&& Use Default &&&&\n");
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NOTYPE:
          {
            printf("$$$$ Found a TK_NOTYPE TOKEN $$$$\n");
            printf("*** TK_NOTYPE will be thrown away directly ****\n");
            break;
          }
          case TK_EQ:
          {
            printf("$$$$ Found a TK_EQ TOKEN $$$$\n");
            tokens[nr_token].type = TK_EQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_NEQ:
          {
            printf("$$$$ Found a TK_NEQ TOKEN $$$$\n");
            tokens[nr_token].type = TK_NEQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_AND:
          {
            printf("$$$$ Found a TK_AND TOKEN $$$$\n");
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_OR:
          {
            printf("$$$$ Found a TK_OR TOKEN $$$$\n");
            tokens[nr_token].type = TK_OR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          /*case TK_POINTER:
          {
            printf("$$$$ Found a TK_POINTER TOKEN $$$$\n");
            tokens[nr_token].type = TK_POINTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }*/
          case TK_NUMBER:
          {
            printf("$$$$ Found a TK_NUMBER TOKEN $$$$\n");
            tokens[nr_token].type = TK_NUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_HEXNUMBER:
          {
            printf("$$$$ Found a TK_HEXNUMBER TOKEN $$$$\n");
            tokens[nr_token].type = TK_HEXNUMBER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          case TK_REGISTER: // !!! Special Case
          {
            printf("$$$$ Found a TK_REGISTER TOKEN $$$$\n");
            tokens[nr_token].type = TK_REGISTER;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }
          /*case TK_MARK:
          {
            printf("$$$$ Found a TK_MARK TOKEN $$$$\n");
            tokens[nr_token].type = TK_MARK;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            printf("**** tokens[nr_token].type is: %d ****\n", tokens[nr_token].type);
            printf("**** tokens[nr_token].str is: \"%s\" ****\n", tokens[nr_token].str);
            nr_token = nr_token + 1;
            break;
          }*/
        }
        // printf("make_token() Check Point #5\n");
        break;
      }
    }

    if (i == NR_REGEX) {
      // printf("make_token() Check Point #6\n");
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  printf("Token Numbers (Decimal): %d\n", nr_token);
  for(int display_index = 0; display_index < nr_token; display_index = display_index + 1)
  {
    printf("Token Number: %4d, Token Type (Decimal ID): %4d, Token String: \"%s\"\n", display_index, tokens[display_index].type, tokens[display_index].str);
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  //TODO();

  return 0;
}

