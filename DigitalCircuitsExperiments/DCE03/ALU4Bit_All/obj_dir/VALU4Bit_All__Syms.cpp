// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VALU4Bit_All__Syms.h"
#include "VALU4Bit_All.h"
#include "VALU4Bit_All___024root.h"

// FUNCTIONS
VALU4Bit_All__Syms::~VALU4Bit_All__Syms()
{
}

VALU4Bit_All__Syms::VALU4Bit_All__Syms(VerilatedContext* contextp, const char* namep,VALU4Bit_All* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
