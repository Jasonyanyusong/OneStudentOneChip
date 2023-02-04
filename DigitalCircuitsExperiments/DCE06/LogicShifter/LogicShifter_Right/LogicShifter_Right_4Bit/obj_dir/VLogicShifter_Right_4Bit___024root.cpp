// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicShifter_Right_4Bit.h for the primary calling header

#include "VLogicShifter_Right_4Bit___024root.h"
#include "VLogicShifter_Right_4Bit__Syms.h"

//==========

VL_INLINE_OPT void VLogicShifter_Right_4Bit___024root___sequent__TOP__1(VLogicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Right_4Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->outp = ((IData)(vlSelf->load) ? (IData)(vlSelf->inp)
                     : ((IData)(vlSelf->clr) ? 0U : 
                        (7U & ((IData)(vlSelf->outp) 
                               >> 1U))));
}

void VLogicShifter_Right_4Bit___024root___eval(VLogicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Right_4Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VLogicShifter_Right_4Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VLogicShifter_Right_4Bit___024root___change_request_1(VLogicShifter_Right_4Bit___024root* vlSelf);

VL_INLINE_OPT QData VLogicShifter_Right_4Bit___024root___change_request(VLogicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Right_4Bit___024root___change_request\n"); );
    // Body
    return (VLogicShifter_Right_4Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VLogicShifter_Right_4Bit___024root___change_request_1(VLogicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Right_4Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VLogicShifter_Right_4Bit___024root___eval_debug_assertions(VLogicShifter_Right_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Right_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicShifter_Right_4Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->clr & 0xfeU))) {
        Verilated::overWidthError("clr");}
    if (VL_UNLIKELY((vlSelf->load & 0xfeU))) {
        Verilated::overWidthError("load");}
    if (VL_UNLIKELY((vlSelf->inp & 0xf0U))) {
        Verilated::overWidthError("inp");}
}
#endif  // VL_DEBUG
