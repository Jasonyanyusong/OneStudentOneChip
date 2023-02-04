// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMultiShifter_4Bit.h for the primary calling header

#include "VMultiShifter_4Bit___024root.h"
#include "VMultiShifter_4Bit__Syms.h"

//==========

extern const VlUnpacked<CData/*3:0*/, 2048> VMultiShifter_4Bit__ConstPool__TABLE_acb00034_0;

VL_INLINE_OPT void VMultiShifter_4Bit___024root___sequent__TOP__1(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___sequent__TOP__1\n"); );
    // Variables
    SData/*10:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->inp) << 7U) | 
                    (((IData)(vlSelf->outp) << 3U) 
                     | (IData)(vlSelf->sel)));
    vlSelf->outp = VMultiShifter_4Bit__ConstPool__TABLE_acb00034_0
        [__Vtableidx1];
}

void VMultiShifter_4Bit___024root___eval(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VMultiShifter_4Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VMultiShifter_4Bit___024root___change_request_1(VMultiShifter_4Bit___024root* vlSelf);

VL_INLINE_OPT QData VMultiShifter_4Bit___024root___change_request(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___change_request\n"); );
    // Body
    return (VMultiShifter_4Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VMultiShifter_4Bit___024root___change_request_1(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMultiShifter_4Bit___024root___eval_debug_assertions(VMultiShifter_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMultiShifter_4Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((vlSelf->inp & 0xf0U))) {
        Verilated::overWidthError("inp");}
}
#endif  // VL_DEBUG
