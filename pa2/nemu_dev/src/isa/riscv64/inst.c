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

#include "RISCV.h"

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  // Below is rs3's implementation, rs3 appears in RV32(64)F, RV32(64)D, RV32(64)Q and RV32(64)Zfh 
  // int rs3 = BITS(i, 31, 27);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_R : src1R(); src2R();         break;
    case TYPE_R4: /*TODO*/                  break;
    case TYPE_I : src1R();          immI(); break;
    case TYPE_S : src1R(); src2R(); immS(); break;
    case TYPE_B : src1R(); src2R(); immB(); break;
    case TYPE_U :                   immU(); break;
    case TYPE_J :                   immJ(); break;
  }
}

void rv32m_DIV(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_DIV(int get_rd, Decode* get_s)] CKPT #01: Enter DIV Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIV(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIV(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_DIV(int get_rd, Decode* get_s)] CKPT #01: End DIV Process Function\n");
  }
}

void rv32m_DIVU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_DIVU(int get_rd, Decode* get_s)] CKPT #01: Enter DIVU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_DIVU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_DIVU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_DIVU(int get_rd, Decode* get_s)] CKPT #01: End DIVU Process Function\n");
  }
}

void rv32m_REM(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_REM(int get_rd, Decode* get_s)] CKPT #01: Enter REM Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REM(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REM(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_REM(int get_rd, Decode* get_s)] CKPT #01: End REM Process Function\n");
  }
}

void rv32m_REMU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_REMU(int get_rd, Decode* get_s)] CKPT #01: Enter REMU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32m_REMU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32m_REMU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32m_REMU(int get_rd, Decode* get_s)] CKPT #01: End REMU Process Function\n");
  }
}

void rv64m_MULW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_MULW(int get_rd, Decode* get_s)] CKPT #01: Enter MULW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_MULW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_MULW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_MULW(int get_rd, Decode* get_s)] CKPT #01: End MULW Process Function\n");
  }
}

void rv64m_DIVW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_DIVW(int get_rd, Decode* get_s)] CKPT #01: Enter DIVW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_DIVW(int get_rd, Decode* get_s)] CKPT #01: End DIVW Process Function\n");
  }
}

void rv64m_DIVUW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_DIVUW(int get_rd, Decode* get_s)] CKPT #01: Enter DIVUW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_DIVUW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_DIVUW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_DIVUW(int get_rd, Decode* get_s)] CKPT #01: End DIVUW Process Function\n");
  }
}

void rv64m_REMW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_REMW(int get_rd, Decode* get_s)] CKPT #01: Enter REMW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_REMW(int get_rd, Decode* get_s)] CKPT #01: End REMW Process Function\n");
  }
}

void rv64m_REMUW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_REMUW(int get_rd, Decode* get_s)] CKPT #01: Enter REMUW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64m_REMUW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64m_REMUW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64m_REMUW(int get_rd, Decode* get_s)] CKPT #01: End REMUW Process Function\n");
  }
}

void rv32a_LR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_LR_W(int get_rd, Decode* get_s)] CKPT #01: Enter LR.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_LR_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_LR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_LR_W(int get_rd, Decode* get_s)] CKPT #01: End LR.W Process Function\n");
  }
}

void rv32a_SC_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_SC_W(int get_rd, Decode* get_s)] CKPT #01: Enter SC.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_SC_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_SC_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_SC_W(int get_rd, Decode* get_s)] CKPT #01: End SC.W Process Function\n");
  }
}

void rv32a_AMOSWAP_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOSWAP.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOSWAP_W(int get_rd, Decode* get_s)] CKPT #01: End AMOSWAP.W Process Function\n");
  }
}

void rv32a_AMOADD_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOADD.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOADD_W(int get_rd, Decode* get_s)] CKPT #01: End AMOADD.W Process Function\n");
  }
}

void rv32a_AMOXOR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOXOR.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOXOR_W(int get_rd, Decode* get_s)] CKPT #01: End AMOXOR.W Process Function\n");
  }
}

void rv32a_AMOAND_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOAND.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOAND_W(int get_rd, Decode* get_s)] CKPT #01: End AMOAND.W Process Function\n");
  }
}

void rv32a_AMOOR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOOR.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOOR_W(int get_rd, Decode* get_s)] CKPT #01: End AMOOR.W Process Function\n");
  }
}

