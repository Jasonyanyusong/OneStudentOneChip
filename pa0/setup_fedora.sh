echo "Yi Sheng Yi Xin Environment Configurator for Ubuntu"
sudo yum update
sudo yum -y upgrade

echo "Install packages for compiling Verilator/Iverilog"
sudo yum install -y autoconf
sudo yum install -y bison
sudo yum install -y flex
sudo yum install -y gperf

echo "Install Yi Sheng Yi Xin required tools"
sudo yum install -y build-essential
sudo yum install -y man
sudo yum install -y gcc-doc
sudo yum install -y gdb
sudo yum install -y git
sudo yum install -y gh
sudo yum install -y libreadline-dev
sudo yum install -y libsdl2-dev
sudo yum install -y llvm llvm-dev
sudo yum install -y gtkwave
sudo yum install -y vim

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
