// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmux_2to1_Structure__Syms.h"
#include "Vmux_2to1_Structure.h"
#include "Vmux_2to1_Structure___024root.h"

// FUNCTIONS
Vmux_2to1_Structure__Syms::~Vmux_2to1_Structure__Syms()
{
}

Vmux_2to1_Structure__Syms::Vmux_2to1_Structure__Syms(VerilatedContext* contextp, const char* namep,Vmux_2to1_Structure* modelp)
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
