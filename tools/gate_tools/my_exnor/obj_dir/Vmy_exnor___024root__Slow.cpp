// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_exnor.h for the primary calling header

#include "verilated.h"

#include "Vmy_exnor__Syms.h"
#include "Vmy_exnor___024root.h"

void Vmy_exnor___024root___ctor_var_reset(Vmy_exnor___024root* vlSelf);

Vmy_exnor___024root::Vmy_exnor___024root(Vmy_exnor__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_exnor___024root___ctor_var_reset(this);
}

void Vmy_exnor___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_exnor___024root::~Vmy_exnor___024root() {
}
