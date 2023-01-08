// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister64.h for the primary calling header

#include "Vregister64___024root.h"
#include "Vregister64__Syms.h"

//==========


void Vregister64___024root___ctor_var_reset(Vregister64___024root* vlSelf);

Vregister64___024root::Vregister64___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vregister64___024root___ctor_var_reset(this);
}

void Vregister64___024root::__Vconfigure(Vregister64__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vregister64___024root::~Vregister64___024root() {
}

void Vregister64___024root___eval_initial(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vregister64___024root___eval_settle(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___eval_settle\n"); );
}

void Vregister64___024root___final(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___final\n"); );
}

void Vregister64___024root___ctor_var_reset(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_Q(64);
    vlSelf->q = VL_RAND_RESET_Q(64);
}
