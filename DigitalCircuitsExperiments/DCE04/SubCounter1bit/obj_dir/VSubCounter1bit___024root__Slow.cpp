// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter1bit.h for the primary calling header

#include "VSubCounter1bit___024root.h"
#include "VSubCounter1bit__Syms.h"

//==========


void VSubCounter1bit___024root___ctor_var_reset(VSubCounter1bit___024root* vlSelf);

VSubCounter1bit___024root::VSubCounter1bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSubCounter1bit___024root___ctor_var_reset(this);
}

void VSubCounter1bit___024root::__Vconfigure(VSubCounter1bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSubCounter1bit___024root::~VSubCounter1bit___024root() {
}

void VSubCounter1bit___024root___eval_initial(VSubCounter1bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter1bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VSubCounter1bit___024root___eval_settle(VSubCounter1bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter1bit___024root___eval_settle\n"); );
}

void VSubCounter1bit___024root___final(VSubCounter1bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter1bit___024root___final\n"); );
}

void VSubCounter1bit___024root___ctor_var_reset(VSubCounter1bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter1bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(1);
}
