# 变量
BIN = yemu
USER_BIN = hello.bin
RV_CFLAGS = -march=rv64g -ffreestanding -nostdlib -static -Wl,-Ttext=0x0 -O2

SRCS = $(shell ls *.c)  # 将shell命令的运行结果赋值给变量
OBJS = $(SRCS:.c=.o)    # 字符串处理, SRCS变量中的.c替换成.o
CC   = gcc

# 规则
prog/hello.elf: prog/hello.c
	riscv64-linux-gnu-gcc $(RV_CFLAGS) -o $@ $^  # 自动变量

$(USER_BIN): prog/hello.elf
	llvm-objcopy -j .text -O binary $^ $@

$(BIN): $(OBJS)  # 隐含规则

run-yemu: $(BIN) $(USER_BIN)  # 此规则并不生成目标run-yemu
	./$(BIN) $(USER_BIN)

.PHONY: run-yemu clean   # 定义伪目标
clean:  # 用于清除编译结果
	-@rm $(OBJS) $(BIN) prog/hello.elf $(USER_BIN) 2> /dev/null
