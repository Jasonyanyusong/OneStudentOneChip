#include "yemu.h"

typedef union {
  struct {
    uint32_t opcode  :  7;
    uint32_t rd      :  5;
    uint32_t funct3  :  3;
    uint32_t rs1     :  5;
    int64_t imm11_0 : 12;
  } I;
  // struct { /* ... */ } R;
  uint32_t bytes;
} inst_t;

enum {
  R_a0 = 10,
  R_a1
};

static uint64_t R[32], PC;
static bool halt = false;
uint8_t M[MSIZE];

static void handle_ebreak() {
  switch (R[R_a0]) {
    case 0: putchar(R[R_a1] & 0xff); break;
    case 1: halt = true; break;
    default: panic("Unsupported ebreak command");
  }
}

static void inst_cycle() {
  inst_t *inst = (inst_t *)&M[PC];
  uint32_t rd  = inst->I.rd;
  uint32_t rs1 = inst->I.rs1;
  uint64_t imm = (int64_t)inst->I.imm11_0;
  if (inst->I.opcode == 0b0010011) {
    switch (inst->I.funct3) {
      case 0b000: R[rd] = R[rs1] + imm; break; // addi
      case 0b100: R[rd] = R[rs1] ^ imm; break; // xori
      case 0b110: R[rd] = R[rs1] | imm; break; // ori
      case 0b111: R[rd] = R[rs1] & imm; break; // andi
      default: panic("Unsupported funct3 = %d", inst->I.funct3);
    }
    R[0] = 0; // 若指令写入了R[0], 此处将其重置为0
  } else if (inst->bytes == 0x00100073) {
    handle_ebreak();
  } else { panic("Unsupported instuction: 0x%x", inst->bytes); }
  PC += 4;
}

void yemu_exec() {
  while (!halt) { inst_cycle(); }
}

void yemu_init() {
  PC = 0; R[0] = 0;
}
