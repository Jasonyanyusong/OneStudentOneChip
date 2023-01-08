// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter16bit.h for the primary calling header

#include "VSubCounter16bit___024root.h"
#include "VSubCounter16bit__Syms.h"

//==========

VL_INLINE_OPT void VSubCounter16bit___024root___sequent__TOP__1(VSubCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter16bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->out_q = ((IData)(vlSelf->en) ? (0xffffU 
                                            & ((IData)(vlSelf->out_q) 
                                               - (IData)(1U)))
                      : 0U);
}

void VSubCounter16bit___024root___eval(VSubCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter16bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VSubCounter16bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VSubCounter16bit___024root___change_request_1(VSubCounter16bit___024root* vlSelf);

VL_INLINE_OPT QData VSubCounter16bit___024root___change_request(VSubCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter16bit___024root___change_request\n"); );
    // Body
    return (VSubCounter16bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VSubCounter16bit___024root___change_request_1(VSubCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter16bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSubCounter16bit___024root___eval_debug_assertions(VSubCounter16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter16bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
