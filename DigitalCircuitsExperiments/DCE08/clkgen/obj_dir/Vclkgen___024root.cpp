// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclkgen.h for the primary calling header

#include "Vclkgen___024root.h"
#include "Vclkgen__Syms.h"

//==========

VL_INLINE_OPT void Vclkgen___024root___sequent__TOP__1(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___sequent__TOP__1\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->clkgen__DOT__clkcount = 0U;
        vlSelf->clkout = 0U;
    } else if (vlSelf->clken) {
        vlSelf->clkgen__DOT__clkcount = ((IData)(1U) 
                                         + vlSelf->clkgen__DOT__clkcount);
        if ((0x61a8U <= vlSelf->clkgen__DOT__clkcount)) {
            vlSelf->clkout = (1U & (~ (IData)(vlSelf->clkout)));
            vlSelf->clkgen__DOT__clkcount = 0U;
        }
    }
}

void Vclkgen___024root___eval(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clkin) & (~ (IData)(vlSelf->__Vclklast__TOP__clkin)))) {
        Vclkgen___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clkin = vlSelf->clkin;
}

QData Vclkgen___024root___change_request_1(Vclkgen___024root* vlSelf);

VL_INLINE_OPT QData Vclkgen___024root___change_request(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___change_request\n"); );
    // Body
    return (Vclkgen___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vclkgen___024root___change_request_1(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vclkgen___024root___eval_debug_assertions(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clkin & 0xfeU))) {
        Verilated::overWidthError("clkin");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clken & 0xfeU))) {
        Verilated::overWidthError("clken");}
}
#endif  // VL_DEBUG
