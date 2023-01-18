// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArithmeticRightShiftRegister_NegEdge_64Bit.h for the primary calling header

#include "VArithmeticRightShiftRegister_NegEdge_64Bit___024root.h"
#include "VArithmeticRightShiftRegister_NegEdge_64Bit__Syms.h"

//==========


void VArithmeticRightShiftRegister_NegEdge_64Bit___024root___ctor_var_reset(VArithmeticRightShiftRegister_NegEdge_64Bit___024root* vlSelf);

VArithmeticRightShiftRegister_NegEdge_64Bit___024root::VArithmeticRightShiftRegister_NegEdge_64Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VArithmeticRightShiftRegister_NegEdge_64Bit___024root___ctor_var_reset(this);
}

void VArithmeticRightShiftRegister_NegEdge_64Bit___024root::__Vconfigure(VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VArithmeticRightShiftRegister_NegEdge_64Bit___024root::~VArithmeticRightShiftRegister_NegEdge_64Bit___024root() {
}

void VArithmeticRightShiftRegister_NegEdge_64Bit___024root___eval_initial(VArithmeticRightShiftRegister_NegEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_64Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VArithmeticRightShiftRegister_NegEdge_64Bit___024root___eval_settle(VArithmeticRightShiftRegister_NegEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_64Bit___024root___eval_settle\n"); );
}

void VArithmeticRightShiftRegister_NegEdge_64Bit___024root___final(VArithmeticRightShiftRegister_NegEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_64Bit___024root___final\n"); );
}

void VArithmeticRightShiftRegister_NegEdge_64Bit___024root___ctor_var_reset(VArithmeticRightShiftRegister_NegEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_64Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->D = VL_RAND_RESET_Q(64);
    vlSelf->Q = VL_RAND_RESET_Q(64);
}
