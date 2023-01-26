// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vps2_keyboard_sim_fn__Syms.h"
#include "Vps2_keyboard_sim_fn.h"
#include "Vps2_keyboard_sim_fn___024root.h"

// FUNCTIONS
Vps2_keyboard_sim_fn__Syms::~Vps2_keyboard_sim_fn__Syms()
{
}

Vps2_keyboard_sim_fn__Syms::Vps2_keyboard_sim_fn__Syms(VerilatedContext* contextp, const char* namep,Vps2_keyboard_sim_fn* modelp)
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
