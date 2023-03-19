#include "yemu.h"

void load_prog(const char *bin);
void yemu_init();
void yemu_exec();

int main(int argc, char *argv[]) {
  Assert(argc >= 2, "Program is not given");  // 要求至少包含一个参数
  load_prog(argv[1]);
  yemu_init();
  yemu_exec();
  return 0;
}
