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
#include <cpu/difftest.h>
#include "../local-include/reg.h"
#include<math.h>

const char *rvint_regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *rvint_regs_alias[] = {
  "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7",
  "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15",
  "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23",
  "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31"
};

void isa_print_regcompare(CPU_state ref_r, vaddr_t pc, int error_integer_register_number);

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for(int integer_register_index = 0; integer_register_index < 32; integer_register_index = integer_register_index + 1)
  {
    if(cpu.gpr[integer_register_index] != ref_r -> gpr[integer_register_index])
    {
      isa_print_regcompare(*ref_r, pc, integer_register_index);
      return false;
    }
  }
  return true;
}

void isa_print_regcompare(CPU_state ref_r, vaddr_t pc, int error_integer_register_number)
{
  printf("\nAt pc = 0x%lx\n", pc);
  printf("*****************************************************************************RV64 Integer Registers*****************************************************************************\n");
  printf("|    Name     |         Hex         |           Dec           |            Oct            |                                        Bin                                         |\n");

  for(int print_integer_register = 0; print_integer_register < 32; print_integer_register = print_integer_register + 1)
  {
    // Codes for processing reference register binary string
    char ref_reg_value_bin_string[65] = {0};
    u_int64_t ref_get_reg_value = ref_r.gpr[print_integer_register];
    for(int i = 0; i <= 63; i = i + 1)
    {
      if(ref_get_reg_value >= pow(2, 63 - i))
      {
        ref_reg_value_bin_string[i] = '1';
        ref_get_reg_value = ref_get_reg_value - pow(2, 63 - i);
      }
      else
      {
        ref_reg_value_bin_string[i] = '0';
      }
    }
    ref_reg_value_bin_string[64] = '\0';
    char ref_display_ref_reg_string[79] = {0};
    for(int parts_number = 0; parts_number < 16; parts_number = parts_number + 1)
    {
      for(int secter_number = 0; secter_number <= 4; secter_number = secter_number + 1)
      {
        if(secter_number != 4)
        {
          ref_display_ref_reg_string[5 * parts_number + secter_number] = ref_reg_value_bin_string[4 * parts_number + secter_number];
        }
        else
        {
          ref_display_ref_reg_string[5 * parts_number + secter_number] = ' ';
        }
      }
    }
    ref_display_ref_reg_string[79] = '\0';

    // Codes for processing cpu register binary string
    char cpu_reg_value_bin_string[65] = {0};
    u_int64_t cpu_get_reg_value = cpu.gpr[print_integer_register];
    for(int i = 0; i <= 63; i = i + 1)
    {
      if(cpu_get_reg_value >= pow(2, 63 - i))
      {
        cpu_reg_value_bin_string[i] = '1';
        cpu_get_reg_value = cpu_get_reg_value - pow(2, 63 - i);
      }
      else
      {
        cpu_reg_value_bin_string[i] = '0';
      }
    }
    cpu_reg_value_bin_string[64] = '\0';
    char cpu_display_cpu_reg_string[79] = {0};
    for(int parts_number = 0; parts_number < 16; parts_number = parts_number + 1)
    {
      for(int secter_number = 0; secter_number <= 4; secter_number = secter_number + 1)
      {
        if(secter_number != 4)
        {
          cpu_display_cpu_reg_string[5 * parts_number + secter_number] = cpu_reg_value_bin_string[4 * parts_number + secter_number];
        }
        else
        {
          cpu_display_cpu_reg_string[5 * parts_number + secter_number] = ' ';
        }
      }
    }
    cpu_display_cpu_reg_string[79] = '\0';


    // Codes for display register informations
    if(print_integer_register != error_integer_register_number)
    {
      printf("| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu_display_cpu_reg_string);
    }
    else
    {
      // "\033[1;44;31m" Means Print using highlight, red text and blue highlight
      // "\033[1;44;32m" Means Print using highlight, green text and blue highlight
      printf("\033[1;44;31m| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\033[0m\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu_display_cpu_reg_string);
      printf("\033[1;44;32m| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\033[0m\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], ref_r.gpr[print_integer_register], ref_r.gpr[print_integer_register], ref_r.gpr[print_integer_register], ref_display_ref_reg_string);
    }
  }
  printf("*****************************************************************************RV64 Integer Registers*****************************************************************************\n");
}

void isa_difftest_attach() {
}
