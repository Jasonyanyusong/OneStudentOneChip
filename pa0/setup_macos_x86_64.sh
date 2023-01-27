echo "autoinstaller for macOS with Intel Chip"
echo "The default name of user is yishengyixin, find and replace before execution, or the script will fail"
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"

source /Users/yishengyixin/.zprofile
git config --global --add safe.directory /opt/homebrew/Library/Taps/homebrew/homebrew-core
git config --global --add safe.directory /opt/homebrew/Library/Taps/homebrew/homebrew-cask

brew install wget
brew install autoconf
brew install gtkwave

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
