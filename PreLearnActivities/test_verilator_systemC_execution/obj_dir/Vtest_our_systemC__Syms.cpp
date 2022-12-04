// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtest_our_systemC__Syms.h"
#include "Vtest_our_systemC.h"
#include "Vtest_our_systemC___024root.h"

// FUNCTIONS
Vtest_our_systemC__Syms::~Vtest_our_systemC__Syms()
{
}

Vtest_our_systemC__Syms::Vtest_our_systemC__Syms(VerilatedContext* contextp, const char* namep, Vtest_our_systemC* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
