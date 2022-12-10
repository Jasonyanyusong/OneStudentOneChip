// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_1bit_structure.h for the primary calling header

#include "verilated.h"

#include "Vadd_1bit_structure__Syms.h"
#include "Vadd_1bit_structure___024root.h"

void Vadd_1bit_structure___024root___ctor_var_reset(Vadd_1bit_structure___024root* vlSelf);

Vadd_1bit_structure___024root::Vadd_1bit_structure___024root(Vadd_1bit_structure__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd_1bit_structure___024root___ctor_var_reset(this);
}

void Vadd_1bit_structure___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vadd_1bit_structure___024root::~Vadd_1bit_structure___024root() {
}
