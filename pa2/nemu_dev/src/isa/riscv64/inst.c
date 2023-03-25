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
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, rv32i_LUI(s, rd, src1, src2, imm)); // Good
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, rv32i_AUIPC(s, rd, src1, src2, imm)); // Good
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, rv32i_ADDI(s, rd, src1, src2, imm)); // Good
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, rv32i_ADD(s, rd, src1, src2, imm)); // Good
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
  instruction_value = 0;
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  instruction_value = s->isa.inst.val;
  return decode_exec(s);
}
