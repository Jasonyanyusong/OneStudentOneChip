// RV32F Instructions
void rv32f_FLW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FNMSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FNMADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FADD_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSUB_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMUL_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FDIV_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSQRT_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSGNJ_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSGNJN_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FSGNJX_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMIN_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMAX_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FCVT_W_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FCVT_WU_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMV_X_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FEQ_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FLT_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FLE_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FCLASS_S(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FCVT_S_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FCVT_S_WU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32f_FMV_W_X(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);