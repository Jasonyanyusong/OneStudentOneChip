// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vencode_4to2_for__Syms.h"
#include "Vencode_4to2_for.h"
#include "Vencode_4to2_for___024root.h"

// FUNCTIONS
Vencode_4to2_for__Syms::~Vencode_4to2_for__Syms()
{
}

Vencode_4to2_for__Syms::Vencode_4to2_for__Syms(VerilatedContext* contextp, const char* namep, Vencode_4to2_for* modelp)
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
