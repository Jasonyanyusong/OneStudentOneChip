// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_nand.h for the primary calling header

#include "verilated.h"

#include "Vmy_nand__Syms.h"
#include "Vmy_nand___024root.h"

void Vmy_nand___024root___ctor_var_reset(Vmy_nand___024root* vlSelf);

Vmy_nand___024root::Vmy_nand___024root(Vmy_nand__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_nand___024root___ctor_var_reset(this);
}

void Vmy_nand___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_nand___024root::~Vmy_nand___024root() {
}
