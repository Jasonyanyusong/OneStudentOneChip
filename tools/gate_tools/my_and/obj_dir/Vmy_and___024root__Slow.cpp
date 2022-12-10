// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_and.h for the primary calling header

#include "verilated.h"

#include "Vmy_and__Syms.h"
#include "Vmy_and___024root.h"

void Vmy_and___024root___ctor_var_reset(Vmy_and___024root* vlSelf);

Vmy_and___024root::Vmy_and___024root(Vmy_and__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_and___024root___ctor_var_reset(this);
}

void Vmy_and___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_and___024root::~Vmy_and___024root() {
}
