// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter2bit.h for the primary calling header

#include "VSubCounter2bit___024root.h"
#include "VSubCounter2bit__Syms.h"

//==========


void VSubCounter2bit___024root___ctor_var_reset(VSubCounter2bit___024root* vlSelf);

VSubCounter2bit___024root::VSubCounter2bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSubCounter2bit___024root___ctor_var_reset(this);
}

void VSubCounter2bit___024root::__Vconfigure(VSubCounter2bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSubCounter2bit___024root::~VSubCounter2bit___024root() {
}

void VSubCounter2bit___024root___eval_initial(VSubCounter2bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter2bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter2bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VSubCounter2bit___024root___eval_settle(VSubCounter2bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter2bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter2bit___024root___eval_settle\n"); );
}

void VSubCounter2bit___024root___final(VSubCounter2bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter2bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter2bit___024root___final\n"); );
}

void VSubCounter2bit___024root___ctor_var_reset(VSubCounter2bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter2bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter2bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(2);
}
