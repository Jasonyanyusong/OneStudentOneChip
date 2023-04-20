cd ..
cp ALU.v verilator-test
cd verilator-test
cp ALU.v AddTest
cp ALU.v AndTest
cp ALU.v BeqTest
cp ALU.v CmpTest
cp ALU.v NotTest
cp ALU.v OrTest
cp ALU.v SLLTest
cp ALU.v SRATest
cp ALU.v SRLTest
cp ALU.v SubTest
cp ALU.v XorTest

cd AddTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd AndTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd BeqTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd CmpTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd NotTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd OrTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd SLLTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd SRATest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd SRLTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd SubTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..

cd XorTest
verilator --cc --exe --build --trace --debug ALU.v testALU.cpp
cd obj_dir
./VALU
cd ../..
