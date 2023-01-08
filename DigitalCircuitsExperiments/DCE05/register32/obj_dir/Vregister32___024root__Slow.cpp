// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister32.h for the primary calling header

#include "Vregister32___024root.h"
#include "Vregister32__Syms.h"

//==========


void Vregister32___024root___ctor_var_reset(Vregister32___024root* vlSelf);

Vregister32___024root::Vregister32___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vregister32___024root___ctor_var_reset(this);
}

void Vregister32___024root::__Vconfigure(Vregister32__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vregister32___024root::~Vregister32___024root() {
}

void Vregister32___024root___eval_initial(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vregister32___024root___eval_settle(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___eval_settle\n"); );
}

void Vregister32___024root___final(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___final\n"); );
}

void Vregister32___024root___ctor_var_reset(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(32);
    vlSelf->q = VL_RAND_RESET_I(32);
}
