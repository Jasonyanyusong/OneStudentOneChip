// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicLeftShiftRegister_PosEdge_4Bit.h for the primary calling header

#include "VLogicLeftShiftRegister_PosEdge_4Bit___024root.h"
#include "VLogicLeftShiftRegister_PosEdge_4Bit__Syms.h"

//==========

VL_INLINE_OPT void VLogicLeftShiftRegister_PosEdge_4Bit___024root___sequent__TOP__1(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_4Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->Q = ((IData)(vlSelf->reset) ? 0U : (0xfU 
                                                & ((IData)(vlSelf->Q) 
                                                   << 1U)));
}

void VLogicLeftShiftRegister_PosEdge_4Bit___024root___eval(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_4Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VLogicLeftShiftRegister_PosEdge_4Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request_1(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf);

VL_INLINE_OPT QData VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request\n"); );
    // Body
    return (VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request_1(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_4Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VLogicLeftShiftRegister_PosEdge_4Bit___024root___eval_debug_assertions(VLogicLeftShiftRegister_PosEdge_4Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicLeftShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicLeftShiftRegister_PosEdge_4Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->D & 0xf0U))) {
        Verilated::overWidthError("D");}
}
#endif  // VL_DEBUG
