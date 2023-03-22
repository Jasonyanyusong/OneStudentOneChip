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

RV3264Zifencei = []
RV3264Zifencei.append(instructions("rv3264zifencei", "FENCE_I", "FENCE.I"))

RV3264Zicsr = []
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRW", "CSRRW"))
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRS", "CSRRS"))
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRC", "CSRRC"))
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRWI", "CSRRWI"))
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRSI", "CSRRSI"))
RV3264Zicsr.append(instructions("rv3264zicsr", "CSRRCI", "CSRRCI"))

RV32M = []
RV32M.append(instructions("rv32m", "MUL", "MUL"))
RV32M.append(instructions("rv32m", "MULH", "MULH"))
RV32M.append(instructions("rv32m", "MULHSU", "MULHSU"))
RV32M.append(instructions("rv32m", "MULHU", "MULHU"))
RV32M.append(instructions("rv32m", "DIV", "DIV"))
RV32M.append(instructions("rv32m", "DIVU", "DIVU"))
RV32M.append(instructions("rv32m", "REM", "REM"))
RV32M.append(instructions("rv32m", "REMU", "REMU"))

RV64M = []
RV64M.append(instructions("rv64m", "MULW", "MULW"))
RV64M.append(instructions("rv64m", "DIVW", "DIVW"))
RV64M.append(instructions("rv64m", "DIVUW", "DIVUW"))
RV64M.append(instructions("rv64m", "REMW", "REMW"))
RV64M.append(instructions("rv64m", "REMUW", "REMUW"))

RV32A = []
RV32A.append(instructions("rv32a", "LR_W", "LR.W"))
RV32A.append(instructions("rv32a", "SC_W", "SC.W"))
RV32A.append(instructions("rv32a", "AMOSWAP_W", "AMOSWAP.W"))
RV32A.append(instructions("rv32a", "AMOADD_W", "AMOADD.W"))
RV32A.append(instructions("rv32a", "AMOXOR_W", "AMOXOR.W"))
RV32A.append(instructions("rv32a", "AMOAND_W", "AMOAND.W"))
RV32A.append(instructions("rv32a", "AMOOR_W", "AMOOR.W"))
RV32A.append(instructions("rv32a", "AMOMIN_W", "AMOMIN.W"))
RV32A.append(instructions("rv32a", "AMOMAX_W", "AMOMAX.W"))
RV32A.append(instructions("rv32a", "AMOMINU_W", "AMOMINU.W"))
RV32A.append(instructions("rv32a", "AMOMAXU_W", "AMOMAXU.W"))

RV64A = []
RV64A.append(instructions("rv64a", "LR_D", "LR.D"))
RV64A.append(instructions("rv64a", "SC_D", "SC.D"))
RV64A.append(instructions("rv64a", "AMOSWAP_D", "AMOSWAP.D"))
RV64A.append(instructions("rv64a", "AMOADD_D", "AMOADD.D"))
RV64A.append(instructions("rv64a", "AMOXOR_D", "AMOXOR.D"))
RV64A.append(instructions("rv64a", "AMOAND_D", "AMOAND.D"))
RV64A.append(instructions("rv64a", "AMOOR_D", "AMOOR.D"))
RV64A.append(instructions("rv64a", "AMOMIN_D", "AMOMIN.D"))
RV64A.append(instructions("rv64a", "AMOMAX_D", "AMOMAX.D"))
RV64A.append(instructions("rv64a", "AMOMINU_D", "AMOMINU.D"))
RV64A.append(instructions("rv64a", "AMOMAXU_D", "AMOMAXU.D"))

