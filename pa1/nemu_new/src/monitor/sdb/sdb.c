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
  printf("++++ cmd_si command ++++\n\n");
  printf("==== Run the program for N steps and then suspend, if N is not given, defalt is 1 ==== \n");
  printf("==== Subcommnd Received: \"%s\" ====\n", args);
  if (args == NULL){
    printf("^^^^ No Subcommand received, default 1 ^^^^\n");
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
    printf("==== Will execute cpu_exec %d times ====\n", cmd_si_n);
    cpu_exec(cmd_si_n);
  }
  printf("==== Execution finished ====\n\n");
  return 0;
}

static int cmd_info(char *args){
  printf("++++ cmd_info command ++++\n\n");
  printf("==== info r: Print the state of register info w: Print the information of watch point(s) ====\n");
  if (args == NULL)
  {
    printf("!!!! No Subcommand !!!!\n");
  }
  else
  {
    if (strcmp(args, "r") == 0)
    {
      printf("==== Received Subcommand “r”: print the state of register ====\n");
      isa_reg_display();
    }
  else if (strcmp(args, "w") == 0)
    {
      printf("==== Received Subcommand “w”: print the information of watch point(s) ====\n");
      // Implement Later
    }
  else
    {
      printf("!!!! Subcommand Not Defined !!!!\n");
    }
  }
  printf("==== Execution finished ====\n\n");
  return 0;
}

// Due to config ISA as riscv64 and make it easy to compile, other ISA's print memory was setted as "%lx", however, should be "%x"