void rv32a_AMOMIN_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMIN.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMIN_W(int get_rd, Decode* get_s)] CKPT #01: End AMOMIN.W Process Function\n");
  }
}

void rv32a_AMOMAX_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMAX.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMAX_W(int get_rd, Decode* get_s)] CKPT #01: End AMOMAX.W Process Function\n");
  }
}

void rv32a_AMOMINU_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMINU.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMINU_W(int get_rd, Decode* get_s)] CKPT #01: End AMOMINU.W Process Function\n");
  }
}

void rv32a_AMOMAXU_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMAXU.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32a_AMOMAXU_W(int get_rd, Decode* get_s)] CKPT #01: End AMOMAXU.W Process Function\n");
  }
}

void rv64a_LR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_LR_D(int get_rd, Decode* get_s)] CKPT #01: Enter LR.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_LR_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_LR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_LR_D(int get_rd, Decode* get_s)] CKPT #01: End LR.D Process Function\n");
  }
}

void rv64a_SC_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_SC_D(int get_rd, Decode* get_s)] CKPT #01: Enter SC.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_SC_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_SC_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_SC_D(int get_rd, Decode* get_s)] CKPT #01: End SC.D Process Function\n");
  }
}

void rv64a_AMOSWAP_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOSWAP.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOSWAP_D(int get_rd, Decode* get_s)] CKPT #01: End AMOSWAP.D Process Function\n");
  }
}

void rv64a_AMOADD_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOADD.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOADD_D(int get_rd, Decode* get_s)] CKPT #01: End AMOADD.D Process Function\n");
  }
}

void rv64a_AMOXOR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOXOR.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOXOR_D(int get_rd, Decode* get_s)] CKPT #01: End AMOXOR.D Process Function\n");
  }
}

void rv64a_AMOAND_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOAND.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOAND_D(int get_rd, Decode* get_s)] CKPT #01: End AMOAND.D Process Function\n");
  }
}

void rv64a_AMOOR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOOR.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOOR_D(int get_rd, Decode* get_s)] CKPT #01: End AMOOR.D Process Function\n");
  }
}

void rv64a_AMOMIN_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMIN.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMIN_D(int get_rd, Decode* get_s)] CKPT #01: End AMOMIN.D Process Function\n");
  }
}

void rv64a_AMOMAX_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMAX.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMAX_D(int get_rd, Decode* get_s)] CKPT #01: End AMOMAX.D Process Function\n");
  }
}

void rv64a_AMOMINU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMINU.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMINU_D(int get_rd, Decode* get_s)] CKPT #01: End AMOMINU.D Process Function\n");
  }
}

void rv64a_AMOMAXU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] CKPT #01: Enter AMOMAXU.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64a_AMOMAXU_D(int get_rd, Decode* get_s)] CKPT #01: End AMOMAXU.D Process Function\n");
  }
}

void rv32f_FLW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLW(int get_rd, Decode* get_s)] CKPT #01: Enter FLW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLW(int get_rd, Decode* get_s)] CKPT #01: End FLW Process Function\n");
  }
}

void rv32f_FSW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSW(int get_rd, Decode* get_s)] CKPT #01: Enter FSW Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSW(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSW(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSW(int get_rd, Decode* get_s)] CKPT #01: End FSW Process Function\n");
  }
}

void rv32f_FMADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMADD_S(int get_rd, Decode* get_s)] CKPT #01: Enter FMADD.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMADD_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMADD_S(int get_rd, Decode* get_s)] CKPT #01: End FMADD.S Process Function\n");
  }
}

void rv32f_FMSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] CKPT #01: Enter FMSUB.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMSUB_S(int get_rd, Decode* get_s)] CKPT #01: End FMSUB.S Process Function\n");
  }
}

void rv32f_FNMSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] CKPT #01: Enter FNMSUB.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FNMSUB_S(int get_rd, Decode* get_s)] CKPT #01: End FNMSUB.S Process Function\n");
  }
}

void rv32f_FNMADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] CKPT #01: Enter FNMADD.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FNMADD_S(int get_rd, Decode* get_s)] CKPT #01: End FNMADD.S Process Function\n");
  }
}

void rv32f_FADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FADD_S(int get_rd, Decode* get_s)] CKPT #01: Enter FADD.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FADD_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FADD_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FADD_S(int get_rd, Decode* get_s)] CKPT #01: End FADD.S Process Function\n");
  }
}

