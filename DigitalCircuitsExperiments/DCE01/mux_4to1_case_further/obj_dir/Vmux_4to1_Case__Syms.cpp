// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmux_4to1_Case__Syms.h"
#include "Vmux_4to1_Case.h"
#include "Vmux_4to1_Case___024root.h"

// FUNCTIONS
Vmux_4to1_Case__Syms::~Vmux_4to1_Case__Syms()
{
}

Vmux_4to1_Case__Syms::Vmux_4to1_Case__Syms(VerilatedContext* contextp, const char* namep, Vmux_4to1_Case* modelp)
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
