// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter.h for the primary calling header

#include "VSubCounter___024root.h"
#include "VSubCounter__Syms.h"

//==========


void VSubCounter___024root___ctor_var_reset(VSubCounter___024root* vlSelf);

VSubCounter___024root::VSubCounter___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSubCounter___024root___ctor_var_reset(this);
}

void VSubCounter___024root::__Vconfigure(VSubCounter__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSubCounter___024root::~VSubCounter___024root() {
}

void VSubCounter___024root___eval_initial(VSubCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VSubCounter___024root___eval_settle(VSubCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter___024root___eval_settle\n"); );
}

void VSubCounter___024root___final(VSubCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter___024root___final\n"); );
}

void VSubCounter___024root___ctor_var_reset(VSubCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(3);
}
