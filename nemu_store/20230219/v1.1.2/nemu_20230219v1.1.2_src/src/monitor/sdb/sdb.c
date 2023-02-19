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
#include <cpu/cpu.h>
#include <stdlib.h>
#include <math.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>
#include <memory/host.h>
#include "sdb.h"

static int is_batch_mode = false;

// To enable sdb print usage instruction for each call or print debug messge, set these two bool values to true
static bool print_instruction = false;
static bool print_debug_message = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  printf("++++ cmd_c command ++++\n");
  cpu_exec(-1);
  return 0;
}

static int cmd_si(char *args){
  if (print_instruction)
  {
    printf("++++ cmd_si command ++++\n\n");
    printf("==== Run the program for N steps and then suspend, if N is not given, defalt is 1 ==== \n");
    printf("==== Subcommnd Received: \"%s\" ====\n", args);
  }
  if (args == NULL){
    if (print_debug_message)
    {
      printf("^^^^ No Subcommand received, default 1 ^^^^\n");
    }
    cpu_exec(1);
  }
  else{
    int cmd_si_n;
    cmd_si_n = atoi(args);
    if(cmd_si_n < -1)
    {
      printf("!!!! Invalid input !!!!\n");
      return 0;
    }
    if (print_debug_message)
    {
      printf("==== Will execute cpu_exec %d times ====\n", cmd_si_n);
    }
    cpu_exec(cmd_si_n);
  }
  if (print_debug_message)
  {
    printf("==== Execution finished ====\n\n");
  }
  return 0;
}

static int cmd_info(char *args){
  if (print_instruction)
  {
    printf("++++ cmd_info command ++++\n\n");
    printf("==== info r: Print the state of register info w: Print the information of watch point(s) ====\n");
  }

  if (args == NULL)
  {
    printf("!!!! No Subcommand !!!!\n");
    return 0;
  }
  else
  {
    if (strcmp(args, "r") == 0)
    {
      if (print_debug_message)
      {
        printf("==== Received Subcommand “r”: print the state of register ====\n");
      }
      isa_reg_display();
    }
  else if (strcmp(args, "w") == 0)
    {
      if (print_debug_message)
      {
        printf("==== Received Subcommand “w”: print the information of watch point(s) ====\n");
      }
      // Implement Later
    }
  else
    {
      printf("!!!! Subcommand Not Defined !!!!\n");
    }
  }
  if (print_debug_message)
  {
    printf("==== Execution finished ====\n\n");
  }
  return 0;
}

void print_memory_allisa(int allisa_start_memory_address, int steps)
{
  printf("******************************************************************************************************************\n");
  printf("|  Address   | 1b Phys | 2b Phys | 4b Phys  |     8b Phys      | 1b Virt | 2b Virt | 4b Virt  |     8b Virt      |\n");
  for (int i = allisa_start_memory_address; i < allisa_start_memory_address + steps; i = i + 1)
  {
    IFDEF(CONFIG_ISA64, printf("| 0x%x | %7lx | %7lx | %8lx | %16lx | %7lx | %7lx | %8lx | %16lx |\n", i, paddr_read(i, 1), paddr_read(i, 2),paddr_read(i, 4), paddr_read(i, 8), vaddr_read(i, 1), vaddr_read(i, 2),vaddr_read(i, 4), vaddr_read(i, 8)););
    IFNDEF(CONFIG_ISA64, printf("| 0x%x | %7x | %7x | %8x |        NA        | %7x | %7x | %8x |        NA        |\n", i, paddr_read(i, 1), paddr_read(i, 2),paddr_read(i, 4), vaddr_read(i, 1), vaddr_read(i, 2),vaddr_read(i, 4)););
  }
  printf("******************************************************************************************************************\n");
}

static int cmd_x(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_x command ++++\n");
    printf("==== x N EXPR: Solve the value of EXPR, set the result of the start of memory address, using hexadecimal as output, print 1/2/4(/8 RISCV64 Only) continue Bit ====\n");
  }
  int print_length;
  int start_memory_address;
  char *last_part_of_args;
  char *string_token_first = strtok_r(args, " ", &last_part_of_args);
  print_length = atoi(string_token_first);
  sscanf(last_part_of_args, "%x", &start_memory_address);
  if(print_debug_message)
  {
    printf("==== string_token_first is : \"%s\" ====\n", string_token_first);
    printf("==== print_length is : \"%d\" ====\n", print_length);
    printf("==== last_part_of_args is : \"%s\" ====\n", last_part_of_args);
    printf("---- start_memory_address (decimal) is: %d ----\n\n", start_memory_address);
  }
  print_memory_allisa(start_memory_address, print_length);
  if(print_debug_message)
  {
    printf("==== Execution finished ====\n\n");
  }
  return 0;
}

