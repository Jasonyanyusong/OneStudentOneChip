// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArithmeticShifter_Right_4Bit.h for the primary calling header

#include "VArithmeticShifter_Right_4Bit___024root.h"
#include "VArithmeticShifter_Right_4Bit__Syms.h"

//==========


void VArithmeticShifter_Right_4Bit___024root___ctor_var_reset(VArithmeticShifter_Right_4Bit___024root* vlSelf);

VArithmeticShifter_Right_4Bit___024root::VArithmeticShifter_Right_4Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VArithmeticShifter_Right_4Bit___024root___ctor_var_reset(this);
}

void VArithmeticShifter_Right_4Bit___024root::__Vconfigure(VArithmeticShifter_Right_4Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VArithmeticShifter_Right_4Bit___024root::~VArithmeticShifter_Right_4Bit___024root() {
}

void VArithmeticShifter_Right_4Bit___024root___eval_initial(VArithmeticShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticShifter_Right_4Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VArithmeticShifter_Right_4Bit___024root___eval_settle(VArithmeticShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticShifter_Right_4Bit___024root___eval_settle\n"); );
}

void VArithmeticShifter_Right_4Bit___024root___final(VArithmeticShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticShifter_Right_4Bit___024root___final\n"); );
}

void VArithmeticShifter_Right_4Bit___024root___ctor_var_reset(VArithmeticShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticShifter_Right_4Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->clr = VL_RAND_RESET_I(1);
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(4);
    vlSelf->outp = VL_RAND_RESET_I(4);
}
