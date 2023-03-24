// RV64I Instructions
void rv64i_LWU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_LD(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SD(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_ADDIW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SLLIW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SRLIW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SRAIW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_ADDW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SUBW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SLLW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SRLW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64i_SRAW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);