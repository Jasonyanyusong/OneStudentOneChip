// RV64A Instructions
void rv64a_LR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_SC_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOSWAP_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOADD_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOXOR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOAND_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOOR_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOMIN_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOMAX_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOMINU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64a_AMOMAXU_D(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);