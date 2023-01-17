// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicLeftShiftRegister_PosEdge_2Bit.h for the primary calling header

#include "VCyclicLeftShiftRegister_PosEdge_2Bit___024root.h"
#include "VCyclicLeftShiftRegister_PosEdge_2Bit__Syms.h"

//==========

VL_INLINE_OPT void VCyclicLeftShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->Q = ((IData)(vlSelf->reset) ? 0U : ((2U 
                                                 & ((IData)(vlSelf->D) 
                                                    << 1U)) 
                                                | (1U 
                                                   & ((IData)(vlSelf->D) 
                                                      >> 1U))));
}

void VCyclicLeftShiftRegister_PosEdge_2Bit___024root___eval(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_2Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VCyclicLeftShiftRegister_PosEdge_2Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request_1(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf);

VL_INLINE_OPT QData VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request\n"); );
    // Body
    return (VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request_1(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_2Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCyclicLeftShiftRegister_PosEdge_2Bit___024root___eval_debug_assertions(VCyclicLeftShiftRegister_PosEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_PosEdge_2Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->D & 0xfcU))) {
        Verilated::overWidthError("D");}
}
#endif  // VL_DEBUG
