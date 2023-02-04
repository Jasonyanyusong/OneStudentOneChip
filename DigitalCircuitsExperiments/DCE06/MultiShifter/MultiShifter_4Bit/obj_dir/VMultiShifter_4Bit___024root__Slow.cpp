// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiShifter_4Bit.h for the primary calling header

#include "VMultiShifter_4Bit___024root.h"
#include "VMultiShifter_4Bit__Syms.h"

//==========


void VMultiShifter_4Bit___024root___ctor_var_reset(VMultiShifter_4Bit___024root* vlSelf);

VMultiShifter_4Bit___024root::VMultiShifter_4Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VMultiShifter_4Bit___024root___ctor_var_reset(this);
}

void VMultiShifter_4Bit___024root::__Vconfigure(VMultiShifter_4Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VMultiShifter_4Bit___024root::~VMultiShifter_4Bit___024root() {
}

void VMultiShifter_4Bit___024root___eval_initial(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VMultiShifter_4Bit___024root___eval_settle(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___eval_settle\n"); );
}

void VMultiShifter_4Bit___024root___final(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___final\n"); );
}

void VMultiShifter_4Bit___024root___ctor_var_reset(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->sel = VL_RAND_RESET_I(3);
    vlSelf->inp = VL_RAND_RESET_I(4);
    vlSelf->outp = VL_RAND_RESET_I(4);
}