void rv32f_FSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSUB_S(int get_rd, Decode* get_s)] CKPT #01: Enter FSUB.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSUB_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSUB_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSUB_S(int get_rd, Decode* get_s)] CKPT #01: End FSUB.S Process Function\n");
  }
}

void rv32f_FMUL_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMUL_S(int get_rd, Decode* get_s)] CKPT #01: Enter FMUL.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMUL_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMUL_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMUL_S(int get_rd, Decode* get_s)] CKPT #01: End FMUL.S Process Function\n");
  }
}

void rv32f_FDIV_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FDIV_S(int get_rd, Decode* get_s)] CKPT #01: Enter FDIV.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FDIV_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FDIV_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FDIV_S(int get_rd, Decode* get_s)] CKPT #01: End FDIV.S Process Function\n");
  }
}

void rv32f_FSQRT_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] CKPT #01: Enter FSQRT.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSQRT_S(int get_rd, Decode* get_s)] CKPT #01: End FSQRT.S Process Function\n");
  }
}

void rv32f_FSGNJ_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJ.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJ_S(int get_rd, Decode* get_s)] CKPT #01: End FSGNJ.S Process Function\n");
  }
}

void rv32f_FSGNJN_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJN.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJN_S(int get_rd, Decode* get_s)] CKPT #01: End FSGNJN.S Process Function\n");
  }
}

void rv32f_FSGNJX_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJX.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FSGNJX_S(int get_rd, Decode* get_s)] CKPT #01: End FSGNJX.S Process Function\n");
  }
}

void rv32f_FMIN_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMIN_S(int get_rd, Decode* get_s)] CKPT #01: Enter FMIN.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMIN_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMIN_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMIN_S(int get_rd, Decode* get_s)] CKPT #01: End FMIN.S Process Function\n");
  }
}

void rv32f_FMAX_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMAX_S(int get_rd, Decode* get_s)] CKPT #01: Enter FMAX.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMAX_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMAX_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMAX_S(int get_rd, Decode* get_s)] CKPT #01: End FMAX.S Process Function\n");
  }
}

void rv32f_FCVT_W_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.W.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_W_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.W.S Process Function\n");
  }
}

void rv32f_FCVT_WU_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.WU.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_WU_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.WU.S Process Function\n");
  }
}

void rv32f_FMV_X_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.X.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMV_X_W(int get_rd, Decode* get_s)] CKPT #01: End FMV.X.W Process Function\n");
  }
}

void rv32f_FEQ_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FEQ_S(int get_rd, Decode* get_s)] CKPT #01: Enter FEQ.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FEQ_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FEQ_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FEQ_S(int get_rd, Decode* get_s)] CKPT #01: End FEQ.S Process Function\n");
  }
}

void rv32f_FLT_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLT_S(int get_rd, Decode* get_s)] CKPT #01: Enter FLT.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLT_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLT_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLT_S(int get_rd, Decode* get_s)] CKPT #01: End FLT.S Process Function\n");
  }
}

void rv32f_FLE_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLE_S(int get_rd, Decode* get_s)] CKPT #01: Enter FLE.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FLE_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FLE_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FLE_S(int get_rd, Decode* get_s)] CKPT #01: End FLE.S Process Function\n");
  }
}

void rv32f_FCLASS_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCLASS.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCLASS_S(int get_rd, Decode* get_s)] CKPT #01: End FCLASS.S Process Function\n");
  }
}

void rv32f_FCVT_S_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_S_W(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.W Process Function\n");
  }
}

void rv32f_FCVT_S_WU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.WU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FCVT_S_WU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.WU Process Function\n");
  }
}

void rv32f_FMV_W_X(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.W.X Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32f_FMV_W_X(int get_rd, Decode* get_s)] CKPT #01: End FMV.W.X Process Function\n");
  }
}

void rv64f_FCVT_L_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.L.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_L_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.L.S Process Function\n");
  }
}

void rv64f_FCVT_LU_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.LU.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_LU_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.LU.S Process Function\n");
  }
}

void rv64f_FCVT_S_L(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.L Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_S_L(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.L Process Function\n");
  }
}

void rv64f_FCVT_S_LU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.LU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64f_FCVT_S_LU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.LU Process Function\n");
  }
}

