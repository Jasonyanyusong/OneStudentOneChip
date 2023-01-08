// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister16.h for the primary calling header

#include "Vregister16___024root.h"
#include "Vregister16__Syms.h"

//==========


void Vregister16___024root___ctor_var_reset(Vregister16___024root* vlSelf);

Vregister16___024root::Vregister16___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vregister16___024root___ctor_var_reset(this);
}

void Vregister16___024root::__Vconfigure(Vregister16__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vregister16___024root::~Vregister16___024root() {
}

void Vregister16___024root___eval_initial(Vregister16___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister16___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vregister16___024root___eval_settle(Vregister16___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister16___024root___eval_settle\n"); );
}

void Vregister16___024root___final(Vregister16___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister16___024root___final\n"); );
}

void Vregister16___024root___ctor_var_reset(Vregister16___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister16___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(16);
    vlSelf->q = VL_RAND_RESET_I(16);
}
