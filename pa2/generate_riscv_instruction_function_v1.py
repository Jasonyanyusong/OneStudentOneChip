# This script will automatically generate C code for RV instructions
class instructions:
    def __init__(self, module_name, function_name, print_name):
        self.module_name = module_name
        self.function_name = function_name
        self.print_name = print_name
    def print_c(self):
        # Line 01
        print("void", self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm)")
        # Line 02
        print("{")
        # Line 03
        print("  //INSTPAT(\"??????? ????? ????? ??? ????? 00101 11\", auipc  , U, R(rd) = s->pc + imm);")
        # Line 04
        print("  if(riscv64_instC_Print_ChecKPoinT)")
        # Line 05
        print("  {")
        # Line 06
        print("    printf(\"[NEMU_RISCV64_instC CHECKPOINT: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] CKPT #01: Enter", self.print_name, end="")
        print(" Process Function\\n\");")
        # Line 07
        print("  }")
        # Line 08
        print("  if(riscv64_instC_Print_Instruction)")
        # Line 09
        print("  {")
        # Line 10
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] RV64 Instruction AUIPC (U-type), Pattern:\\n\");")
        # Line 11
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] *****************************************************************\\n\");")
        # Line 12
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] |3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1|1 1 0 0 0|0 0 0 0 0 0 0|\\n\");")
        # Line 13
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] |1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2|1 0 9 8 7|6 5 4 3 2 1 0|\\n\");")
        # Line 14
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] |---------------------------------------------------------------|\\n\");")
        # Line 15
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] |? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?|? ? ? ? ?|0 0 1 0 1 1 1|\\n\");")
        # Line 16
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] |---------------imm[31:12]--------------|----rd---|----opcode---|\\n\");")
        # Line 17
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] *****************************************************************\\n\");")
        # Line 18
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format.\\n\");")
        # Line 19
        print("    printf(\"[NEMU_RISCV64_instC INSTRUCTION: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] AUIPC forms a 32-bit offset from the U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the address of the AUIPC instruction, then places the result in register rd.\\n\");")
        # Line 20
        print("  }")
        # Line 21
        print("  if(riscv64_instC_Print_Debug)")
        # Line 22
        print("  {")
        # Line 23
        print("    // Decimal debug information")
        # Line 24
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_rd (Dec) = %d\\n\", get_rd);")
        # Line 25
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_src1 (Dec) = %ld\\n\", get_src1);")
        # Line 26
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_src2 (Dec) = %ld\\n\", get_src2);")
        # Line 27
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_imm (Dec) = %ld\\n\", get_imm);")
        # Line 28
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Dec) = %ld\\n\", get_s -> pc);")
        # Line 29
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Dec) = %ld\\n\", get_s -> snpc);")
        # Line 30
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Dec) = %ld\\n\", get_s -> dnpc);")
        # Line 31
        print("    // Hexadecimal debug information")
        # Line 32
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_rd (Hex) = 0x%x\\n\", get_rd);")
        # Line 33
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_src1 (Hex) = 0x%lx\\n\", get_src1);")
        # Line 34
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_src2 (Hex) = 0x%lx\\n\", get_src2);")
        # Line 35
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_imm (Hex) = 0x%lx\\n\", get_imm);")
        # Line 36
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> pc (Program Counter) (Hex) = 0x%lx\\n\", get_s -> pc);")
        # Line 37
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> snpc (Static Next Program Counter) (Hex) = 0x%lx\\n\", get_s -> snpc);")
        # Line 38
        print("    printf(\"[NEMU_RISCV64_instC DEBUG: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] get_s -> dnpc (Dynamic Next Program Counter) (Hex) = 0x%lx\\n\", get_s -> dnpc);")
        # Line 39
        print("  }")
        # Line 40
        print("  R(get_rd) = get_s->pc + get_imm;")
        # Line 41
        print("  if(riscv64_instC_Print_ChecKPoinT)")
        # Line 42
        print("  {")
        # Line 43
        print("    printf(\"[NEMU_RISCV64_instC CHECKPOINT: void ",end="")
        print(self.module_name, end="")
        print("_", end="")
        print(self.function_name, end="")
        print("(int get_rd, Decode* get_s)] CKPT #01: End", self.print_name, end="")
        print(" Process Function\\n\");")
        # Line 44
        print("  }")
        # Line 45
        print("}")


RV64I = []
RV64I.append(instructions("rv64i", "LWU", "LWU"))
RV64I.append(instructions("rv64i", "LD", "LD"))
RV64I.append(instructions("rv64i", "SD", "SD"))
RV64I.append(instructions("rv64i", "SLLI", "SLLI"))
RV64I.append(instructions("rv64i", "SRLI", "SRLI"))
RV64I.append(instructions("rv64i", "SRAI", "SRAI"))
RV64I.append(instructions("rv64i", "ADDIW", "ADDIW"))
RV64I.append(instructions("rv64i", "SLLIW", "SLLIW"))
RV64I.append(instructions("rv64i", "SRLIW", "SRLIW"))
RV64I.append(instructions("rv64i", "SRAIW", "SRAIW"))
RV64I.append(instructions("rv64i", "ADDW", "ADDW"))
RV64I.append(instructions("rv64i", "SUBW", "SUBW"))
RV64I.append(instructions("rv64i", "SLLW", "SLLW"))
RV64I.append(instructions("rv64i", "SRLW", "SRLW"))
RV64I.append(instructions("rv64i", "SRAW", "SRAW"))

for i in range (0, len(RV64I), 1):
    RV64I[i].print_c()
    print("")