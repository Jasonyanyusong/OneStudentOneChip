// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicLeftShiftRegister_PosEdge_2Bit.h for the primary calling header

#include "VLogicLeftShiftRegister_PosEdge_2Bit___024root.h"
#include "VLogicLeftShiftRegister_PosEdge_2Bit__Syms.h"

//==========


void VLogicLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(VLogicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf);

VLogicLeftShiftRegister_PosEdge_2Bit___024root::VLogicLeftShiftRegister_PosEdge_2Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VLogicLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(this);
}

void VLogicLeftShiftRegister_PosEdge_2Bit___024root::__Vconfigure(VLogicLeftShiftRegister_PosEdge_2Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VLogicLeftShiftRegister_PosEdge_2Bit___024root::~VLogicLeftShiftRegister_PosEdge_2Bit___024root() {
}

void VLogicLeftShiftRegister_PosEdge_2Bit___024root___eval_initial(VLogicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_2Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VLogicLeftShiftRegister_PosEdge_2Bit___024root___eval_settle(VLogicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_2Bit___024root___eval_settle\n"); );
}

void VLogicLeftShiftRegister_PosEdge_2Bit___024root___final(VLogicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_2Bit___024root___final\n"); );
}

void VLogicLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset(VLogicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_2Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->D = VL_RAND_RESET_I(2);
    vlSelf->Q = VL_RAND_RESET_I(2);
}
