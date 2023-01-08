// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter16bit.h for the primary calling header

#include "VAddCounter16bit___024root.h"
#include "VAddCounter16bit__Syms.h"

//==========


void VAddCounter16bit___024root___ctor_var_reset(VAddCounter16bit___024root* vlSelf);

VAddCounter16bit___024root::VAddCounter16bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddCounter16bit___024root___ctor_var_reset(this);
}

void VAddCounter16bit___024root::__Vconfigure(VAddCounter16bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddCounter16bit___024root::~VAddCounter16bit___024root() {
}

void VAddCounter16bit___024root___eval_initial(VAddCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter16bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VAddCounter16bit___024root___eval_settle(VAddCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter16bit___024root___eval_settle\n"); );
}

void VAddCounter16bit___024root___final(VAddCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter16bit___024root___final\n"); );
}

void VAddCounter16bit___024root___ctor_var_reset(VAddCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter16bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(16);
}
