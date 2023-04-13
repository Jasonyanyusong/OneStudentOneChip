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
    if((unsigned)cpu.gpr[integer_register_index] != (unsigned)ref_r -> gpr[integer_register_index])
    {
      isa_print_regcompare(*ref_r, pc, integer_register_index);
      return false;
    }
  }
  return true;
}

void isa_print_regcompare(CPU_state ref_r, vaddr_t pc, int error_integer_register_number)
{
  printf("\n\033[1;31;43mAt pc = 0x%lx, register x%d(%s) failed DiffTest!\033[0m\n", pc, error_integer_register_number, rvint_regs[error_integer_register_number]);
  printf("*****************************************************************************RV64 Integer Registers*****************************************************************************\n");
  printf("|    Name     |         Hex         |           Dec           |            Oct            |                                        Bin                                         |\n");

  for(int print_integer_register = 0; print_integer_register < 32; print_integer_register = print_integer_register + 1)
  {
    char nemu_register[79] = {0};
    char difftest_register[79] = {0};
    for(int group_index = 0; group_index < 16; group_index = group_index + 1)
    {
      for(int bit_index = 0; bit_index <= 4; bit_index = bit_index + 1)
      {
        if(bit_index != 4)
        {
          if(BITS(cpu.gpr[print_integer_register], 4 * group_index + bit_index, 4 * group_index + bit_index) == 1)
          {
            nemu_register[5 * group_index + bit_index] = '1';
          }
          else
          {
            nemu_register[5 * group_index + bit_index] = '0';
          }

          if(BITS(ref_r.gpr[print_integer_register], 4 * group_index + bit_index, 4 * group_index + bit_index) == 1)
          {
            difftest_register[5 * group_index + bit_index] = '1';
          }
          else
          {
            difftest_register[5 * group_index + bit_index] = '0';
          }
        }
        else
        {
          nemu_register[5 * group_index + bit_index] = ' ';
          difftest_register[5 * group_index + bit_index] = ' ';
        }
      }
    }
    nemu_register[79] = '\0';
    difftest_register[79] = '\0';
    // Codes for display register informations
    if(print_integer_register != error_integer_register_number)
    {
      printf("| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], nemu_register);
    }
    else
    {
      // "\033[1;44;31m" Means Print using highlight, red text and blue highlight
      // "\033[1;44;32m" Means Print using highlight, green text and blue highlight
      // Format: \033[ (Display Mode); (Background Color); (Text Color)m
      // After finishing printf, we use "\033[0m" to change printf style to default
      printf("\033[1;;31m| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\033[1;;31m <- NEMU's Result (Incorrect)\033[0m\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], cpu.gpr[print_integer_register], nemu_register);
      printf("\033[1;;32m| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\033[1;;32m <- DiffTest's Result (Correct)\033[0m\n", rvint_regs[print_integer_register], rvint_regs_alias[print_integer_register], ref_r.gpr[print_integer_register], ref_r.gpr[print_integer_register], ref_r.gpr[print_integer_register], difftest_register);
    }
  }
  printf("*****************************************************************************RV64 Integer Registers*****************************************************************************\n");
}

void isa_difftest_attach() {
}
