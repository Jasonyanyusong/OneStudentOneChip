// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister64.h for the primary calling header

#include "Vregister64___024root.h"
#include "Vregister64__Syms.h"

//==========

VL_INLINE_OPT void Vregister64___024root___sequent__TOP__1(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___sequent__TOP__1\n"); );
    // Body
    if (vlSelf->clr) {
        vlSelf->q = 0ULL;
    } else if (vlSelf->load) {
        vlSelf->q = vlSelf->inp;
    }
}

void Vregister64___024root___eval(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vregister64___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vregister64___024root___change_request_1(Vregister64___024root* vlSelf);

VL_INLINE_OPT QData Vregister64___024root___change_request(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___change_request\n"); );
    // Body
    return (Vregister64___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vregister64___024root___change_request_1(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister64___024root___eval_debug_assertions(Vregister64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister64___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->load & 0xfeU))) {
        Verilated::overWidthError("load");}
    if (VL_UNLIKELY((vlSelf->clr & 0xfeU))) {
        Verilated::overWidthError("clr");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
