// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdecode_5to32_for__Syms.h"
#include "Vdecode_5to32_for.h"
#include "Vdecode_5to32_for___024root.h"

// FUNCTIONS
Vdecode_5to32_for__Syms::~Vdecode_5to32_for__Syms()
{
}

Vdecode_5to32_for__Syms::Vdecode_5to32_for__Syms(VerilatedContext* contextp, const char* namep, Vdecode_5to32_for* modelp)
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
