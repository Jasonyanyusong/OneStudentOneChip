// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_or.h for the primary calling header

#include "verilated.h"

#include "Vmy_or__Syms.h"
#include "Vmy_or___024root.h"

void Vmy_or___024root___ctor_var_reset(Vmy_or___024root* vlSelf);

Vmy_or___024root::Vmy_or___024root(Vmy_or__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_or___024root___ctor_var_reset(this);
}

void Vmy_or___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_or___024root::~Vmy_or___024root() {
}
