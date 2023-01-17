// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicRightShiftRegister_PosEdge_4Bit.h for the primary calling header

#include "VCyclicRightShiftRegister_PosEdge_4Bit___024root.h"
#include "VCyclicRightShiftRegister_PosEdge_4Bit__Syms.h"

//==========


void VCyclicRightShiftRegister_PosEdge_4Bit___024root___ctor_var_reset(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf);

VCyclicRightShiftRegister_PosEdge_4Bit___024root::VCyclicRightShiftRegister_PosEdge_4Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VCyclicRightShiftRegister_PosEdge_4Bit___024root___ctor_var_reset(this);
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root::__Vconfigure(VCyclicRightShiftRegister_PosEdge_4Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VCyclicRightShiftRegister_PosEdge_4Bit___024root::~VCyclicRightShiftRegister_PosEdge_4Bit___024root() {
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root___eval_initial(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_4Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root___eval_settle(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_4Bit___024root___eval_settle\n"); );
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root___final(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_4Bit___024root___final\n"); );
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root___ctor_var_reset(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_4Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->D = VL_RAND_RESET_I(4);
    vlSelf->Q = VL_RAND_RESET_I(4);
}
