// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VALU32_TestCase_1__Syms.h"
#include "VALU32_TestCase_1.h"
#include "VALU32_TestCase_1___024root.h"

// FUNCTIONS
VALU32_TestCase_1__Syms::~VALU32_TestCase_1__Syms()
{
}

VALU32_TestCase_1__Syms::VALU32_TestCase_1__Syms(VerilatedContext* contextp, const char* namep, VALU32_TestCase_1* modelp)
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