RV32F = []
RV32F.append(instructions("rv32f", "FLW", "FLW"))
RV32F.append(instructions("rv32f", "FSW", "FSW"))
RV32F.append(instructions("rv32f", "FMADD_S", "FMADD.S"))
RV32F.append(instructions("rv32f", "FMSUB_S", "FMSUB.S"))
RV32F.append(instructions("rv32f", "FNMSUB_S", "FNMSUB.S"))
RV32F.append(instructions("rv32f", "FNMADD_S", "FNMADD.S"))
RV32F.append(instructions("rv32f", "FADD_S", "FADD.S"))
RV32F.append(instructions("rv32f", "FSUB_S", "FSUB.S"))
RV32F.append(instructions("rv32f", "FMUL_S", "FMUL.S"))
RV32F.append(instructions("rv32f", "FDIV_S", "FDIV.S"))
RV32F.append(instructions("rv32f", "FSQRT_S", "FSQRT.S"))
RV32F.append(instructions("rv32f", "FSGNJ_S", "FSGNJ.S"))
RV32F.append(instructions("rv32f", "FSGNJN_S", "FSGNJN.S"))
RV32F.append(instructions("rv32f", "FSGNJX_S", "FSGNJX.S"))
RV32F.append(instructions("rv32f", "FMIN_S", "FMIN.S"))
RV32F.append(instructions("rv32f", "FMAX_S", "FMAX.S"))
RV32F.append(instructions("rv32f", "FCVT_W_S", "FCVT.W.S"))
RV32F.append(instructions("rv32f", "FCVT_WU_S", "FCVT.WU.S"))
RV32F.append(instructions("rv32f", "FMV_X_W", "FMV.X.W"))
RV32F.append(instructions("rv32f", "FEQ_S", "FEQ.S"))
RV32F.append(instructions("rv32f", "FLT_S", "FLT.S"))
RV32F.append(instructions("rv32f", "FLE_S", "FLE.S"))
RV32F.append(instructions("rv32f", "FCLASS_S", "FCLASS.S"))
RV32F.append(instructions("rv32f", "FCVT_S_W", "FCVT.S.W"))
RV32F.append(instructions("rv32f", "FCVT_S_WU", "FCVT.S.WU"))
RV32F.append(instructions("rv32f", "FMV_W_X", "FMV.W.X"))

RV64F = []
RV64F.append(instructions("rv64f", "FCVT_L_S", "FCVT.L.S"))
RV64F.append(instructions("rv64f", "FCVT_LU_S", "FCVT.LU.S"))
RV64F.append(instructions("rv64f", "FCVT_S_L", "FCVT.S.L"))
RV64F.append(instructions("rv64f", "FCVT_S_LU", "FCVT.S.LU"))

RV32D = []
RV32D.append(instructions("rv32d", "FLD", "FLD"))
RV32D.append(instructions("rv32d", "FSD", "FSD"))
RV32D.append(instructions("rv32d", "FMADD_D", "FMADD.D"))
RV32D.append(instructions("rv32d", "FMSUB_D", "FMSUB.D"))
RV32D.append(instructions("rv32d", "FNMSUB_D", "FNMSUB.D"))
RV32D.append(instructions("rv32d", "FNMADD_D", "FNMADD.D"))
RV32D.append(instructions("rv32d", "FADD_D", "FADD.D"))
RV32D.append(instructions("rv32d", "FSUB_D", "FSUB.D"))
RV32D.append(instructions("rv32d", "FMUL_D", "FMUL.D"))
RV32D.append(instructions("rv32d", "FDIV_D", "FDIV.D"))
RV32D.append(instructions("rv32d", "FSQRT_D", "FSQRT.D"))
RV32D.append(instructions("rv32d", "FSGNJ_D", "FSGNJ.D"))
RV32D.append(instructions("rv32d", "FSGNJN_D", "FSGNJN.D"))
RV32D.append(instructions("rv32d", "FSGNJX_D", "FSGNJX.D"))
RV32D.append(instructions("rv32d", "FMIN_D", "FMIN.D"))
RV32D.append(instructions("rv32d", "FMAX_D", "FMAX.D"))
RV32D.append(instructions("rv32d", "FCVT_S_D", "FCVT.S.D"))
RV32D.append(instructions("rv32d", "FCVT_D_S", "FCVT.D.S"))
RV32D.append(instructions("rv32d", "FEQ_D", "FEQ.D"))
RV32D.append(instructions("rv32d", "FLT_D", "FLT.D"))
RV32D.append(instructions("rv32d", "FLE_D", "FLE.D"))
RV32D.append(instructions("rv32d", "FCLASS_D", "FCLASS.D"))
RV32D.append(instructions("rv32d", "FCVT_W_D", "FCVT.W.D"))
RV32D.append(instructions("rv32d", "FCVT_WU_D", "FCVT.WU.D"))
RV32D.append(instructions("rv32d", "FCVT_D_W", "FCVT.D.W"))
RV32D.append(instructions("rv32d", "FCVT_D_WU", "FCVT.D.WU"))

