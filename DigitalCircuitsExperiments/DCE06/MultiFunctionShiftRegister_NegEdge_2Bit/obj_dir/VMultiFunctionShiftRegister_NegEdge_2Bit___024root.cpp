// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiFunctionShiftRegister_NegEdge_2Bit.h for the primary calling header

#include "VMultiFunctionShiftRegister_NegEdge_2Bit___024root.h"
#include "VMultiFunctionShiftRegister_NegEdge_2Bit__Syms.h"

//==========

extern const VlUnpacked<CData/*1:0*/, 256> VMultiFunctionShiftRegister_NegEdge_2Bit__ConstPool__TABLE_06396925_0;

VL_INLINE_OPT void VMultiFunctionShiftRegister_NegEdge_2Bit___024root___sequent__TOP__1(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_2Bit___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*7:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->Q) << 6U) | (((IData)(vlSelf->inp) 
                                                   << 5U) 
                                                  | (((IData)(vlSelf->D) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->sel))));
    vlSelf->Q = VMultiFunctionShiftRegister_NegEdge_2Bit__ConstPool__TABLE_06396925_0
        [__Vtableidx1];
}

void VMultiFunctionShiftRegister_NegEdge_2Bit___024root___eval(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_2Bit___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        VMultiFunctionShiftRegister_NegEdge_2Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request_1(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf);

VL_INLINE_OPT QData VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request\n"); );
    // Body
    return (VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request_1(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_2Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMultiFunctionShiftRegister_NegEdge_2Bit___024root___eval_debug_assertions(VMultiFunctionShiftRegister_NegEdge_2Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_2Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->inp & 0xfeU))) {
        Verilated::overWidthError("inp");}
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((vlSelf->D & 0xfcU))) {
        Verilated::overWidthError("D");}
}
#endif  // VL_DEBUG