static int cmd_p(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_p command ++++\n");
    printf("==== p EXPR: Solve the expression EXPR ====\n");
  }
  u_int64_t expression_ans;
  bool expression_success;
  expression_success = false;
  if(print_debug_message)
  {
    printf("---- Received Expression: \"%s\" , evaluating ----\n", args);
  }
  expression_ans = expr(args, &expression_success);
  if(expression_success)
  {
    printf("Ans: %lx\n", expression_ans);
  }
  return 0;
}

static int cmd_w(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_w command ++++\n");
  }
  return 0;
}

static int cmd_d(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_d command ++++\n");
  }
  return 0;
}

static int cmd_q(char *args) {
  if(print_instruction)
  {
    printf("++++ cmd_q command ++++\n");
  }
  if(print_debug_message)
  {
    printf("==== q: Exit NEMU ====\n");
  }
  nemu_state.state = NEMU_QUIT;
  // Refined the function for quiting NEMU, so the system will not report bug.
  // Principle: this is the function that calls the quit of NEMU, bu defalt, the function will not change the NEMU state when quiting.
  // If we add "nemu_state.state = NEMU_QUIT;" the system will know that NEMU quit with status "NEMU_QUIT", there will no bug generated.
  return -1;
}

static int cmd_debug(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_debug command ++++\n");
    printf("==== debug: Switch mode of debug behavior ====\n");
  }
  if(true)
  {
    if(print_debug_message)
    {
      printf("==== Current mode of debug: Enabled ====\n");
      printf("==== Will change to mode: Disabled ====\n");
    }
    else
    {
      printf("==== Current mode of debug: Disabled ====\n");
      printf("==== Will change to mode: Enabled ====\n");
    }
  }
  print_debug_message = !print_debug_message;
  return 0;
}

static int cmd_instruction(char *args){
  if(print_instruction)
  {
    printf("++++ cmd_instruction command ++++\n");
    printf("==== instruction: Switch mode of instruction behavior ====\n");
  }
  if(true)
  {
    if(print_instruction)
    {
      printf("==== Current mode of instruction: Enabled ====\n");
      printf("==== Will change to mode: Disabled ====\n");
    }
    else
    {
      printf("==== Current mode of instruction: Disabled ====\n");
      printf("==== Will change to mode: Enabled ====\n");
    }
  }
  print_instruction = !print_instruction;
  return 0;
}

static int cmd_version(char *args) {
  if(print_instruction)
  {
    printf("++++ cmd_verison command ++++\n");
  }
  if(print_debug_message)
  {
    printf("==== version: Print version of current NEMU ====\n");
  }
  printf("Version: 1.1.2, Date: 2023.02.19, Jasonyanyusong, Beijing 101 High School\n");

  printf("\nVersion History:\n");
  printf("Version 1.0.0: Refine NEMU structure\n");
  printf("Version 1.0.1: Optimize output of \"info r\" and \"x N EXPR\"\n");
  printf("Version 1.0.2: Remove redundant codes\n");
  printf("Version 1.0.3: Optimize \"version\" function, optimize output\n");
  printf("Version 1.0.4: Add enable and disable of printing debug and instruction message\n");
  printf("Version 1.1.0: Add Command Line Interface for expression evaluation\n");
  printf("Version 1.1.1: Implement switch structure (default, NOTYPE, EQ, NEQ AND, OR, NUMBER, HEXNUMBER) in make_token()\n");
  printf("Version 1.1.2: Add display of token number, token type and token string at the end of make_token()\n");

  if(print_debug_message)
  {
    printf("==== Execution finished ====\n\n");
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Run the program for N steps and then suspend, if N is not given, defalt is 1", cmd_si},
  { "info", "info r: Print the state of register, info w: Print the information of watch point(s)", cmd_info},
  { "x", "Solve the value of EXPR, set the result of the start of memory address, using hexadecimal as output, print N continue memory", cmd_x},
  { "p", "Solve the expression EXPR", cmd_p},
  { "w", "When the value of EXPR changes, suspend the program", cmd_w},
  { "d", "Delete the watch point with number N", cmd_d},
  { "version", "Print version of current NEMU", cmd_version},
  { "debug", "Switch mode of debug behavior", cmd_debug},
  { "instruction", "Switch mode of instruction behavior", cmd_instruction},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  if(print_instruction)
  {
    printf("++++ cmd_help command ++++\n");
  }
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  Log("Version: 1.1.2, Date: 2023.02.19, Jasonyanyusong, Beijing 101 High School");

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}