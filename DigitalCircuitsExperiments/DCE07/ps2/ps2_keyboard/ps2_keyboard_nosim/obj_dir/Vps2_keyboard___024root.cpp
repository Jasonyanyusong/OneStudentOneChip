// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_keyboard.h for the primary calling header

#include "Vps2_keyboard___024root.h"
#include "Vps2_keyboard__Syms.h"

//==========

VL_INLINE_OPT void Vps2_keyboard___024root___sequent__TOP__1(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*2:0*/ __Vdly__ps2_keyboard__DOT__ps2_clk_sync;
    CData/*2:0*/ __Vdly__ps2_keyboard__DOT__r_ptr;
    CData/*2:0*/ __Vdlyvdim0__ps2_keyboard__DOT__fifo__v0;
    CData/*7:0*/ __Vdlyvval__ps2_keyboard__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__ps2_keyboard__DOT__fifo__v0;
    CData/*2:0*/ __Vdly__ps2_keyboard__DOT__w_ptr;
    CData/*3:0*/ __Vdly__ps2_keyboard__DOT__count;
    // Body
    __Vdly__ps2_keyboard__DOT__ps2_clk_sync = vlSelf->ps2_keyboard__DOT__ps2_clk_sync;
    __Vdly__ps2_keyboard__DOT__count = vlSelf->ps2_keyboard__DOT__count;
    __Vdly__ps2_keyboard__DOT__w_ptr = vlSelf->ps2_keyboard__DOT__w_ptr;
    __Vdly__ps2_keyboard__DOT__r_ptr = vlSelf->ps2_keyboard__DOT__r_ptr;
    __Vdlyvset__ps2_keyboard__DOT__fifo__v0 = 0U;
    __Vdly__ps2_keyboard__DOT__ps2_clk_sync = ((6U 
                                                & ((IData)(vlSelf->ps2_keyboard__DOT__ps2_clk_sync) 
                                                   << 1U)) 
                                               | (IData)(vlSelf->ps2_clk));
    if (vlSelf->clrn) {
        if (vlSelf->ready) {
            if ((1U & (~ (IData)(vlSelf->nextdata_n)))) {
                __Vdly__ps2_keyboard__DOT__r_ptr = 
                    (7U & ((IData)(1U) + (IData)(vlSelf->ps2_keyboard__DOT__r_ptr)));
                if (((IData)(vlSelf->ps2_keyboard__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->ps2_keyboard__DOT__r_ptr))))) {
                    vlSelf->ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelf->ps2_keyboard__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->ps2_keyboard__DOT__count))) {
                if ((((~ (IData)(vlSelf->ps2_keyboard__DOT__buffer)) 
                      & (IData)(vlSelf->ps2_data)) 
                     & VL_REDXOR_32((0x1ffU & ((IData)(vlSelf->ps2_keyboard__DOT__buffer) 
                                               >> 1U))))) {
                    __Vdlyvval__ps2_keyboard__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->ps2_keyboard__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__ps2_keyboard__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__ps2_keyboard__DOT__fifo__v0 
                        = vlSelf->ps2_keyboard__DOT__w_ptr;
                    vlSelf->ready = 1U;
                    __Vdly__ps2_keyboard__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->ps2_keyboard__DOT__w_ptr)));
                    vlSelf->overflow = ((IData)(vlSelf->overflow) 
                                        | ((IData)(vlSelf->ps2_keyboard__DOT__r_ptr) 
                                           == (7U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelf->ps2_keyboard__DOT__w_ptr)))));
                }
                __Vdly__ps2_keyboard__DOT__count = 0U;
            } else {
                vlSelf->ps2_keyboard__DOT____Vlvbound1 
                    = vlSelf->ps2_data;
                if ((9U >= (IData)(vlSelf->ps2_keyboard__DOT__count))) {
                    vlSelf->ps2_keyboard__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->ps2_keyboard__DOT__count))) 
                            & (IData)(vlSelf->ps2_keyboard__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->ps2_keyboard__DOT____Vlvbound1) 
                                        << (IData)(vlSelf->ps2_keyboard__DOT__count))));
                }
                __Vdly__ps2_keyboard__DOT__count = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelf->ps2_keyboard__DOT__count)));
            }
        }
    } else {
        __Vdly__ps2_keyboard__DOT__count = 0U;
        __Vdly__ps2_keyboard__DOT__w_ptr = 0U;
        __Vdly__ps2_keyboard__DOT__r_ptr = 0U;
        vlSelf->overflow = 0U;
        vlSelf->ready = 0U;
    }
    vlSelf->ps2_keyboard__DOT__ps2_clk_sync = __Vdly__ps2_keyboard__DOT__ps2_clk_sync;
    vlSelf->ps2_keyboard__DOT__w_ptr = __Vdly__ps2_keyboard__DOT__w_ptr;
    vlSelf->ps2_keyboard__DOT__count = __Vdly__ps2_keyboard__DOT__count;
    vlSelf->ps2_keyboard__DOT__r_ptr = __Vdly__ps2_keyboard__DOT__r_ptr;
    if (__Vdlyvset__ps2_keyboard__DOT__fifo__v0) {
        vlSelf->ps2_keyboard__DOT__fifo[__Vdlyvdim0__ps2_keyboard__DOT__fifo__v0] 
            = __Vdlyvval__ps2_keyboard__DOT__fifo__v0;
    }
    vlSelf->data = vlSelf->ps2_keyboard__DOT__fifo[vlSelf->ps2_keyboard__DOT__r_ptr];
}

void Vps2_keyboard___024root___eval(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vps2_keyboard___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vps2_keyboard___024root___change_request_1(Vps2_keyboard___024root* vlSelf);

VL_INLINE_OPT QData Vps2_keyboard___024root___change_request(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___change_request\n"); );
    // Body
    return (Vps2_keyboard___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vps2_keyboard___024root___change_request_1(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vps2_keyboard___024root___eval_debug_assertions(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->clrn & 0xfeU))) {
        Verilated::overWidthError("clrn");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->nextdata_n & 0xfeU))) {
        Verilated::overWidthError("nextdata_n");}
}
#endif  // VL_DEBUG
