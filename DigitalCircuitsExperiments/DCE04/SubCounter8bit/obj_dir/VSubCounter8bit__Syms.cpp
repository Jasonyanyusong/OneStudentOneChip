// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VSubCounter8bit__Syms.h"
#include "VSubCounter8bit.h"
#include "VSubCounter8bit___024root.h"

// FUNCTIONS
VSubCounter8bit__Syms::~VSubCounter8bit__Syms()
{
}

VSubCounter8bit__Syms::VSubCounter8bit__Syms(VerilatedContext* contextp, const char* namep,VSubCounter8bit* modelp)
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
