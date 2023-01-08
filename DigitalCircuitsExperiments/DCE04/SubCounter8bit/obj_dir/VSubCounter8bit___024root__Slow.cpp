// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter8bit.h for the primary calling header

#include "VSubCounter8bit___024root.h"
#include "VSubCounter8bit__Syms.h"

//==========


void VSubCounter8bit___024root___ctor_var_reset(VSubCounter8bit___024root* vlSelf);

VSubCounter8bit___024root::VSubCounter8bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSubCounter8bit___024root___ctor_var_reset(this);
}

void VSubCounter8bit___024root::__Vconfigure(VSubCounter8bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSubCounter8bit___024root::~VSubCounter8bit___024root() {
}

void VSubCounter8bit___024root___eval_initial(VSubCounter8bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter8bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VSubCounter8bit___024root___eval_settle(VSubCounter8bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter8bit___024root___eval_settle\n"); );
}

void VSubCounter8bit___024root___final(VSubCounter8bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter8bit___024root___final\n"); );
}

void VSubCounter8bit___024root___ctor_var_reset(VSubCounter8bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter8bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(8);
}