RV64D = []
RV64D.append(instructions("rv64d", "FCVT_L_D", "FCVT.L.D"))
RV64D.append(instructions("rv64d", "FCVT_LU_D", "FCVT.LU.D"))
RV64D.append(instructions("rv64d", "FMV_X_D", "FMV.X.D"))
RV64D.append(instructions("rv64d", "FCVT_D_L", "FCVT.D.L"))
RV64D.append(instructions("rv64d", "FCVT_D_LU", "FCVT.D.LU"))
RV64D.append(instructions("rv64d", "FMV_D_X", "FMV.D.X"))

RV32Q = []
RV32Q.append(instructions("rv32q", "FLQ", "FLQ"))
RV32Q.append(instructions("rv32q", "FSQ", "FSQ"))
RV32Q.append(instructions("rv32q", "FMADD_Q", "FMADD.Q"))
RV32Q.append(instructions("rv32q", "FMSUB_Q", "FMSUB.Q"))
RV32Q.append(instructions("rv32q", "FNMSUB_Q", "FNMSUB.Q"))
RV32Q.append(instructions("rv32q", "FNMADD_Q", "FNMADD.Q"))
RV32Q.append(instructions("rv32q", "FADD_Q", "FADD.Q"))
RV32Q.append(instructions("rv32q", "FSUB_Q", "FSUB.Q"))
RV32Q.append(instructions("rv32q", "FMUL_Q", "FMUL.Q"))
RV32Q.append(instructions("rv32q", "FDIV_Q", "FDIV.Q"))
RV32Q.append(instructions("rv32q", "FSQRT_Q", "FSQRT_Q"))
RV32Q.append(instructions("rv32q", "FSGNJ_Q", "FSGNJ.Q"))
RV32Q.append(instructions("rv32q", "FSGNJN_Q", "FSGNJN.Q"))
RV32Q.append(instructions("rv32q", "FSGNJX_Q", "FSGNJX.Q"))
RV32Q.append(instructions("rv32q", "FMIN_Q", "FMIN.Q"))
RV32Q.append(instructions("rv32q", "FMAX_Q", "FMAX.Q"))
RV32Q.append(instructions("rv32q", "FCVT_S_Q", "FCVT.S.Q"))
RV32Q.append(instructions("rv32q", "FCVT_Q_S", "FCVT.Q.S"))
RV32Q.append(instructions("rv32q", "FCVT_D_Q", "FCVT.D.Q"))
RV32Q.append(instructions("rv32q", "FCVT_Q_D", "FCVT.Q.D"))
RV32Q.append(instructions("rv32q", "FEQ_Q", "FEQ.Q"))
RV32Q.append(instructions("rv32q", "FLT_Q", "FLT.Q"))
RV32Q.append(instructions("rv32q", "FLE_Q", "FLE.Q"))
RV32Q.append(instructions("rv32q", "FCLASS_Q", "FCLASS.Q"))
RV32Q.append(instructions("rv32q", "FCVT_W_Q", "FCVT.W.Q"))
RV32Q.append(instructions("rv32q", "FCVT_WU_Q", "FCVT.WU.Q"))
RV32Q.append(instructions("rv32q", "FCVT_Q_W", "FCVT.Q.W"))
RV32Q.append(instructions("rv32q", "FCVT_Q_WU", "FCVT.Q.WU"))

