// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicShifter_Left_4Bit.h for the primary calling header

#include "VLogicShifter_Left_4Bit___024root.h"
#include "VLogicShifter_Left_4Bit__Syms.h"

//==========


void VLogicShifter_Left_4Bit___024root___ctor_var_reset(VLogicShifter_Left_4Bit___024root* vlSelf);

VLogicShifter_Left_4Bit___024root::VLogicShifter_Left_4Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VLogicShifter_Left_4Bit___024root___ctor_var_reset(this);
}

void VLogicShifter_Left_4Bit___024root::__Vconfigure(VLogicShifter_Left_4Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VLogicShifter_Left_4Bit___024root::~VLogicShifter_Left_4Bit___024root() {
}

void VLogicShifter_Left_4Bit___024root___eval_initial(VLogicShifter_Left_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Left_4Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VLogicShifter_Left_4Bit___024root___eval_settle(VLogicShifter_Left_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Left_4Bit___024root___eval_settle\n"); );
}

void VLogicShifter_Left_4Bit___024root___final(VLogicShifter_Left_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Left_4Bit___024root___final\n"); );
}

void VLogicShifter_Left_4Bit___024root___ctor_var_reset(VLogicShifter_Left_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Left_4Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(4);
    vlSelf->outp = VL_RAND_RESET_I(4);
}
