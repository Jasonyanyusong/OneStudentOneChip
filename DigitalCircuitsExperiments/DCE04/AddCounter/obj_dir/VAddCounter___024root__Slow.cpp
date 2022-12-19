// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter.h for the primary calling header

#include "verilated.h"

#include "VAddCounter__Syms.h"
#include "VAddCounter___024root.h"

void VAddCounter___024root___ctor_var_reset(VAddCounter___024root* vlSelf);

VAddCounter___024root::VAddCounter___024root(VAddCounter__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VAddCounter___024root___ctor_var_reset(this);
}

void VAddCounter___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VAddCounter___024root::~VAddCounter___024root() {
}
