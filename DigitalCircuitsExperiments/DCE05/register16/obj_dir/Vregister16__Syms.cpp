// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vregister16__Syms.h"
#include "Vregister16.h"
#include "Vregister16___024root.h"

// FUNCTIONS
Vregister16__Syms::~Vregister16__Syms()
{
}

Vregister16__Syms::Vregister16__Syms(VerilatedContext* contextp, const char* namep,Vregister16* modelp)
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
