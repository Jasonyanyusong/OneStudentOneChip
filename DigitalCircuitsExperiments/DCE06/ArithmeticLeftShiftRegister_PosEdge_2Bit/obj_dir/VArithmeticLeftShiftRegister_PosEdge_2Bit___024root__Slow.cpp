// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArithmeticLeftShiftRegister_PosEdge_2Bit.h for the primary calling header

#include "VArithmeticLeftShiftRegister_PosEdge_2Bit___024root.h"
#include "VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms.h"

//==========


void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(VArithmeticLeftShiftRegister_PosEdge_2Bit___024root* vlSelf);

VArithmeticLeftShiftRegister_PosEdge_2Bit___024root::VArithmeticLeftShiftRegister_PosEdge_2Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(this);
}

void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root::__Vconfigure(VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VArithmeticLeftShiftRegister_PosEdge_2Bit___024root::~VArithmeticLeftShiftRegister_PosEdge_2Bit___024root() {
}

void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___eval_initial(VArithmeticLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___eval_settle(VArithmeticLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___eval_settle\n"); );
}

void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___final(VArithmeticLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___final\n"); );
}

void VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(VArithmeticLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->D = VL_RAND_RESET_I(2);
    vlSelf->Q = VL_RAND_RESET_I(2);
}
