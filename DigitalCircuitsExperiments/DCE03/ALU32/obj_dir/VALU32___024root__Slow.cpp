// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32.h for the primary calling header

#include "verilated.h"

#include "VALU32__Syms.h"
#include "VALU32___024root.h"

void VALU32___024root___ctor_var_reset(VALU32___024root* vlSelf);

VALU32___024root::VALU32___024root(VALU32__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VALU32___024root___ctor_var_reset(this);
}

void VALU32___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VALU32___024root::~VALU32___024root() {
}