void rv32d_FLD(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLD(int get_rd, Decode* get_s)] CKPT #01: Enter FLD Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLD(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLD(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLD(int get_rd, Decode* get_s)] CKPT #01: End FLD Process Function\n");
  }
}

void rv32d_FSD(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSD(int get_rd, Decode* get_s)] CKPT #01: Enter FSD Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSD(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSD(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSD(int get_rd, Decode* get_s)] CKPT #01: End FSD Process Function\n");
  }
}

void rv32d_FMADD_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMADD_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMADD.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMADD_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMADD_D(int get_rd, Decode* get_s)] CKPT #01: End FMADD.D Process Function\n");
  }
}

void rv32d_FMSUB_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMSUB.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMSUB_D(int get_rd, Decode* get_s)] CKPT #01: End FMSUB.D Process Function\n");
  }
}

void rv32d_FNMSUB_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] CKPT #01: Enter FNMSUB.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FNMSUB_D(int get_rd, Decode* get_s)] CKPT #01: End FNMSUB.D Process Function\n");
  }
}

void rv32d_FNMADD_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] CKPT #01: Enter FNMADD.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FNMADD_D(int get_rd, Decode* get_s)] CKPT #01: End FNMADD.D Process Function\n");
  }
}

void rv32d_FADD_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FADD_D(int get_rd, Decode* get_s)] CKPT #01: Enter FADD.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FADD_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FADD_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FADD_D(int get_rd, Decode* get_s)] CKPT #01: End FADD.D Process Function\n");
  }
}

void rv32d_FSUB_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSUB_D(int get_rd, Decode* get_s)] CKPT #01: Enter FSUB.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSUB_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSUB_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSUB_D(int get_rd, Decode* get_s)] CKPT #01: End FSUB.D Process Function\n");
  }
}

void rv32d_FMUL_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMUL_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMUL.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMUL_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMUL_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMUL_D(int get_rd, Decode* get_s)] CKPT #01: End FMUL.D Process Function\n");
  }
}

void rv32d_FDIV_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FDIV_D(int get_rd, Decode* get_s)] CKPT #01: Enter FDIV.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FDIV_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FDIV_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FDIV_D(int get_rd, Decode* get_s)] CKPT #01: End FDIV.D Process Function\n");
  }
}

void rv32d_FSQRT_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] CKPT #01: Enter FSQRT.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSQRT_D(int get_rd, Decode* get_s)] CKPT #01: End FSQRT.D Process Function\n");
  }
}

void rv32d_FSGNJ_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJ.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJ_D(int get_rd, Decode* get_s)] CKPT #01: End FSGNJ.D Process Function\n");
  }
}

void rv32d_FSGNJN_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJN.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJN_D(int get_rd, Decode* get_s)] CKPT #01: End FSGNJN.D Process Function\n");
  }
}

void rv32d_FSGNJX_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJX.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FSGNJX_D(int get_rd, Decode* get_s)] CKPT #01: End FSGNJX.D Process Function\n");
  }
}

void rv32d_FMIN_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMIN_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMIN.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMIN_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMIN_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMIN_D(int get_rd, Decode* get_s)] CKPT #01: End FMIN.D Process Function\n");
  }
}

void rv32d_FMAX_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMAX_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMAX.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FMAX_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FMAX_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FMAX_D(int get_rd, Decode* get_s)] CKPT #01: End FMAX.D Process Function\n");
  }
}

void rv32d_FCVT_S_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_S_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.D Process Function\n");
  }
}

void rv32d_FCVT_D_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.S Process Function\n");
  }
}

void rv32d_FEQ_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FEQ_D(int get_rd, Decode* get_s)] CKPT #01: Enter FEQ.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FEQ_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FEQ_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FEQ_D(int get_rd, Decode* get_s)] CKPT #01: End FEQ.D Process Function\n");
  }
}

void rv32d_FLT_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLT_D(int get_rd, Decode* get_s)] CKPT #01: Enter FLT.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLT_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLT_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLT_D(int get_rd, Decode* get_s)] CKPT #01: End FLT.D Process Function\n");
  }
}

void rv32d_FLE_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLE_D(int get_rd, Decode* get_s)] CKPT #01: Enter FLE.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FLE_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FLE_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FLE_D(int get_rd, Decode* get_s)] CKPT #01: End FLE.D Process Function\n");
  }
}

void rv32d_FCLASS_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCLASS.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCLASS_D(int get_rd, Decode* get_s)] CKPT #01: End FCLASS.D Process Function\n");
  }
}

