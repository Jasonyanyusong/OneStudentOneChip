// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicRightShiftRegister_NegEdge_128Bit.h for the primary calling header

#include "VLogicRightShiftRegister_NegEdge_128Bit___024root.h"
#include "VLogicRightShiftRegister_NegEdge_128Bit__Syms.h"

//==========

VL_INLINE_OPT void VLogicRightShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1\n"); );
    // Variables
    VlWide<4>/*127:0*/ __Vtemp3;
    // Body
    VL_SHIFTR_WWI(128,128,32, __Vtemp3, vlSelf->Q, 1U);
    if (vlSelf->reset) {
        vlSelf->Q[0U] = 0U;
        vlSelf->Q[1U] = 0U;
        vlSelf->Q[2U] = 0U;
        vlSelf->Q[3U] = 0U;
    } else {
        vlSelf->Q[0U] = __Vtemp3[0U];
        vlSelf->Q[1U] = __Vtemp3[1U];
        vlSelf->Q[2U] = __Vtemp3[2U];
        vlSelf->Q[3U] = __Vtemp3[3U];
    }
}

void VLogicRightShiftRegister_NegEdge_128Bit___024root___eval(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_NegEdge_128Bit___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clock)) & (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VLogicRightShiftRegister_NegEdge_128Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request_1(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf);

VL_INLINE_OPT QData VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request\n"); );
    // Body
    return (VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request_1(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_NegEdge_128Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VLogicRightShiftRegister_NegEdge_128Bit___024root___eval_debug_assertions(VLogicRightShiftRegister_NegEdge_128Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_128Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_NegEdge_128Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
