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

#include <stdio.h>
#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include "math.h"
// #include <stdlib.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

u_int32_t instruction_value = 0;

enum {
  TYPE_R, TYPE_I, TYPE_S, TYPE_B, TYPE_U, TYPE_J, TYPE_R4, 
  TYPE_N, // none
};

bool riscv64_instC_Print_Debug = true;
bool riscv64_instC_Print_ChecKPoinT = true;
bool riscv64_instC_Print_Instruction = true;

#define src1R() do { *src1 = R(rs1); } while (0) // Skeleton Code
#define src2R() do { *src2 = R(rs2); } while (0) // Skeleton Code
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0) // Skeleton Code
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0) // Skeleton Code
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0) // Skeleton Code
// My codes (Have confusions about SEXT and BITS)
#define immB() do { *imm = BITS(i, 31, 31) << 12 | BITS(i, 7, 7) << 11 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1;} while(0)
#define immJ() do { *imm = BITS(i, 31, 31) << 20 | BITS(i, 19, 12) << 12 | BITS(i, 20, 20) << 11 | BITS(i, 30, 21) << 1;} while(0)

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
  word_t src1 = 0, src2 = 0, src3 = 0, imm = 0;
  s->dnpc = s->snpc;

  printf("Before Execute: rd=0x%x, R(rd)=0x%lx, src1=0x%lx, src2=0x%lx, src3=0x%lx, imm=0x%lx, pc=0x%lx, dnpc=0x%lx, snpc=0x%lx\n", rd, R(rd), src1, src2, src3, imm, s -> pc, s -> dnpc, s -> snpc);

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  // For INSPAT Part, we use "assert(0)" if the instruction is not implemented

  INSTPAT_START();
  // RV64I Instructions
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm << 12);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s -> pc + 4, s -> pc = s -> pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 11001 11", jalr   , I, s -> pc = (src1 + imm) & ~ 1, R(rd) = s -> pc + 4);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, s -> pc = src1 == src2 ? s -> pc + imm, s -> pc + 4);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, s -> pc = src1 != src2 ? s -> pc + imm, s -> pc + 4);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, s -> pc = src1 < src2 ? s -> pc + imm, s -> pc + 4);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, s -> pc = src1 >= src2 ? s -> pc + imm: s -> pc + 4);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, s -> pc = src1 < src2 ? s -> pc + imm, s -> pc + 4);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, s -> pc = src1 >= src2 ? s -> pc + imm: s -> pc + 4);




  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, rv32i_ADDI(s, rd, src1, src2, imm));   // Good
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, rv32i_AND(s, rd, src1, src2, imm));    // Good
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, rv32i_ANDI(s, rd, src1, src2, imm));   // Good
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, rv32i_XORI(s, rd, src1, src2, imm));   // Good
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, rv32i_ORI(s, rd, src1, src2, imm));    // Good
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, rv32i_SUB(s, rd, src1, src2, imm));    // Good
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, rv32i_OR(s, rd, src1, src2, imm));     // Good
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, rv32i_XOR(s, rd, src1, src2, imm));    // Good
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, rv32i_SLL(s, rd, src1, src2, imm));    // Good
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, rv32i_SRA(s, rd, src1, src2, imm));    // Good
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, rv32i_SRL(s, rd, src1, src2, imm));    // Good
  INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld     , I, R(rd) = Mr(src1 + imm, 8));
  INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     , S, Mw(src1 + imm, 8, src2));

  // RV64M Instructions

  // RV64F, RV64D, RV64Q, RV64Zfh Instructions

  // RV64 Zicsr Zifencei Instructions

  // RV64A Instructions

  // RV64C Instructions

  // RV64V Instructions

  // RV64B Instructions

  // RV64H Instructions

  // Changed to I, original N (ECALL and EBREAK)
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , I, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  printf("After Execute: rd=0x%x, R(rd)=0x%lx, src1=0x%lx, src2=0x%lx, src3=0x%lx, imm=0x%lx, pc=0x%lx, dnpc=0x%lx, snpc=0x%lx\n", rd, R(rd), src1, src2, src3, imm, s -> pc, s -> dnpc, s -> snpc);

  return 0;
}

int isa_exec_once(Decode *s) {
  //instruction_value = 0;
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  //instruction_value = s->isa.inst.val;
  return decode_exec(s);
}
