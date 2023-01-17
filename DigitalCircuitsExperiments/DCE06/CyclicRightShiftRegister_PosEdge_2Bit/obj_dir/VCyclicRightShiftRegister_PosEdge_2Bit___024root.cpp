// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicRightShiftRegister_PosEdge_2Bit.h for the primary calling header

#include "VCyclicRightShiftRegister_PosEdge_2Bit___024root.h"
#include "VCyclicRightShiftRegister_PosEdge_2Bit__Syms.h"

//==========

VL_INLINE_OPT void VCyclicRightShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->Q = ((IData)(vlSelf->reset) ? 0U : ((2U 
                                                 & ((IData)(vlSelf->D) 
                                                    << 1U)) 
                                                | (1U 
                                                   & ((IData)(vlSelf->D) 
                                                      >> 1U))));
}

void VCyclicRightShiftRegister_PosEdge_2Bit___024root___eval(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_2Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VCyclicRightShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request_1(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf);

VL_INLINE_OPT QData VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request\n"); );
    // Body
    return (VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request_1(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_2Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCyclicRightShiftRegister_PosEdge_2Bit___024root___eval_debug_assertions(VCyclicRightShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicRightShiftRegister_PosEdge_2Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->D & 0xfcU))) {
        Verilated::overWidthError("D");}
}
#endif  // VL_DEBUG
