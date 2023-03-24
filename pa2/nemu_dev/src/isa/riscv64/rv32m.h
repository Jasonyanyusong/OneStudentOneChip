// RV32M Instructions
void rv32m_MUL(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_MULH(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_MULHSU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_MULHU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_DIV(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_DIVU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_REM(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv32m_REMU(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);