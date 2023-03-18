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
  char* watchpoint_expression;
  u_int64_t watchpoint_last_value;
  u_int64_t watchpoint_current_value;

  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

bool watchpoint_print_instruction = true;
bool watchpoint_print_debug = true;
bool watchpoint_print_checkpoint = true;
bool watchpoint_print_assertpoint = true;
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

void init_wp_pool() {
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: void init_wp_pool()] CKPT #01: Enter function\n");
  }
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].watchpoint_expression = NULL;
    wp_pool[i].watchpoint_last_value = 0;
    wp_pool[i].watchpoint_current_value = 0;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp()
{
  if(free_ == NULL)
  {
    if(watchpoint_print_debug)
    {
      printf("[NEMU_WATCHPOINT_DEBUG: WP* new_wp()] No free watchpoint space available\n");
    }
    if(watchpoint_print_assertpoint)
    {
      printf("[NEMU_WATCHPOINT_ASSERTPOINT: WP* new_wp()] No free watchpoint space availablen\n");
    }
    assert(0);
    return NULL;
  }
  WP *new_watch_point = free_;
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: WP* new_wp()] CKPT #01: set the new watchpoint\n");
  }
  free_ = free_ -> next;
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: WP* new_wp()] CKPT #02: move free_ to the next free_\n");
  }
  return new_watch_point;
}

void free_wp(WP *wp)
{
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: void free_wp(WP *wp)] CKPT #01: Enter function\n");
  }
  wp -> watchpoint_expression = NULL;
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: void free_wp(WP *wp)] CKPT #02: Execute \"wp -> watchpoint_expression = NULL;\" Finished\n");
  }
  wp -> next = free_;
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: void free_wp(WP *wp)] CKPT #03: Execute \"wp -> next = free_;\" Finished\n");
  }
  free_ = wp;
  if(watchpoint_print_checkpoint)
  {
    printf("[NEMU_WATCHPOINT_CHECKPOINT: void free_wp(WP *wp)] CKPT #04: Execute \"free_ = wp;\" Finished, End function\n");
  }
  return;
}