// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vvgactl_VGA_640x480__Syms.h"
#include "Vvgactl_VGA_640x480.h"
#include "Vvgactl_VGA_640x480___024root.h"

// FUNCTIONS
Vvgactl_VGA_640x480__Syms::~Vvgactl_VGA_640x480__Syms()
{
}

Vvgactl_VGA_640x480__Syms::Vvgactl_VGA_640x480__Syms(VerilatedContext* contextp, const char* namep,Vvgactl_VGA_640x480* modelp)
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
