sudo apt-get install -y build-essential
sudo apt-get install -y man
sudo apt-get install -y gcc-doc
sudo apt-get install -y gdb
sudo apt-get install -y git
sudo apt-get install -y libreadline-dev
sudo apt-get install -y libsdl2-dev
sudo apt-get install -y llvm llvm-dev
sudo apt-get install -y vim

sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev libusb-1.0-0-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev device-tree-compiler pkg-config libexpat-dev
git clone --recursiv https://github.com/riscv/riscv-tools.git
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain

cd riscv-binutils-gdb
cp -a * ../riscv-gdb
cp -a * ../riscv-binutils

export RISCV="/home/{ysyx}/riscv/riscv-gnu-toolchain"
export PATH=$PATH:$RISCV/bin
source ~/.bashrc

./configure --prefix=$RISCV
sudo apt-get install libsysfs-dev
sudo apt-get install pkg-config
sudo apt-get install device-tree-compiler