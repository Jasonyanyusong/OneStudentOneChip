// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicLeftShiftRegister_NegEdge_128Bit.h for the primary calling header

#include "VLogicLeftShiftRegister_NegEdge_128Bit___024root.h"
#include "VLogicLeftShiftRegister_NegEdge_128Bit__Syms.h"

//==========


void VLogicLeftShiftRegister_NegEdge_128Bit___024root___ctor_var_reset(VLogicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf);

VLogicLeftShiftRegister_NegEdge_128Bit___024root::VLogicLeftShiftRegister_NegEdge_128Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VLogicLeftShiftRegister_NegEdge_128Bit___024root___ctor_var_reset(this);
}

void VLogicLeftShiftRegister_NegEdge_128Bit___024root::__Vconfigure(VLogicLeftShiftRegister_NegEdge_128Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VLogicLeftShiftRegister_NegEdge_128Bit___024root::~VLogicLeftShiftRegister_NegEdge_128Bit___024root() {
}

void VLogicLeftShiftRegister_NegEdge_128Bit___024root___eval_initial(VLogicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_NegEdge_128Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VLogicLeftShiftRegister_NegEdge_128Bit___024root___eval_settle(VLogicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_NegEdge_128Bit___024root___eval_settle\n"); );
}

void VLogicLeftShiftRegister_NegEdge_128Bit___024root___final(VLogicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_NegEdge_128Bit___024root___final\n"); );
}

void VLogicLeftShiftRegister_NegEdge_128Bit___024root___ctor_var_reset(VLogicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_NegEdge_128Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->D);
    VL_RAND_RESET_W(128, vlSelf->Q);
}
