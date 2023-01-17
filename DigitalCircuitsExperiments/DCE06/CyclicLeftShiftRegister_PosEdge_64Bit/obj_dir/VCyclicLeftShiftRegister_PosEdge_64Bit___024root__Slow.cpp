// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicLeftShiftRegister_PosEdge_64Bit.h for the primary calling header

#include "VCyclicLeftShiftRegister_PosEdge_64Bit___024root.h"
#include "VCyclicLeftShiftRegister_PosEdge_64Bit__Syms.h"

//==========


void VCyclicLeftShiftRegister_PosEdge_64Bit___024root___ctor_var_reset(VCyclicLeftShiftRegister_PosEdge_64Bit___024root* vlSelf);

VCyclicLeftShiftRegister_PosEdge_64Bit___024root::VCyclicLeftShiftRegister_PosEdge_64Bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VCyclicLeftShiftRegister_PosEdge_64Bit___024root___ctor_var_reset(this);
}

void VCyclicLeftShiftRegister_PosEdge_64Bit___024root::__Vconfigure(VCyclicLeftShiftRegister_PosEdge_64Bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VCyclicLeftShiftRegister_PosEdge_64Bit___024root::~VCyclicLeftShiftRegister_PosEdge_64Bit___024root() {
}

void VCyclicLeftShiftRegister_PosEdge_64Bit___024root___eval_initial(VCyclicLeftShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_64Bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void VCyclicLeftShiftRegister_PosEdge_64Bit___024root___eval_settle(VCyclicLeftShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_64Bit___024root___eval_settle\n"); );
}

void VCyclicLeftShiftRegister_PosEdge_64Bit___024root___final(VCyclicLeftShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_64Bit___024root___final\n"); );
}

void VCyclicLeftShiftRegister_PosEdge_64Bit___024root___ctor_var_reset(VCyclicLeftShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_64Bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->D = VL_RAND_RESET_Q(64);
    vlSelf->Q = VL_RAND_RESET_Q(64);
}
