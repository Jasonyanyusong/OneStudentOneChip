// RV64D Instructions
void rv64d_FCVT_L_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64d_FCVT_LU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64d_FMV_X_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64d_FCVT_D_L(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64d_FCVT_D_LU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64d_FMV_D_X(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);