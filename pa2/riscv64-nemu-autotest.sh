echo "THIS IS SCRIPT FOR TESTING RISCV64 NEMU USING AM-KERNELS"
cd $AM_KERNELS_HOME/tests/cpu-tests
pwd

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING add"
make ARCH=riscv64-nemu ALL=add run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING add-longlong"
make ARCH=riscv64-nemu ALL=add-longlong run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING bit"
make ARCH=riscv64-nemu ALL=bit run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING bubble-sort"
make ARCH=riscv64-nemu ALL=bubble-sort run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING div"
make ARCH=riscv64-nemu ALL=div run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING dummy"
make ARCH=riscv64-nemu ALL=dummy run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING fact"
make ARCH=riscv64-nemu ALL=fact run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING fib"
make ARCH=riscv64-nemu ALL=fib run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING goldbach"
make ARCH=riscv64-nemu ALL=goldbach run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING hello-str"
make ARCH=riscv64-nemu ALL=hello-str run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING leap-year"
make ARCH=riscv64-nemu ALL=leap-year run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING load-store"
make ARCH=riscv64-nemu ALL=load-store run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING matrix-mul"
make ARCH=riscv64-nemu ALL=matrix-mul run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING max"
make ARCH=riscv64-nemu ALL=max run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING min3"
make ARCH=riscv64-nemu ALL=min3 run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING mov-c"
make ARCH=riscv64-nemu ALL=mov-c run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING movsx"
make ARCH=riscv64-nemu ALL=movsx run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING mul-longlong"
make ARCH=riscv64-nemu ALL=mul-longlong run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING pascal"
make ARCH=riscv64-nemu ALL=pascal run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING prime"
make ARCH=riscv64-nemu ALL=prime run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING recursion"
make ARCH=riscv64-nemu ALL=recursion run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING selection-sort"
make ARCH=riscv64-nemu ALL=selection-sort run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING shift"
make ARCH=riscv64-nemu ALL=shift run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING shuixianhua"
make ARCH=riscv64-nemu ALL=shuixianhua run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING string"
make ARCH=riscv64-nemu ALL=string run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING sub-longlong"
make ARCH=riscv64-nemu ALL=sub-longlong run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING sum"
make ARCH=riscv64-nemu ALL=sum run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING switch"
make ARCH=riscv64-nemu ALL=switch run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING to-lower-case"
make ARCH=riscv64-nemu ALL=to-lower-case run

cd $AM_KERNELS_HOME/tests/cpu-tests
echo "TESTING unalign"
make ARCH=riscv64-nemu ALL=unalign run