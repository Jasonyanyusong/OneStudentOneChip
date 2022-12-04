// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_our_systemC.h for the primary calling header

#include "verilated.h"

#include "Vtest_our_systemC__Syms.h"
#include "Vtest_our_systemC___024root.h"

void Vtest_our_systemC___024root___ctor_var_reset(Vtest_our_systemC___024root* vlSelf);

Vtest_our_systemC___024root::Vtest_our_systemC___024root(Vtest_our_systemC__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , clk("clk")
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtest_our_systemC___024root___ctor_var_reset(this);
}

void Vtest_our_systemC___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtest_our_systemC___024root::~Vtest_our_systemC___024root() {
}
