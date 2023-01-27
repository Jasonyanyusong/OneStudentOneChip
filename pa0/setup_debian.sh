echo "Yi Sheng Yi Xin Environment Configurator for Debian"
su
apt-get update
apt-get -y upgrade
exit

echo "Install packages for compiling Verilator/Iverilog"
su
apt-get install -y autoconf
apt-get install -y bison
apt-get install -y flex
apt-get install -y gperf
exit

echo "Install Yi Sheng Yi Xin required tools"
su
apt-get install -y build-essential
apt-get install -y man
apt-get install -y gcc-doc
apt-get install -y gdb
apt-get install -y git
apt-get install -y gh
apt-get install -y libreadline-dev
apt-get install -y libsdl2-dev
apt-get install -y llvm llvm-dev
apt-get install -y gtkwave
apt-get install -y vim
exit

echo "Fetch and Install Verilator (4.210)"
wget https://github.com/verilator/verilator/archive/refs/tags/v4.210.zip
unzip v4.210.zip
cd ~/verilator-4.210
autoconf
./configure
make
su
make install
exit
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
su
make install
exit
cd ~
rm v12_0.zip
rm -rf iverilog-12_0