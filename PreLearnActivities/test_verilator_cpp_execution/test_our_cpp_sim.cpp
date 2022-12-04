#include "Vtest_our_cpp.h"
#include "verilated.h"
int main(int argc, char** argv, char ** env)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp -> commandArgs(argc, argv);
    Vtest_our_cpp* top = new Vtest_our_cpp {contextp};
    while (!contextp -> gotFinish())
    {
        top -> eval();
    }
    delete top;
    delete contextp;
    return 0;
}