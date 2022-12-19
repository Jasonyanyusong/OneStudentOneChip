// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter.h for the primary calling header

#include "verilated.h"

#include "VSubCounter__Syms.h"
#include "VSubCounter___024root.h"

void VSubCounter___024root___ctor_var_reset(VSubCounter___024root* vlSelf);

VSubCounter___024root::VSubCounter___024root(VSubCounter__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSubCounter___024root___ctor_var_reset(this);
}

void VSubCounter___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VSubCounter___024root::~VSubCounter___024root() {
}
