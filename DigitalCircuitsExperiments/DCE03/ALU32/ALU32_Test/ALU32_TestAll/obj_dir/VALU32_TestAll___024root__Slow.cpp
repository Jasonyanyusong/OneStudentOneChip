// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_TestAll.h for the primary calling header

#include "verilated.h"

#include "VALU32_TestAll__Syms.h"
#include "VALU32_TestAll___024root.h"

void VALU32_TestAll___024root___ctor_var_reset(VALU32_TestAll___024root* vlSelf);

VALU32_TestAll___024root::VALU32_TestAll___024root(VALU32_TestAll__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VALU32_TestAll___024root___ctor_var_reset(this);
}

void VALU32_TestAll___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VALU32_TestAll___024root::~VALU32_TestAll___024root() {
}
