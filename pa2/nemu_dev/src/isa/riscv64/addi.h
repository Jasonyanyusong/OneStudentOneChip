#include <stdlib.h>

void rv32i_ADDI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  // Completed
  //INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_ADDI(int get_rd, Decode* get_s)] CKPT #01: Enter ADDI Process Function\n");
  }
  u_int32_t copy_instruction = get_s->isa.inst.val;
  char instruction_bin_string[33] = {0};
  for(int i = 0; i <= 31; i = i + 1)
  {
    if(pow(2, 31 - i) <= copy_instruction)
    {
      instruction_bin_string[i] = '1';
      copy_instruction = copy_instruction - pow(2, 31 - i);
    }
    else
    {
      instruction_bin_string[i] = '0';
    }
  }
  char instruction_string_bin[63] = {0};
  for(int i = 0; i <= 62; i = i + 1)
  {
    if(i % 2 == 0)
    {
      instruction_string_bin[i] = instruction_bin_string[i/2];
    }
    else
    {
      instruction_string_bin[i] = ' ';
    }
  }
  instruction_bin_string[32] = '\0';
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] Received Instruction (Bin): 0b%s\n", instruction_bin_string);
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] Received Instruction (Oct): 0o%o\n", get_s->isa.inst.val);
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] Received Instruction (Dec): 0d%d\n", get_s->isa.inst.val);
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] Received Instruction (Hec): 0x%x\n", get_s->isa.inst.val);
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] RV32I Instruction ADDI (I-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2|1 1 1 1 1|1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0|9 8 7 6 5|4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |%s|\n",instruction_string_bin);
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 0|? ? ? ? ?|0 0 1 0 0 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] |-------imm[11:0]-------|---rs1---|-OPC-|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] ADDI adds the sign-extended 12-bit immediate to register rs1.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] Arithmetic overflow is ignored and the result is simply the low XLEN bits of the result.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ADDI(int get_rd, Decode* get_s)] ADDI rd, rs1, 0 is used to implement the MV rd, rs1 assembler pseudoinstruction.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] ********** Before Execute: **********\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] R(get_rd) (Dec) = %ld\n", R(get_rd));
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] R(get_rd) (Dec) = %lx\n", R(get_rd));
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  R(get_rd) = get_src1 + get_imm;
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] ********** After Execute: **********\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] R(get_rd) (Dec) = %ld\n", R(get_rd));
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] R(get_rd) (Dec) = %lx\n", R(get_rd));
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ADDI(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_ADDI(int get_rd, Decode* get_s)] CKPT #02: End ADDI Process Function\n");
  }
}