void rv32d_FCVT_W_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.W.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_W_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.W.D Process Function\n");
  }
}

void rv32d_FCVT_WU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.WU.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_WU_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.WU.D Process Function\n");
  }
}

void rv32d_FCVT_D_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_W(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.W Process Function\n");
  }
}

void rv32d_FCVT_D_WU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.WU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32d_FCVT_D_WU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.WU Process Function\n");
  }
}

void rv64d_FCVT_L_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.L.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_L_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.L.D Process Function\n");
  }
}

void rv64d_FCVT_LU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.LU.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_LU_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.LU.D Process Function\n");
  }
}

void rv64d_FMV_X_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.X.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FMV_X_D(int get_rd, Decode* get_s)] CKPT #01: End FMV.X.D Process Function\n");
  }
}

void rv64d_FCVT_D_L(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.L Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_D_L(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.L Process Function\n");
  }
}

void rv64d_FCVT_D_LU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.LU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FCVT_D_LU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.LU Process Function\n");
  }
}

void rv64d_FMV_D_X(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.D.X Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64d_FMV_D_X(int get_rd, Decode* get_s)] CKPT #01: End FMV.D.X Process Function\n");
  }
}

void rv32q_FLQ(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLQ(int get_rd, Decode* get_s)] CKPT #01: Enter FLQ Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLQ(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLQ(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLQ(int get_rd, Decode* get_s)] CKPT #01: End FLQ Process Function\n");
  }
}

void rv32q_FSQ(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSQ(int get_rd, Decode* get_s)] CKPT #01: Enter FSQ Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQ(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQ(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSQ(int get_rd, Decode* get_s)] CKPT #01: End FSQ Process Function\n");
  }
}

void rv32q_FMADD_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FMADD.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMADD_Q(int get_rd, Decode* get_s)] CKPT #01: End FMADD.Q Process Function\n");
  }
}

void rv32q_FMSUB_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FMSUB.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMSUB_Q(int get_rd, Decode* get_s)] CKPT #01: End FMSUB.Q Process Function\n");
  }
}

void rv32q_FNMSUB_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FNMSUB.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FNMSUB_Q(int get_rd, Decode* get_s)] CKPT #01: End FNMSUB.Q Process Function\n");
  }
}

void rv32q_FNMADD_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FNMADD.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FNMADD_Q(int get_rd, Decode* get_s)] CKPT #01: End FNMADD.Q Process Function\n");
  }
}

void rv32q_FADD_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FADD_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FADD.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FADD_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FADD_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FADD_Q(int get_rd, Decode* get_s)] CKPT #01: End FADD.Q Process Function\n");
  }
}

void rv32q_FSUB_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FSUB.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSUB_Q(int get_rd, Decode* get_s)] CKPT #01: End FSUB.Q Process Function\n");
  }
}

void rv32q_FMUL_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FMUL.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMUL_Q(int get_rd, Decode* get_s)] CKPT #01: End FMUL.Q Process Function\n");
  }
}

void rv32q_FDIV_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FDIV.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FDIV_Q(int get_rd, Decode* get_s)] CKPT #01: End FDIV.Q Process Function\n");
  }
}

void rv32q_FSQRT_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FSQRT_Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSQRT_Q(int get_rd, Decode* get_s)] CKPT #01: End FSQRT_Q Process Function\n");
  }
}

void rv32q_FSGNJ_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJ.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJ_Q(int get_rd, Decode* get_s)] CKPT #01: End FSGNJ.Q Process Function\n");
  }
}

void rv32q_FSGNJN_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJN.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJN_Q(int get_rd, Decode* get_s)] CKPT #01: End FSGNJN.Q Process Function\n");
  }
}

void rv32q_FSGNJX_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJX.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FSGNJX_Q(int get_rd, Decode* get_s)] CKPT #01: End FSGNJX.Q Process Function\n");
  }
}

void rv32q_FMIN_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FMIN.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMIN_Q(int get_rd, Decode* get_s)] CKPT #01: End FMIN.Q Process Function\n");
  }
}

void rv32q_FMAX_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FMAX.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FMAX_Q(int get_rd, Decode* get_s)] CKPT #01: End FMAX.Q Process Function\n");
  }
}

void rv32q_FCVT_S_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_S_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.Q Process Function\n");
  }
}

