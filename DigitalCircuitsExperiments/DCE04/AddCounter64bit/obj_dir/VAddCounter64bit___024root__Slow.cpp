// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter64bit.h for the primary calling header

#include "VAddCounter64bit___024root.h"
#include "VAddCounter64bit__Syms.h"

//==========


void VAddCounter64bit___024root___ctor_var_reset(VAddCounter64bit___024root* vlSelf);

VAddCounter64bit___024root::VAddCounter64bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddCounter64bit___024root___ctor_var_reset(this);
}

void VAddCounter64bit___024root::__Vconfigure(VAddCounter64bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddCounter64bit___024root::~VAddCounter64bit___024root() {
}

void VAddCounter64bit___024root___eval_initial(VAddCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter64bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VAddCounter64bit___024root___eval_settle(VAddCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter64bit___024root___eval_settle\n"); );
}

void VAddCounter64bit___024root___final(VAddCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter64bit___024root___final\n"); );
}

void VAddCounter64bit___024root___ctor_var_reset(VAddCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter64bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_Q(64);
}
