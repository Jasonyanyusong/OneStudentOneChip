// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiFunctionShiftRegister_NegEdge_8Bit.h for the primary calling header

#include "VMultiFunctionShiftRegister_NegEdge_8Bit___024root.h"
#include "VMultiFunctionShiftRegister_NegEdge_8Bit__Syms.h"

//==========

VL_INLINE_OPT void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___sequent__TOP__1(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*31:0*/ __Vtemp1;
    // Body
    __Vtemp1 = (0xffU & ((4U & (IData)(vlSelf->sel))
                          ? ((2U & (IData)(vlSelf->sel))
                              ? ((1U & (IData)(vlSelf->sel))
                                  ? ((0xfeU & ((IData)(vlSelf->Q) 
                                               << 1U)) 
                                     | (1U & ((IData)(vlSelf->Q) 
                                              >> 7U)))
                                  : ((0x80U & ((IData)(vlSelf->Q) 
                                               << 7U)) 
                                     | (0x7fU & ((IData)(vlSelf->Q) 
                                                 >> 1U))))
                              : ((1U & (IData)(vlSelf->sel))
                                  ? (((IData)(vlSelf->inp) 
                                      << 7U) | (0x7fU 
                                                & ((IData)(vlSelf->Q) 
                                                   >> 1U)))
                                  : ((0x80U & (IData)(vlSelf->Q)) 
                                     | (0x7fU & ((IData)(vlSelf->Q) 
                                                 >> 1U)))))
                          : ((2U & (IData)(vlSelf->sel))
                              ? ((1U & (IData)(vlSelf->sel))
                                  ? ((IData)(vlSelf->Q) 
                                     << 1U) : ((IData)(vlSelf->Q) 
                                               >> 1U))
                              : ((1U & (IData)(vlSelf->sel))
                                  ? (IData)(vlSelf->D)
                                  : 0U))));
    vlSelf->Q = __Vtemp1;
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        VMultiFunctionShiftRegister_NegEdge_8Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request_1(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf);

VL_INLINE_OPT QData VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request\n"); );
    // Body
    return (VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request_1(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_debug_assertions(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiFunctionShiftRegister_NegEdge_8Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->inp & 0xfeU))) {
        Verilated::overWidthError("inp");}
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
}
#endif  // VL_DEBUG
