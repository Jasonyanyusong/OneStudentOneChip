// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_nor.h for the primary calling header

#include "verilated.h"

#include "Vmy_nor__Syms.h"
#include "Vmy_nor___024root.h"

void Vmy_nor___024root___ctor_var_reset(Vmy_nor___024root* vlSelf);

Vmy_nor___024root::Vmy_nor___024root(Vmy_nor__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_nor___024root___ctor_var_reset(this);
}

void Vmy_nor___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_nor___024root::~Vmy_nor___024root() {
}
