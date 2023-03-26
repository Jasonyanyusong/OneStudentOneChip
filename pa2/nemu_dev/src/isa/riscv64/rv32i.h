#include "lui.h"
#include "auipc.h"
#include "jal.h"
#include "jalr.h"
#include "beq.h"
#include "bne.h"
#include "blt.h"
#include "addi.h"
#include "andi.h"
#include "add.h"
#include "and.h"
#include "ecall.h"
#include "ebreak.h"
#include "bge.h"

// RV32I Instructions
void rv32i_BGE(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_BLTU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_BGEU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_LB(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_LH(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_LW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_LBU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_LHU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SB(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SH(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLTI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLTIU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_XORI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_ORI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLLI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SRLI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SRAI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SUB(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLL(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLT(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SLTU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_XOR(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SRL(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_SRA(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_OR(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_FENCE(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_FENCE_TSO(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32i_PAUSE(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);