// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiFunctionShiftRegister_NegEdge_8Bit.h for the primary calling header

#include "VMultiFunctionShiftRegister_NegEdge_8Bit___024root.h"
#include "VMultiFunctionShiftRegister_NegEdge_8Bit__Syms.h"

//==========


void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___ctor_var_reset(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf);

VMultiFunctionShiftRegister_NegEdge_8Bit___024root::VMultiFunctionShiftRegister_NegEdge_8Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___ctor_var_reset(this);
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root::__Vconfigure(VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VMultiFunctionShiftRegister_NegEdge_8Bit___024root::~VMultiFunctionShiftRegister_NegEdge_8Bit___024root() {
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_initial(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_settle(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_settle\n"); );
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___final(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___final\n"); );
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___ctor_var_reset(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inp = VL_RAND_RESET_I(1);
    vlSelf->sel = VL_RAND_RESET_I(3);
    vlSelf->D = VL_RAND_RESET_I(8);
    vlSelf->Q = VL_RAND_RESET_I(8);
}