void print_memory_riscv64(int riscv64_start_memory_address, int steps)
{
  // RISCV64 Codes:
  //printf("Address: 0x%x :\n", riscv64_memory_address);
  //printf("1 Byte Data (paddr): %lx\n2 Byte Data (paddr): %lx\n4 Byte Data (paddr): %lx\n8 Byte Data (paddr): %lx\n", paddr_read(riscv64_memory_address, 1), paddr_read(riscv64_memory_address, 2),paddr_read(riscv64_memory_address, 4), paddr_read(riscv64_memory_address, 8));
  //printf("1 Byte Data (vaddr): %lx\n2 Byte Data (vaddr): %lx\n4 Byte Data (vaddr): %lx\n8 Byte Data (vaddr): %lx\n", vaddr_read(riscv64_memory_address, 1), vaddr_read(riscv64_memory_address, 2),vaddr_read(riscv64_memory_address, 4), vaddr_read(riscv64_memory_address, 8));
  //printf("\n");

  /*
  printf("******************************************************************************************************************\n");
  printf("|  Address   | 1b Phys | 2b Phys | 4b Phys  |     8b Phys      | 1b Virt | 2b Virt | 4b Virt  |     8b Virt      |\n");
  for (int i = riscv64_start_memory_address; i < riscv64_start_memory_address + steps; i = i + 1)
  {
    printf("| 0x%x | %7lx | %7lx | %8lx | %16lx | %7lx | %7lx | %8lx | %16lx |\n", i, paddr_read(i, 1), paddr_read(i, 2),paddr_read(i, 4), paddr_read(i, 8), vaddr_read(i, 1), vaddr_read(i, 2),vaddr_read(i, 4), vaddr_read(i, 8));
  }
  printf("******************************************************************************************************************\n");
  */

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

void print_memory_riscv32(int riscv32_memory_address)
{
  // RISCV32 Codes:

  /*
  printf("Address: 0x%x :\n", riscv32_memory_address);
  printf("1 Byte Data (paddr): %lx\n2 Byte Data (paddr): %lx\n4 Byte Data (paddr): %lx\n", paddr_read(riscv32_memory_address, 1), paddr_read(riscv32_memory_address, 2),paddr_read(riscv32_memory_address, 4));
  printf("1 Byte Data (vaddr): %lx\n2 Byte Data (vaddr): %lx\n4 Byte Data (vaddr): %lx\n", vaddr_read(riscv32_memory_address, 1), vaddr_read(riscv32_memory_address, 2),vaddr_read(riscv32_memory_address, 4));
  printf("\n");
  */

}

void print_memory_mips32(int mips32_memory_address)
{
  // MIPS32 Codes:
  /*
  printf("Address: 0x%x :\n", mips32_memory_address);
  printf("1 Byte Data (paddr): %lx\n2 Byte Data (paddr): %lx\n4 Byte Data (paddr): %lx\n", paddr_read(mips32_memory_address, 1), paddr_read(mips32_memory_address, 2),paddr_read(mips32_memory_address, 4));
  printf("1 Byte Data (vaddr): %lx\n2 Byte Data (vaddr): %lx\n4 Byte Data (vaddr): %lx\n", vaddr_read(mips32_memory_address, 1), vaddr_read(mips32_memory_address, 2),vaddr_read(mips32_memory_address, 4));
  printf("\n");
  */

}

void print_memory_loongarch32r(int loongarch32r_memory_address)
{
  // Loongarch32r Codes:
  /*
  printf("Address: 0x%x :\n", loongarch32r_memory_address);
  printf("1 Byte Data (paddr): %lx\n2 Byte Data (paddr): %lx\n4 Byte Data (paddr): %lx\n", paddr_read(loongarch32r_memory_address, 1), paddr_read(loongarch32r_memory_address, 2),paddr_read(loongarch32r_memory_address, 4));
  printf("1 Byte Data (vaddr): %lx\n2 Byte Data (vaddr): %lx\n4 Byte Data (vaddr): %lx\n", vaddr_read(loongarch32r_memory_address, 1), vaddr_read(loongarch32r_memory_address, 2),vaddr_read(loongarch32r_memory_address, 4));
  printf("\n");
  */
 
}

static int cmd_x(char *args){
  printf("++++ cmd_x command ++++\n");
  printf("==== Solve the value of EXPR, set the result of the start of memory address, using hexadecimal as output, print N continue 1/2/4(/8) Byte ====\n");
  int print_length;
  int start_memory_address;
  char *last_part_of_args;
  char *string_token_first = strtok_r(args, " ", &last_part_of_args);
  printf("==== string_token_first is : \"%s\" ====\n", string_token_first);
  print_length = atoi(string_token_first);
  printf("==== print_length is : \"%d\" ====\n", print_length);
  printf("==== last_part_of_args is : \"%s\" ====\n", last_part_of_args);
  sscanf(last_part_of_args, "%x", &start_memory_address);
  printf("---- start_memory_address (decimal) is: %d ----\n\n", start_memory_address);
  //printf("________________________________________________________________________________________________\n");
  //printf("| Address  |1b Phys|2b Phys|4b Phys |    8b Phys     |1b Virt|2b Virt|4b Virt |    8b Virt     |\n");

  print_memory_allisa(start_memory_address, print_length);

  for(int i = 0; i < print_length; i = i + 1)
  {
    //int this_memory_address = start_memory_address + i;
    // For different ISAs, enable different types of code
    //print_memory_riscv64(this_memory_address);
    // print_memory_riscv32(this_memory_address);
    // print_memory_mips32(this_memory_address);
    // print_memory_loongarch32r(this_memory_address);
  }
  //printf("________________________________________________________________________________________________\n");
  printf("==== Execution finished ====\n\n");
  return 0;
}

static int cmd_p(char *args){
  printf("++++ cmd_p command ++++\n");
  return 0;
}

static int cmd_w(char *args){
  printf("++++ cmd_w command ++++\n");
  return 0;
}

static int cmd_d(char *args){
  printf("++++ cmd_d command ++++\n");
  return 0;
}

static int cmd_q(char *args) {
  printf("++++ cmd_q command ++++\n");
  printf("==== q: Exit NEMU ====\n");
  nemu_state.state = NEMU_QUIT;
  // Refined the function for quiting NEMU, so the system will not report bug.
  // Principle: this is the function that calls the quit of NEMU, bu defalt, the function will not change the NEMU state when quiting.
  // If we add "nemu_state.state = NEMU_QUIT;" the system will know that NEMU quit with status "NEMU_QUIT", there will no bug generated.
  return -1;
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
  { "x", "Solve the value of EXPR, set the result of the start of memory address, using hexadecimal as output, print N continue 4 Byte", cmd_x},
  { "p", "Solve the expression EXPR", cmd_p},
  { "w", "When the value of EXPR changes, suspend the program", cmd_w},
  { "d", "Delete the watch point with number N", cmd_d}
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  printf("++++ cmd_help command ++++\n");
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

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

