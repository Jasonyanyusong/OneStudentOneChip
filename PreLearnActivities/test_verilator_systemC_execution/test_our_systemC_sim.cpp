#include "Vtest_our_systemC.h"
int sc_main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    sc_clock clk {"clk", 10, SC_NS, 0.5, 3, SC_NS, true};
    Vtest_our_systemC* top = new Vtest_our_systemC("top")
    top -> clk (clk);
    while (!Verilated::gotFinish())
    {
        sc_start(1, SC_NS);
    }
    delete top;
    return 0;
}