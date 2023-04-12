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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for(int integer_register_index = 0; integer_register_index < 32; integer_register_index = integer_register_index + 1)
  {
    if(cpu.gpr[integer_register_index] != ref_r -> gpr[integer_register_index])
    {
      printf("At pc 0x%lx, find DiffTest Error in register No.%d\n", pc, integer_register_index);
      printf("***************************************************************************REF-RV64 Integer Registers***************************************************************************\n");
      printf("|    Name     |         Hex         |           Dec           |            Oct            |                                        Bin                                         |\n");
      for(int print_reference_integer_register = 0; print_reference_integer_register < 32; print_reference_integer_register = print_reference_integer_register + 1)
      {
        char reg_value_bin_string[65] = {0};
        u_int64_t get_reg_value = ref_r -> gpr[print_reference_integer_register];
        for(int i = 0; i <= 63; i = i + 1)
        {
          if(get_reg_value >= pow(2, 63 - i))
          {
            reg_value_bin_string[i] = '1';
            get_reg_value = get_reg_value - pow(2, 63 - i);
          }
          else
          {
            reg_value_bin_string[i] = '0';
          }
        }
        reg_value_bin_string[64] = '\0';
        char display_reg_string[79] = {0};
        for(int parts_number = 0; parts_number < 16; parts_number = parts_number + 1)
        {
          for(int secter_number = 0; secter_number <= 4; secter_number = secter_number + 1)
          {
            if(secter_number != 4)
            {
              display_reg_string[5 * parts_number + secter_number] = reg_value_bin_string[4 * parts_number + secter_number];
            }
            else
            {
              display_reg_string[5 * parts_number + secter_number] = ' ';
            }
          }
        }
        display_reg_string[79] = '\0';
        printf("| %4s (%4s) | 0x %16lx | 0d %20ld | 0o %22lo | 0b %s |\n", rvint_regs[print_reference_integer_register], rvint_regs_alias[print_reference_integer_register], ref_r -> gpr[print_reference_integer_register], ref_r -> gpr[print_reference_integer_register], ref_r -> gpr[print_reference_integer_register], display_reg_string);
      }
      printf("***************************************************************************REF-RV64 Integer Registers***************************************************************************\n");
      return false;
    }
  }
  return true;
}

void isa_difftest_attach() {
}