void rv32q_FCVT_Q_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.S Process Function\n");
  }
}

void rv32q_FCVT_D_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_D_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.Q Process Function\n");
  }
}

void rv32q_FCVT_Q_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.D Process Function\n");
  }
}

void rv32q_FEQ_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FEQ.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FEQ_Q(int get_rd, Decode* get_s)] CKPT #01: End FEQ.Q Process Function\n");
  }
}

void rv32q_FLT_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLT_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FLT.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLT_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLT_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLT_Q(int get_rd, Decode* get_s)] CKPT #01: End FLT.Q Process Function\n");
  }
}

void rv32q_FLE_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLE_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FLE.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FLE_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FLE_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FLE_Q(int get_rd, Decode* get_s)] CKPT #01: End FLE.Q Process Function\n");
  }
}

void rv32q_FCLASS_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCLASS.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCLASS_Q(int get_rd, Decode* get_s)] CKPT #01: End FCLASS.Q Process Function\n");
  }
}

void rv32q_FCVT_W_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.W.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_W_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.W.Q Process Function\n");
  }
}

void rv32q_FCVT_WU_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.WU.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_WU_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.WU.Q Process Function\n");
  }
}

void rv32q_FCVT_Q_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_W(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.W Process Function\n");
  }
}

void rv32q_FCVT_Q_WU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.WU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32q_FCVT_Q_WU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.WU Process Function\n");
  }
}

void rv64q_FCVT_L_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.L.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_L_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.L.Q Process Function\n");
  }
}

void rv64q_FCVT_LU_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.LU.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_LU_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.LU.Q Process Function\n");
  }
}

void rv64q_FCVT_Q_L(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.L Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_Q_L(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.L Process Function\n");
  }
}

void rv64q_FCVT_Q_LU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.LU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64q_FCVT_Q_LU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.LU Process Function\n");
  }
}

void rv32zfh_FLH(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLH(int get_rd, Decode* get_s)] CKPT #01: Enter FLH Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLH(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLH(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLH(int get_rd, Decode* get_s)] CKPT #01: End FLH Process Function\n");
  }
}

void rv32zfh_FSH(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSH(int get_rd, Decode* get_s)] CKPT #01: Enter FSH Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSH(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSH(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSH(int get_rd, Decode* get_s)] CKPT #01: End FSH Process Function\n");
  }
}

void rv32zfh_FMADD_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMADD.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMADD_H(int get_rd, Decode* get_s)] CKPT #01: End FMADD.H Process Function\n");
  }
}

void rv32zfh_FMSUB_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMSUB.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMSUB_H(int get_rd, Decode* get_s)] CKPT #01: End FMSUB.H Process Function\n");
  }
}

void rv32zfh_FNMSUB_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] CKPT #01: Enter FNMSUB.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FNMSUB_H(int get_rd, Decode* get_s)] CKPT #01: End FNMSUB.H Process Function\n");
  }
}

void rv32zfh_FNMADD_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] CKPT #01: Enter FNMADD.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FNMADD_H(int get_rd, Decode* get_s)] CKPT #01: End FNMADD.H Process Function\n");
  }
}

void rv32zfh_FADD_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] CKPT #01: Enter FADD.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FADD_H(int get_rd, Decode* get_s)] CKPT #01: End FADD.H Process Function\n");
  }
}

void rv32zfh_FSUB_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] CKPT #01: Enter FSUB.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSUB_H(int get_rd, Decode* get_s)] CKPT #01: End FSUB.H Process Function\n");
  }
}

void rv32zfh_FMUL_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMUL.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMUL_H(int get_rd, Decode* get_s)] CKPT #01: End FMUL.H Process Function\n");
  }
}

void rv32zfh_FDIV_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] CKPT #01: Enter FDIV.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FDIV_H(int get_rd, Decode* get_s)] CKPT #01: End FDIV.H Process Function\n");
  }
}

void rv32zfh_FSQRT_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] CKPT #01: Enter FSQRT.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSQRT_H(int get_rd, Decode* get_s)] CKPT #01: End FSQRT.H Process Function\n");
  }
}

void rv32zfh_FSGNJ_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJ.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJ_H(int get_rd, Decode* get_s)] CKPT #01: End FSGNJ.H Process Function\n");
  }
}

void rv32zfh_FSGNJN_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJN.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJN_H(int get_rd, Decode* get_s)] CKPT #01: End FSGNJN.H Process Function\n");
  }
}

