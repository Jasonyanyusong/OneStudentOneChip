// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister32.h for the primary calling header

#include "Vregister32___024root.h"
#include "Vregister32__Syms.h"

//==========

VL_INLINE_OPT void Vregister32___024root___sequent__TOP__1(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___sequent__TOP__1\n"); );
    // Body
    if (vlSelf->clr) {
        vlSelf->q = 0U;
    } else if (vlSelf->load) {
        vlSelf->q = vlSelf->inp;
    }
}

void Vregister32___024root___eval(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vregister32___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vregister32___024root___change_request_1(Vregister32___024root* vlSelf);

VL_INLINE_OPT QData Vregister32___024root___change_request(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___change_request\n"); );
    // Body
    return (Vregister32___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vregister32___024root___change_request_1(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister32___024root___eval_debug_assertions(Vregister32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->load & 0xfeU))) {
        Verilated::overWidthError("load");}
    if (VL_UNLIKELY((vlSelf->clr & 0xfeU))) {
        Verilated::overWidthError("clr");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
