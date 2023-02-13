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
  printf("==== 让程序单步执行N条指令后暂停执行, 当N没有给出时, 缺省为1 ==== \n");
  printf("==== 程序得到如下子指令: \"%s\" ====\n", args);
  if (args == NULL){
    printf("^^^^ 没有收到子命令，默认执行 1 次 ^^^^\n");
    cpu_exec(1);
  }
  else{
    int cmd_si_n;
    cmd_si_n = atoi(args);
    printf("==== 将单步执行 %d 次 ====\n", cmd_si_n);
    cpu_exec(cmd_si_n);
  }
  printf("==== 执行完毕,程序退出 ====\n\n");
  return 0;
}

static int cmd_info(char *args){
  printf("++++ cmd_info command ++++\n\n");
  printf("==== info r: 打印寄存器状态 info w: 打印监视点信息 ====\n");
  if (args == NULL)
  {
    printf("!!!! 没有给出子指令 !!!!\n");
  }
  else
  {
    if (strcmp(args, "r") == 0)
    {
      printf("==== 收到子指令“r”: 打印寄存器状态 ====\n");
      isa_reg_display();
    }
  else if (strcmp(args, "w") == 0)
    {
      printf("==== 收到子指令“w”: 打印监视点信息 ====\n");
      // Implement Later
    }
  else
    {
      printf("!!!! 子指令无定义 !!!!\n");
    }
  }
  printf("==== 执行完毕,程序退出 ====\n\n");
  return 0;
}

static int cmd_x(char *args){
  printf("++++ cmd_x command ++++\n");
  printf("==== 求出表达式EXPR的值, 将结果作为起始内存地址, 以十六进制形式输出连续的N个4字节 ====\n");
  int print_length;
  int start_memory_address;
  char *last_part_of_args;
  char *string_token_first = strtok_r(args, " ", &last_part_of_args);
  printf("==== 读取出的string_token_first为: \"%s\" ====\n", string_token_first);
  print_length = atoi(string_token_first);
  printf("==== 转换后的print_length为: \"%d\" ====\n", print_length);
  printf("==== 读取出的last_part_of_args为: \"%s\" ====\n", last_part_of_args);
  sscanf(last_part_of_args, "%x", &start_memory_address);
  printf("---- 打印内存前，start_memory_address (10进制)为: %d ----\n", start_memory_address);
  for(int i = 0; i < print_length; i = i + 1)
  {
    printf("Address: %x , Data: %llx\n", start_memory_address, paddr_read(start_memory_address, 4));
  }
  printf("==== 执行完毕,程序退出 ====\n\n");
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
  { "help", "打印命令的帮助信息 Display information about all supported commands", cmd_help },
  { "c", "继续运行被暂停的程序 Continue the execution of the program", cmd_c },
  { "q", "退出NEMU Exit NEMU", cmd_q },
  { "si", "让程序单步执行N条指令后暂停执行, 当N没有给出时, 缺省为1 Run the program for N steps and then suspend, if N is not given, defalt is 1", cmd_si},
  { "info", "info r: 打印寄存器状态 info w: 打印监视点信息 info r: print the state of register, info w: point the information of monitor point", cmd_info},
  { "x", "求出表达式EXPR的值, 将结果作为起始内存地址, 以十六进制形式输出连续的N个4字节solve the value of EXPR, set the result of the start of memory address, using hexadecimal as output, print N continue 4 Byte", cmd_x},
  { "p", "求出表达式EXPR的值 slove the expression EXPR", cmd_p},
  { "w", "当表达式EXPR的值发生变化时, 暂停程序执行 when the value of EXPR changes, suspend the program", cmd_w},
  { "d", "删除序号为N的监视点 delete the monitor point with number N", cmd_d}
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
