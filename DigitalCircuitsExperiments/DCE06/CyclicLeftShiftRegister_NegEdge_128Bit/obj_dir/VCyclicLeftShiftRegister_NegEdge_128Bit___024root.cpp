// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCyclicLeftShiftRegister_NegEdge_128Bit.h for the primary calling header

#include "VCyclicLeftShiftRegister_NegEdge_128Bit___024root.h"
#include "VCyclicLeftShiftRegister_NegEdge_128Bit__Syms.h"

//==========

VL_INLINE_OPT void VCyclicLeftShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->Q[0U] = 0U;
        vlSelf->Q[1U] = 0U;
        vlSelf->Q[2U] = 0U;
        vlSelf->Q[3U] = 0U;
    } else {
        vlSelf->Q[0U] = ((vlSelf->D[0U] << 1U) | (vlSelf->D[3U] 
                                                  >> 0x1fU));
        vlSelf->Q[1U] = ((vlSelf->D[0U] >> 0x1fU) | 
                         (vlSelf->D[1U] << 1U));
        vlSelf->Q[2U] = ((vlSelf->D[1U] >> 0x1fU) | 
                         (vlSelf->D[2U] << 1U));
        vlSelf->Q[3U] = ((vlSelf->D[2U] >> 0x1fU) | 
                         (vlSelf->D[3U] << 1U));
    }
}

void VCyclicLeftShiftRegister_NegEdge_128Bit___024root___eval(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_NegEdge_128Bit___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clock)) & (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VCyclicLeftShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request_1(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf);

VL_INLINE_OPT QData VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request\n"); );
    // Body
    return (VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request_1(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_NegEdge_128Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCyclicLeftShiftRegister_NegEdge_128Bit___024root___eval_debug_assertions(VCyclicLeftShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCyclicLeftShiftRegister_NegEdge_128Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
