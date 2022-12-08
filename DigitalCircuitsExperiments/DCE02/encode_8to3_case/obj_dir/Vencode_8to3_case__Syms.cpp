// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vencode_8to3_case__Syms.h"
#include "Vencode_8to3_case.h"
#include "Vencode_8to3_case___024root.h"

// FUNCTIONS
Vencode_8to3_case__Syms::~Vencode_8to3_case__Syms()
{
}

Vencode_8to3_case__Syms::Vencode_8to3_case__Syms(VerilatedContext* contextp, const char* namep, Vencode_8to3_case* modelp)
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
