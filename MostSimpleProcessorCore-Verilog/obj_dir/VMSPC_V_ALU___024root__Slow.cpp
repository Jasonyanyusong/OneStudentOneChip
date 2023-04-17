// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMSPC_V_ALU.h for the primary calling header

#include "verilated.h"

#include "VMSPC_V_ALU__Syms.h"
#include "VMSPC_V_ALU___024root.h"

void VMSPC_V_ALU___024root___ctor_var_reset(VMSPC_V_ALU___024root* vlSelf);

VMSPC_V_ALU___024root::VMSPC_V_ALU___024root(VMSPC_V_ALU__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VMSPC_V_ALU___024root___ctor_var_reset(this);
}

void VMSPC_V_ALU___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VMSPC_V_ALU___024root::~VMSPC_V_ALU___024root() {
}
