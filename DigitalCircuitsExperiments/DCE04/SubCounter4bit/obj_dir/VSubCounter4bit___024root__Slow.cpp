// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter4bit.h for the primary calling header

#include "VSubCounter4bit___024root.h"
#include "VSubCounter4bit__Syms.h"

//==========


void VSubCounter4bit___024root___ctor_var_reset(VSubCounter4bit___024root* vlSelf);

VSubCounter4bit___024root::VSubCounter4bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSubCounter4bit___024root___ctor_var_reset(this);
}

void VSubCounter4bit___024root::__Vconfigure(VSubCounter4bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSubCounter4bit___024root::~VSubCounter4bit___024root() {
}

void VSubCounter4bit___024root___eval_initial(VSubCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter4bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VSubCounter4bit___024root___eval_settle(VSubCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter4bit___024root___eval_settle\n"); );
}

void VSubCounter4bit___024root___final(VSubCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter4bit___024root___final\n"); );
}

void VSubCounter4bit___024root___ctor_var_reset(VSubCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter4bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(4);
}
