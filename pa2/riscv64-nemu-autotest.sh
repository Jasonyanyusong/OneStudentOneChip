echo "THIS IS SCRIPT FOR TESTING RISCV64 NEMU USING AM-KERNELS"
cd $AM_KERNELS_HOME/tests/cpu-tests
pwd

echo "TESTING add"
make ARCH=riscv64-nemu ALL=add run
make clean
cd $NEMU_HOME
make clean

echo "TESTING add-longlong"
make ARCH=riscv64-nemu ALL=add-longlong run
make clean
cd $NEMU_HOME
make clean

echo "TESTING bit"
make ARCH=riscv64-nemu ALL=bit run
make clean
cd $NEMU_HOME
make clean

echo "TESTING bubble-sort"
make ARCH=riscv64-nemu ALL=bubble-sort run
make clean
cd $NEMU_HOME
make clean

echo "TESTING div"
make ARCH=riscv64-nemu ALL=div run
make clean
cd $NEMU_HOME
make clean

echo "TESTING dummy"
make ARCH=riscv64-nemu ALL=dummy run
make clean
cd $NEMU_HOME
make clean

echo "TESTING fact"
make ARCH=riscv64-nemu ALL=fact run
make clean
cd $NEMU_HOME
make clean

echo "TESTING fib"
make ARCH=riscv64-nemu ALL=fib run
make clean
cd $NEMU_HOME
make clean

echo "TESTING goldbach"
make ARCH=riscv64-nemu ALL=goldbach run
make clean
cd $NEMU_HOME
make clean

echo "TESTING hello-srt"
make ARCH=riscv64-nemu ALL=hello-str run
make clean
cd $NEMU_HOME
make clean

echo "TESTING leap-year"
make ARCH=riscv64-nemu ALL=leap-year run
make clean
cd $NEMU_HOME
make clean

echo "TESTING load-store"
make ARCH=riscv64-nemu ALL=load-store run
make clean
cd $NEMU_HOME
make clean

echo "TESTING matrix-mul"
make ARCH=riscv64-nemu ALL=matrix-mul run
make clean
cd $NEMU_HOME
make clean

echo "TESTING max"
make ARCH=riscv64-nemu ALL=max run
make clean
cd $NEMU_HOME
make clean

echo "TESTING min3"
make ARCH=riscv64-nemu ALL=min3 run
make clean
cd $NEMU_HOME
make clean

echo "TESTING mov-c"
make ARCH=riscv64-nemu ALL=mov-c run
make clean
cd $NEMU_HOME
make clean

echo "TESTING movsx"
make ARCH=riscv64-nemu ALL=movsx run
make clean
cd $NEMU_HOME
make clean

echo "TESTING mul-longlong"
make ARCH=riscv64-nemu ALL=mul-longlong run
make clean
cd $NEMU_HOME
make clean

echo "TESTING pascal"
make ARCH=riscv64-nemu ALL=pascal run
make clean
cd $NEMU_HOME
make clean

echo "TESTING prime"
make ARCH=riscv64-nemu ALL=prime run
make clean
cd $NEMU_HOME
make clean

echo "TESTING recursion"
make ARCH=riscv64-nemu ALL=recursion run
make clean
cd $NEMU_HOME
make clean

echo "TESTING selection-sort"
make ARCH=riscv64-nemu ALL=selection-sort run
make clean
cd $NEMU_HOME
make clean

echo "TESTING shift"
make ARCH=riscv64-nemu ALL=shift run
make clean
cd $NEMU_HOME
make clean

echo "TESTING shuixianhua"
make ARCH=riscv64-nemu ALL=shuixianhua run
make clean
cd $NEMU_HOME
make clean

echo "TESTING string"
make ARCH=riscv64-nemu ALL=string run
make clean
cd $NEMU_HOME
make clean

echo "TESTING sub-longlong"
make ARCH=riscv64-nemu ALL=sub-longlong run
make clean
cd $NEMU_HOME
make clean

echo "TESTING sum"
make ARCH=riscv64-nemu ALL=sum run
make clean
cd $NEMU_HOME
make clean

echo "TESTING switch"
make ARCH=riscv64-nemu ALL=switch run
make clean
cd $NEMU_HOME
make clean

echo "TESTING to-lower-case"
make ARCH=riscv64-nemu ALL=to-lower-case run
make clean
cd $NEMU_HOME
make clean

echo "TESTING unalign"
make ARCH=riscv64-nemu ALL=unalign run
make clean
cd $NEMU_HOME
make clean