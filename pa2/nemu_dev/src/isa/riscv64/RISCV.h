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

#include "rv32i.h"
#include "rv32m.h"
#include "rv64i.h"
#include "rv64m.h"