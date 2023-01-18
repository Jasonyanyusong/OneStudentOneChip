// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLogicRightShiftRegister_PosEdge_64Bit.h for the primary calling header

#include "VLogicRightShiftRegister_PosEdge_64Bit___024root.h"
#include "VLogicRightShiftRegister_PosEdge_64Bit__Syms.h"

//==========

VL_INLINE_OPT void VLogicRightShiftRegister_PosEdge_64Bit___024root___sequent__TOP__1(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_PosEdge_64Bit___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->Q = ((IData)(vlSelf->reset) ? 0ULL : (vlSelf->Q 
                                                  >> 1U));
}

void VLogicRightShiftRegister_PosEdge_64Bit___024root___eval(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_PosEdge_64Bit___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VLogicRightShiftRegister_PosEdge_64Bit___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request_1(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf);

VL_INLINE_OPT QData VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request\n"); );
    // Body
    return (VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request_1(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_PosEdge_64Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VLogicRightShiftRegister_PosEdge_64Bit___024root___eval_debug_assertions(VLogicRightShiftRegister_PosEdge_64Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLogicRightShiftRegister_PosEdge_64Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
