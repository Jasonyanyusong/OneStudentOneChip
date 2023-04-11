// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVHM__02dRISCV64IM.h for the primary calling header

#include "verilated.h"

#include "VVHM__02dRISCV64IM__Syms.h"
#include "VVHM__02dRISCV64IM___024root.h"

void VVHM__02dRISCV64IM___024root___ctor_var_reset(VVHM__02dRISCV64IM___024root* vlSelf);

VVHM__02dRISCV64IM___024root::VVHM__02dRISCV64IM___024root(VVHM__02dRISCV64IM__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VVHM__02dRISCV64IM___024root___ctor_var_reset(this);
}

void VVHM__02dRISCV64IM___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VVHM__02dRISCV64IM___024root::~VVHM__02dRISCV64IM___024root() {
}
