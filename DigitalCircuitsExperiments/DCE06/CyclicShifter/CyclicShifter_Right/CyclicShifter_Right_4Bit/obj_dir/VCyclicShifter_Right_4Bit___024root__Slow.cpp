// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicShifter_Right_4Bit.h for the primary calling header

#include "VCyclicShifter_Right_4Bit___024root.h"
#include "VCyclicShifter_Right_4Bit__Syms.h"

//==========


void VCyclicShifter_Right_4Bit___024root___ctor_var_reset(VCyclicShifter_Right_4Bit___024root* vlSelf);

VCyclicShifter_Right_4Bit___024root::VCyclicShifter_Right_4Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VCyclicShifter_Right_4Bit___024root___ctor_var_reset(this);
}

void VCyclicShifter_Right_4Bit___024root::__Vconfigure(VCyclicShifter_Right_4Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VCyclicShifter_Right_4Bit___024root::~VCyclicShifter_Right_4Bit___024root() {
}

void VCyclicShifter_Right_4Bit___024root___eval_initial(VCyclicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicShifter_Right_4Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VCyclicShifter_Right_4Bit___024root___eval_settle(VCyclicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicShifter_Right_4Bit___024root___eval_settle\n"); );
}

void VCyclicShifter_Right_4Bit___024root___final(VCyclicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicShifter_Right_4Bit___024root___final\n"); );
}

void VCyclicShifter_Right_4Bit___024root___ctor_var_reset(VCyclicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicShifter_Right_4Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(4);
    vlSelf->outp = VL_RAND_RESET_I(4);
}
