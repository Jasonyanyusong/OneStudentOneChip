echo "Yi Sheng Yi Xin Environment Configurator for Kali Linux"
sudo apt-get update
sudo apt-get -y upgrade

echo "Install packages for compiling Verilator/Iverilog"
sudo apt-get install -y autoconf
sudo apt-get install -y bison
sudo apt-get install -y flex
sudo apt-get install -y gperf

echo "Install Yi Sheng Yi Xin required tools"
sudo apt-get install -y build-essential
sudo apt-get install -y man
sudo apt-get install -y gcc-doc
sudo apt-get install -y gdb
sudo apt-get install -y git
sudo apt-get install -y gh
sudo apt-get install -y libreadline-dev
sudo apt-get install -y libsdl2-dev
sudo apt-get install -y llvm llvm-dev
sudo apt-get install -y gtkwave
sudo apt-get install -y vim

echo "Fetch and Install Verilator (4.210)"
wget https://github.com/verilator/verilator/archive/refs/tags/v4.210.zip
unzip v4.210.zip
cd ~/verilator-4.210
autoconf
./configure
make
sudo make install
cd ~
rm v4.210.zip
rm -rf verilator-4.210

echo "Fetch and Install IVerilog (12.0)"
wget https://github.com/steveicarus/iverilog/archive/refs/tags/v12_0.zip
unzip v12_0.zip
cd ~/iverilog-12_0
sh autoconf.sh
./configure
make
sudo make install
cd ~
rm v12_0.zip
rm -rf iverilog-12_0
