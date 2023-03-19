#include "yemu.h"

static long fsize(FILE *fp) {
  long now = ftell(fp);
  Perror(now != -1, "Fail to return the file position"); // 要求ftell()成功
  int ret = fseek(fp, 0, SEEK_END);
  Perror(ret != -1, "Fail to seek the end of the file"); // 要求fseek()成功
  long size = ftell(fp);
  Perror(size != -1, "Fail to return the file position"); // 要求ftell()成功
  ret = fseek(fp, now, SEEK_SET);
  Perror(ret != -1, "Fail to seek the end of the file"); // 要求fseek()成功
  return size;
}

void load_prog(const char *bin) {
  FILE *fp = fopen(bin, "r");
  Perror(fp != NULL, "Fail to open %s", bin); // 要求bin是一个可以成功打开的文件
  long size = fsize(fp);
  Assert(size < MSIZE, "Program size exceeds %d Bytes", MSIZE); // 要求程序大小不超过MSIZE字节
  int ret = fread(M, 1, MSIZE, fp);
  Assert(ret == size, "Fail to load the whole program"); // 要求完全读出程序的内容
  fclose(fp);
}
