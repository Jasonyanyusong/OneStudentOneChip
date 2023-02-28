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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

bool watchpoint_print_instruction = false;
bool watchpoint_print_debug = false;
bool watchpoint_print_checkpoint = false;
bool watchpoint_print_assertpoint = false;
void set_watchpoint_print_instruction(bool target_watchpoint_print_instruction);
void set_watchpoint_print_debug(bool target_watchpoint_print_debug);
void set_watchpoint_print_checkpoint(bool target_watchpoint_print_checkpoint);
void set_watchpoint_print_assertpoint(bool target_watchpoint_print_assertpoint);

void set_watchpoint_print_instruction(bool target_watchpoint_print_instruction)
{
  watchpoint_print_instruction = target_watchpoint_print_instruction;
  if(watchpoint_print_instruction)
  {
    printf("watchpoint_print_instruction: ON\n");
  }
  else
  {
    printf("watchpoint_print_instruction: OFF\n");
  }
  return;
}

void set_watchpoint_print_debug(bool target_watchpoint_print_debug)
{
  watchpoint_print_debug = target_watchpoint_print_debug;
  if(watchpoint_print_debug)
  {
    printf("watchpoint_print_debug: ON\n");
  }
  else
  {
    printf("watchpoint_print_debug: OFF\n");
  }
  return;
}

void set_watchpoint_print_checkpoint(bool target_watchpoint_print_checkpoint)
{
  watchpoint_print_checkpoint = target_watchpoint_print_checkpoint;
  if(watchpoint_print_checkpoint)
  {
    printf("watchpoint_print_checkpoint: ON\n");
  }
  else
  {
    printf("watchpoint_print_checkpoint: OFF\n");
  }
  return;
}

void set_watchpoint_print_assertpoint(bool target_watchpoint_print_assertpoint)
{
  watchpoint_print_assertpoint = target_watchpoint_print_assertpoint;
  if(watchpoint_print_assertpoint)
  {
    printf("watchpoint_print_assertpoint: ON\n");
  }
  else
  {
    printf("watchpoint_print_assertpoint: OFF\n");
  }
  return;
}

bool get_watchpoint_print_instruction()
{
  return watchpoint_print_instruction;
}
bool get_watchpoint_print_debug()
{
  return watchpoint_print_debug;
}
bool get_watchpoint_print_checkpoint()
{
  return watchpoint_print_checkpoint;
}
bool get_watchpoint_print_assertpoint()
{
  return watchpoint_print_assertpoint;
}

void watchpoint_debug_instruction_status()
{
  if(watchpoint_print_debug)
  {
    if(watchpoint_print_instruction)
    {
      printf("==== Instruction information display is ENABLED in Watch Point module ====\n");
    }
    else
    {
      printf("==== Instruction information display is DISABLED in Watch Point module ====\n");
    }
    if(watchpoint_print_debug)
    {
      printf("==== Debug message display is ENABLED in Watch Point module ====\n");
    }
    else
    {
      printf("==== Debug message display is DISABLED in Watch Point module ====\n");
    }
    if(watchpoint_print_checkpoint)
    {
      printf("==== Checkpoint display is ENABLED in Watch Point module ====\n");
    }
    else
    {
      printf("==== Checkpoint display is DISABLED in Watch Point module ====\n");
    }
    if(watchpoint_print_assertpoint)
    {
      printf("==== Assertpoint display is ENABLED in Watch Point module ====\n");
    }
    else
    {
      printf("==== Assertpoint display is DISABLED in Watch Point module ====\n");
    }
  }
}


void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

