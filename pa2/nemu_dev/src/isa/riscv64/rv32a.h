// RV32A Instructions
void rv32a_LR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_SC_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOSWAP_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOADD_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOXOR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOAND_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOOR_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOMIN_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOMAX_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOMINU_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32a_AMOMAXU_W(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);