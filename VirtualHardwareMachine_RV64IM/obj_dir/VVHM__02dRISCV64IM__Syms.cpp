// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VVHM__02dRISCV64IM__Syms.h"
#include "VVHM__02dRISCV64IM.h"
#include "VVHM__02dRISCV64IM___024root.h"

// FUNCTIONS
VVHM__02dRISCV64IM__Syms::~VVHM__02dRISCV64IM__Syms()
{
}

VVHM__02dRISCV64IM__Syms::VVHM__02dRISCV64IM__Syms(VerilatedContext* contextp, const char* namep, VVHM__02dRISCV64IM* modelp)
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
