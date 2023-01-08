// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister2.h for the primary calling header

#include "Vregister2___024root.h"
#include "Vregister2__Syms.h"

//==========


void Vregister2___024root___ctor_var_reset(Vregister2___024root* vlSelf);

Vregister2___024root::Vregister2___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vregister2___024root___ctor_var_reset(this);
}

void Vregister2___024root::__Vconfigure(Vregister2__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vregister2___024root::~Vregister2___024root() {
}

void Vregister2___024root___eval_initial(Vregister2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister2___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vregister2___024root___eval_settle(Vregister2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister2___024root___eval_settle\n"); );
}

void Vregister2___024root___final(Vregister2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister2___024root___final\n"); );
}

void Vregister2___024root___ctor_var_reset(Vregister2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister2___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(2);
    vlSelf->q = VL_RAND_RESET_I(2);
}
