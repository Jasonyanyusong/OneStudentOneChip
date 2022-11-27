// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux_2to1_Behavior.h for the primary calling header

#include "Vmux_2to1_Behavior___024root.h"
#include "Vmux_2to1_Behavior__Syms.h"

//==========

VL_INLINE_OPT void Vmux_2to1_Behavior___024root___combo__TOP__1(Vmux_2to1_Behavior___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Behavior___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->y = ((IData)(vlSelf->s) ? (IData)(vlSelf->b)
                  : (IData)(vlSelf->a));
}

void Vmux_2to1_Behavior___024root___eval(Vmux_2to1_Behavior___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Behavior___024root___eval\n"); );
    // Body
    Vmux_2to1_Behavior___024root___combo__TOP__1(vlSelf);
}

QData Vmux_2to1_Behavior___024root___change_request_1(Vmux_2to1_Behavior___024root* vlSelf);

VL_INLINE_OPT QData Vmux_2to1_Behavior___024root___change_request(Vmux_2to1_Behavior___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Behavior___024root___change_request\n"); );
    // Body
    return (Vmux_2to1_Behavior___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vmux_2to1_Behavior___024root___change_request_1(Vmux_2to1_Behavior___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Behavior___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmux_2to1_Behavior___024root___eval_debug_assertions(Vmux_2to1_Behavior___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Behavior___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xfeU))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xfeU))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((vlSelf->s & 0xfeU))) {
        Verilated::overWidthError("s");}
}
#endif  // VL_DEBUG
