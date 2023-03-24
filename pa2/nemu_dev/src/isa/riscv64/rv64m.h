// RV64M Instructions
void rv64m_MULW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64m_DIVW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64m_DIVUW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64m_REMW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv64m_REMUW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);