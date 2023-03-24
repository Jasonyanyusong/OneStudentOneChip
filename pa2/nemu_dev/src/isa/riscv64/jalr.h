void rv32i_JALR(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)
{
  // Completed
  //INSTPAT("??????? ????? ????? ??? ????? 11001 11", jalr   , I, s->pc = (rs1 + imm) & ~1; R(rd) = s -> pc + 4);
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_JALR(int get_rd, Decode* get_s)] CKPT #01: Enter JALR Process Function\n");
  }
  if(riscv64_instC_Print_Instruction)
  {
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] RV32I Instruction JALR (I-type), Pattern:\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2|1 1 1 1 1|1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0|9 8 7 6 5|4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] |-----------------------|---------|-----------------------------|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 0|? ? ? ? ?|1 1 0 0 1 1 1|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] |-------imm[11:0]-------|---rs1---|func3|----rd---|----opcode---|\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] *****************************************************************\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] The indirect jump instruction JALR (jump and link register) uses the I-type encoding.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] The target address is obtained by adding the sign-extended 12-bit I-immediate to the register rs1, then setting the least-significant bit of the result to zero.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] The address of the instruction following the jump (pc+4) is written to register rd.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] Register x0 can be used as the destination if the result is not required.\n");
    printf("[NEMU_RISCV64_instC INSTRUCTION: void rv32i_JALR(int get_rd, Decode* get_s)] The JAL and JALR instructions will generate an instruction-address-misaligned exception if the target address is not aligned to an IALIGN-bit boundary.\n");
  }
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] Before Execute:\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  get_s -> dnpc = (get_src1 + get_imm) & ~1;
  R(get_rd) = get_s -> pc + 4;
  if(riscv64_instC_Print_Debug)
  {
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] After Execute:\n");
    // Decimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_rd (Dec) = %d\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\n", get_s -> dnpc);
    // Hexadecimal debug information
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\n", get_rd);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\n", get_src1);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\n", get_src2);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\n", get_imm);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\n", get_s -> pc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\n", get_s -> snpc);
    printf("[NEMU_RISCV64_instC DEBUG: void rv32i_JALR(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\n", get_s -> dnpc);
  }
  if(riscv64_instC_Print_ChecKPoinT)
  {
    printf("[NEMU_RISCV64_instC CHECKPOINT: void rv32i_JALR(int get_rd, Decode* get_s)] CKPT #02: End JALR Process Function\n");
  }
}