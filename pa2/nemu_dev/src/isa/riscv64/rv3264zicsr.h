// RV32(64)Zicsr Instructions
void rv3264zicsr_CSRRW(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv3264zicsr_CSRRS(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv3264zicsr_CSRRC(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv3264zicsr_CSRRWI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv3264zicsr_CSRRSI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);
void rv3264zicsr_CSRRCI(Decode* get_s, int get_rd, word_t get_src1, word_t get_src2, word_t get_imm);