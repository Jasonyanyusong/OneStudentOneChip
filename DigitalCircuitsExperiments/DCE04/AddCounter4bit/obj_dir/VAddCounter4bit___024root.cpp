// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter4bit.h for the primary calling header

#include "VAddCounter4bit___024root.h"
#include "VAddCounter4bit__Syms.h"

//==========

VL_INLINE_OPT void VAddCounter4bit___024root___sequent__TOP__1(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->out_q = ((IData)(vlSelf->en) ? (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelf->out_q)))
                      : 0U);
}

void VAddCounter4bit___024root___eval(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VAddCounter4bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VAddCounter4bit___024root___change_request_1(VAddCounter4bit___024root* vlSelf);

VL_INLINE_OPT QData VAddCounter4bit___024root___change_request(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___change_request\n"); );
    // Body
    return (VAddCounter4bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VAddCounter4bit___024root___change_request_1(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAddCounter4bit___024root___eval_debug_assertions(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
