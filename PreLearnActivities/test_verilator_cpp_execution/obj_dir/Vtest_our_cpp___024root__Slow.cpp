// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_our_cpp.h for the primary calling header

#include "verilated.h"

#include "Vtest_our_cpp__Syms.h"
#include "Vtest_our_cpp___024root.h"

void Vtest_our_cpp___024root___ctor_var_reset(Vtest_our_cpp___024root* vlSelf);

Vtest_our_cpp___024root::Vtest_our_cpp___024root(Vtest_our_cpp__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtest_our_cpp___024root___ctor_var_reset(this);
}

void Vtest_our_cpp___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtest_our_cpp___024root::~Vtest_our_cpp___024root() {
}