void rv32zfh_FSGNJX_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] CKPT #01: Enter FSGNJX.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FSGNJX_H(int get_rd, Decode* get_s)] CKPT #01: End FSGNJX.H Process Function\n");
  }
}

void rv32zfh_FMIN_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMIN.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMIN_H(int get_rd, Decode* get_s)] CKPT #01: End FMIN.H Process Function\n");
  }
}

void rv32zfh_FMAX_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMAX.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMAX_H(int get_rd, Decode* get_s)] CKPT #01: End FMAX.H Process Function\n");
  }
}

void rv32zfh_FCVT_S_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.S.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_S_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.S.H Process Function\n");
  }
}

void rv32zfh_FCVT_H_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.S Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_S(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.S Process Function\n");
  }
}

void rv32zfh_FCVT_D_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.D.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_D_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.D.H Process Function\n");
  }
}

void rv32zfh_FCVT_H_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.D Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_D(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.D Process Function\n");
  }
}

void rv32zfh_FCVT_Q_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.Q.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_Q_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.Q.H Process Function\n");
  }
}

void rv32zfh_FCVT_H_Q(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.Q Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_Q(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.Q Process Function\n");
  }
}

void rv32zfh_FEQ_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] CKPT #01: Enter FEQ.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FEQ_H(int get_rd, Decode* get_s)] CKPT #01: End FEQ.H Process Function\n");
  }
}

void rv32zfh_FLT_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] CKPT #01: Enter FLT.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLT_H(int get_rd, Decode* get_s)] CKPT #01: End FLT.H Process Function\n");
  }
}

void rv32zfh_FLE_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] CKPT #01: Enter FLE.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FLE_H(int get_rd, Decode* get_s)] CKPT #01: End FLE.H Process Function\n");
  }
}

void rv32zfh_FCLASS_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCLASS.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCLASS_H(int get_rd, Decode* get_s)] CKPT #01: End FCLASS.H Process Function\n");
  }
}

void rv32zfh_FCVT_W_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.W.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_W_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.W.H Process Function\n");
  }
}

void rv32zfh_FCVT_WU_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.WU.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_WU_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.WU.H Process Function\n");
  }
}

void rv32zfh_FMV_X_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.X.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMV_X_H(int get_rd, Decode* get_s)] CKPT #01: End FMV.X.H Process Function\n");
  }
}

void rv32zfh_FCVT_H_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.W Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_W(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.W Process Function\n");
  }
}

void rv32zfh_FCVT_H_WU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.WU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FCVT_H_WU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.WU Process Function\n");
  }
}

void rv32zfh_FMV_H_X(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] CKPT #01: Enter FMV.H.X Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32zfh_FMV_H_X(int get_rd, Decode* get_s)] CKPT #01: End FMV.H.X Process Function\n");
  }
}

void rv64zfh_FCVT_L_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.L.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_L_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.L.H Process Function\n");
  }
}

void rv64zfh_FCVT_LU_H(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.LU.H Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_LU_H(int get_rd, Decode* get_s)] CKPT #01: End FCVT.LU.H Process Function\n");
  }
}

void rv64zfh_FCVT_H_L(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.L Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_H_L(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.L Process Function\n");
  }
}

void rv64zfh_FCVT_H_LU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  //INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] CKPT #01: Enter FCVT.H.LU Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_s->pc + get_imm;
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv64zfh_FCVT_H_LU(int get_rd, Decode* get_s)] CKPT #01: End FCVT.H.LU Process Function\n");
  }
}

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, rv32i_LUI(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, rv32i_AUIPC(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, rv32i_ADDI(s, rd, src1, src2, imm));
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, rv32i_ADD(s, rd, src1, src2, imm));
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, rv32i_AND(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, rv32i_ANDI(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, rv32i_JAL(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? ??? ????? 11001 11", jalr   , I, rv32i_JALR(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, rv32i_BEQ(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, rv32i_BNE(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, rv32i_BLT(s, rd, src1, src2, imm));
  INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld     , I, R(rd) = Mr(src1 + imm, 8));
  INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     , S, Mw(src1 + imm, 8, src2));

  // Changed to I, original N (ECALL and EBREAK)
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, rv32i_ECALL(s, rd, src1, src2, imm)); // R(10) is $a0
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , I, rv32i_EBREAK(s, rd, src1, src2, imm)); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
