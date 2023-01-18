// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArithmeticRightShiftRegister_PosEdge_128Bit.h for the primary calling header

#include "VArithmeticRightShiftRegister_PosEdge_128Bit___024root.h"
#include "VArithmeticRightShiftRegister_PosEdge_128Bit__Syms.h"

//==========


void VArithmeticRightShiftRegister_PosEdge_128Bit___024root___ctor_var_reset(VArithmeticRightShiftRegister_PosEdge_128Bit___024root* vlSelf);

VArithmeticRightShiftRegister_PosEdge_128Bit___024root::VArithmeticRightShiftRegister_PosEdge_128Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VArithmeticRightShiftRegister_PosEdge_128Bit___024root___ctor_var_reset(this);
}

void VArithmeticRightShiftRegister_PosEdge_128Bit___024root::__Vconfigure(VArithmeticRightShiftRegister_PosEdge_128Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VArithmeticRightShiftRegister_PosEdge_128Bit___024root::~VArithmeticRightShiftRegister_PosEdge_128Bit___024root() {
}

void VArithmeticRightShiftRegister_PosEdge_128Bit___024root___eval_initial(VArithmeticRightShiftRegister_PosEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_PosEdge_128Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VArithmeticRightShiftRegister_PosEdge_128Bit___024root___eval_settle(VArithmeticRightShiftRegister_PosEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_PosEdge_128Bit___024root___eval_settle\n"); );
}

void VArithmeticRightShiftRegister_PosEdge_128Bit___024root___final(VArithmeticRightShiftRegister_PosEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_PosEdge_128Bit___024root___final\n"); );
}

void VArithmeticRightShiftRegister_PosEdge_128Bit___024root___ctor_var_reset(VArithmeticRightShiftRegister_PosEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_PosEdge_128Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->D);
    VL_RAND_RESET_W(128, vlSelf->Q);
}
