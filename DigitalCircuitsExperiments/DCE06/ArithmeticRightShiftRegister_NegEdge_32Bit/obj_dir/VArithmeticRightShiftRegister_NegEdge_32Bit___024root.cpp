// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArithmeticRightShiftRegister_NegEdge_32Bit.h for the primary calling header

#include "VArithmeticRightShiftRegister_NegEdge_32Bit___024root.h"
#include "VArithmeticRightShiftRegister_NegEdge_32Bit__Syms.h"

//==========

VL_INLINE_OPT void VArithmeticRightShiftRegister_NegEdge_32Bit___024root___sequent__TOP__1(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_32Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_32Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->Q = ((IData)(vlSelf->reset) ? 0U : ((0x80000000U 
                                                 & vlSelf->D) 
                                                | (vlSelf->D 
                                                   >> 1U)));
}

void VArithmeticRightShiftRegister_NegEdge_32Bit___024root___eval(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_32Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_32Bit___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clock)) & (IData)(vlSelf->__Vclklast__TOP__clock))) {
        VArithmeticRightShiftRegister_NegEdge_32Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request_1(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf);

VL_INLINE_OPT QData VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_32Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request\n"); );
    // Body
    return (VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request_1(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_32Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_32Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VArithmeticRightShiftRegister_NegEdge_32Bit___024root___eval_debug_assertions(VArithmeticRightShiftRegister_NegEdge_32Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_NegEdge_32Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VArithmeticRightShiftRegister_NegEdge_32Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
