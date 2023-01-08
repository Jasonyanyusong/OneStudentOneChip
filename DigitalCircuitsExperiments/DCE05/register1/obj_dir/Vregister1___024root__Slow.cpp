// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister1.h for the primary calling header

#include "Vregister1___024root.h"
#include "Vregister1__Syms.h"

//==========


void Vregister1___024root___ctor_var_reset(Vregister1___024root* vlSelf);

Vregister1___024root::Vregister1___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vregister1___024root___ctor_var_reset(this);
}

void Vregister1___024root::__Vconfigure(Vregister1__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vregister1___024root::~Vregister1___024root() {
}

void Vregister1___024root___eval_initial(Vregister1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister1___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vregister1___024root___eval_settle(Vregister1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister1___024root___eval_settle\n"); );
}

void Vregister1___024root___final(Vregister1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister1___024root___final\n"); );
}

void Vregister1___024root___ctor_var_reset(Vregister1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister1___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(1);
    vlSelf->q = VL_RAND_RESET_I(1);
}
