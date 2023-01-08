// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter64bit.h for the primary calling header

#include "VSubCounter64bit___024root.h"
#include "VSubCounter64bit__Syms.h"

//==========

VL_INLINE_OPT void VSubCounter64bit___024root___sequent__TOP__1(VSubCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter64bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->out_q = ((IData)(vlSelf->en) ? (vlSelf->out_q 
                                            - 1ULL)
                      : 0ULL);
}

void VSubCounter64bit___024root___eval(VSubCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter64bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VSubCounter64bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VSubCounter64bit___024root___change_request_1(VSubCounter64bit___024root* vlSelf);

VL_INLINE_OPT QData VSubCounter64bit___024root___change_request(VSubCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter64bit___024root___change_request\n"); );
    // Body
    return (VSubCounter64bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VSubCounter64bit___024root___change_request_1(VSubCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter64bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSubCounter64bit___024root___eval_debug_assertions(VSubCounter64bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter64bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
