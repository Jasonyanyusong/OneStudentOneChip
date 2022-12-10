// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_not.h for the primary calling header

#include "verilated.h"

#include "Vmy_not__Syms.h"
#include "Vmy_not___024root.h"

void Vmy_not___024root___ctor_var_reset(Vmy_not___024root* vlSelf);

Vmy_not___024root::Vmy_not___024root(Vmy_not__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_not___024root___ctor_var_reset(this);
}

void Vmy_not___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_not___024root::~Vmy_not___024root() {
}
