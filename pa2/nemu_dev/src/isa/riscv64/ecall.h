void rv32i_ECALL(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  // Completed
  //INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_ECALL(int get_rd, Decode* get_s)] CKPT #01: Enter ECALL Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] RV64 Instruction ECALL (I-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] |0 0 0 0 0 0 0 0 0 0 0 0|0 0 0 0 0|0 0 0|0 0 0 0 0|0 0 1 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] |-------imm[11:0]-------|---rs1---|-OPC-|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] The ECALL instruction is used to make a service request to the execution environment.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_ECALL(int get_rd, Decode* get_s)] The EEI will define how parameters for the service request are passed, but usually these will be in defined locations in the integer register file.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] Before Execute:\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  NEMUTRAP(get_s->pc, R(10));
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] After Execute:\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_ECALL(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_ECALL(int get_rd, Decode* get_s)] CKPT #02: End ECALL Process Function\n");
  }
}