RV64Q = []
RV64Q.append(instructions("rv64q", "FCVT_L_Q", "FCVT.L.Q"))
RV64Q.append(instructions("rv64q", "FCVT_LU_Q", "FCVT.LU.Q"))
RV64Q.append(instructions("rv64q", "FCVT_Q_L", "FCVT.Q.L"))
RV64Q.append(instructions("rv64q", "FCVT_Q_LU", "FCVT.Q.LU"))

RV32Zfh = []
RV32Zfh.append(instructions("rv32zfh", "FLH", "FLH"))
RV32Zfh.append(instructions("rv32zfh", "FSH", "FSH"))
RV32Zfh.append(instructions("rv32zfh", "FMADD_H", "FMADD.H"))
RV32Zfh.append(instructions("rv32zfh", "FMSUB_H", "FMSUB.H"))
RV32Zfh.append(instructions("rv32zfh", "FNMSUB_H", "FNMSUB.H"))
RV32Zfh.append(instructions("rv32zfh", "FNMADD_H", "FNMADD.H"))
RV32Zfh.append(instructions("rv32zfh", "FADD_H", "FADD.H"))
RV32Zfh.append(instructions("rv32zfh", "FSUB_H", "FSUB.H"))
RV32Zfh.append(instructions("rv32zfh", "FMUL_H", "FMUL.H"))
RV32Zfh.append(instructions("rv32zfh", "FDIV_H", "FDIV.H"))
RV32Zfh.append(instructions("rv32zfh", "FSQRT_H", "FSQRT.H"))
RV32Zfh.append(instructions("rv32zfh", "FSGNJ_H", "FSGNJ.H"))
RV32Zfh.append(instructions("rv32zfh", "FSGNJN_H", "FSGNJN.H"))
RV32Zfh.append(instructions("rv32zfh", "FSGNJX_H", "FSGNJX.H"))
RV32Zfh.append(instructions("rv32zfh", "FMIN_H", "FMIN.H"))
RV32Zfh.append(instructions("rv32zfh", "FMAX_H", "FMAX.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_S_H", "FCVT.S.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_H_S", "FCVT.H.S"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_D_H", "FCVT.D.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_H_D", "FCVT.H.D"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_Q_H", "FCVT.Q.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_H_Q", "FCVT.H.Q"))
RV32Zfh.append(instructions("rv32zfh", "FEQ_H", "FEQ.H"))
RV32Zfh.append(instructions("rv32zfh", "FLT_H", "FLT.H"))
RV32Zfh.append(instructions("rv32zfh", "FLE_H", "FLE.H"))
RV32Zfh.append(instructions("rv32zfh", "FCLASS_H", "FCLASS.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_W_H", "FCVT.W.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_WU_H", "FCVT.WU.H"))
RV32Zfh.append(instructions("rv32zfh", "FMV_X_H", "FMV.X.H"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_H_W", "FCVT.H.W"))
RV32Zfh.append(instructions("rv32zfh", "FCVT_H_WU", "FCVT.H.WU"))
RV32Zfh.append(instructions("rv32zfh", "FMV_H_X", "FMV.H.X"))

RV64Zfh = []
RV64Zfh.append(instructions("rv64zfh", "FCVT_L_H", "FCVT.L.H"))
RV64Zfh.append(instructions("rv64zfh", "FCVT_LU_H", "FCVT.LU.H"))
RV64Zfh.append(instructions("rv64zfh", "FCVT_H_L", "FCVT.H.L"))
RV64Zfh.append(instructions("rv64zfh", "FCVT_H_LU", "FCVT.H.LU"))

for i in range (0, len(RV32Zfh), 1):
    RV32Zfh[i].print_c()
    print("")

for i in range (0, len(RV64Zfh), 1):
    RV64Zfh[i].print_c()
    print("")