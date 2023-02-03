// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU4Bit_All.h for the primary calling header

#include "VALU4Bit_All___024root.h"
#include "VALU4Bit_All__Syms.h"

//==========

VL_INLINE_OPT void VALU4Bit_All___024root___combo__TOP__1(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___combo__TOP__1\n"); );
    // Body
    if ((1U & (~ ((IData)(vlSelf->sel) >> 2U)))) {
        if ((2U & (IData)(vlSelf->sel))) {
            if ((1U & (~ (IData)(vlSelf->sel)))) {
                vlSelf->ALU4Bit_All__DOT__Cin = 1U;
            }
        } else {
            vlSelf->ALU4Bit_All__DOT__Cin = (1U & (IData)(vlSelf->sel));
        }
    }
    if ((4U & (IData)(vlSelf->sel))) {
        if ((1U & (~ ((IData)(vlSelf->sel) >> 1U)))) {
            vlSelf->ALU4Bit_All__DOT__i = 4U;
        }
    } else if ((2U & (IData)(vlSelf->sel))) {
        if ((1U & (IData)(vlSelf->sel))) {
            vlSelf->ALU4Bit_All__DOT__i = 4U;
        }
    }
    if ((4U & (IData)(vlSelf->sel))) {
        if ((2U & (IData)(vlSelf->sel))) {
            if ((1U & (IData)(vlSelf->sel))) {
                vlSelf->result = (((IData)(vlSelf->a) 
                                   == (IData)(vlSelf->b))
                                   ? 1U : 0U);
                vlSelf->zero = (1U & (~ (IData)((0U 
                                                 != (IData)(vlSelf->result)))));
                vlSelf->carry = 0U;
                vlSelf->overflow = 0U;
            } else {
                vlSelf->result = (((IData)(vlSelf->a) 
                                   < (IData)(vlSelf->b))
                                   ? 1U : 0U);
                vlSelf->zero = (1U & (~ (IData)((0U 
                                                 != (IData)(vlSelf->result)))));
                vlSelf->carry = 0U;
                vlSelf->overflow = 0U;
            }
        } else if ((1U & (IData)(vlSelf->sel))) {
            vlSelf->result = ((0xcU & (IData)(vlSelf->result)) 
                              | ((((1U & ((IData)(vlSelf->a) 
                                          >> 1U)) != 
                                   (1U & ((IData)(vlSelf->b) 
                                          >> 1U))) 
                                  << 1U) | ((1U & (IData)(vlSelf->a)) 
                                            != (1U 
                                                & (IData)(vlSelf->b)))));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->result = ((3U & (IData)(vlSelf->result)) 
                              | ((((1U & ((IData)(vlSelf->a) 
                                          >> 3U)) != 
                                   (1U & ((IData)(vlSelf->b) 
                                          >> 3U))) 
                                  << 3U) | (((1U & 
                                              ((IData)(vlSelf->a) 
                                               >> 2U)) 
                                             != (1U 
                                                 & ((IData)(vlSelf->b) 
                                                    >> 2U))) 
                                            << 2U)));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
        } else {
            vlSelf->result = ((IData)(vlSelf->a) | (IData)(vlSelf->b));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
        }
    } else if ((2U & (IData)(vlSelf->sel))) {
        if ((1U & (IData)(vlSelf->sel))) {
            vlSelf->result = ((0xeU & (IData)(vlSelf->result)) 
                              | (((1U & (IData)(vlSelf->a)) 
                                  == (1U & (IData)(vlSelf->b))) 
                                 & (IData)(vlSelf->a)));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->result = ((0xdU & (IData)(vlSelf->result)) 
                              | (0xfffffffeU & ((((1U 
                                                   & ((IData)(vlSelf->a) 
                                                      >> 1U)) 
                                                  == 
                                                  (1U 
                                                   & ((IData)(vlSelf->b) 
                                                      >> 1U))) 
                                                 << 1U) 
                                                & (IData)(vlSelf->a))));
            vlSelf->result = ((0xbU & (IData)(vlSelf->result)) 
                              | (0xfffffffcU & ((((1U 
                                                   & ((IData)(vlSelf->a) 
                                                      >> 2U)) 
                                                  == 
                                                  (1U 
                                                   & ((IData)(vlSelf->b) 
                                                      >> 2U))) 
                                                 << 2U) 
                                                & (IData)(vlSelf->a))));
            vlSelf->result = ((7U & (IData)(vlSelf->result)) 
                              | (0xfffffff8U & ((((1U 
                                                   & ((IData)(vlSelf->a) 
                                                      >> 3U)) 
                                                  == 
                                                  (1U 
                                                   & ((IData)(vlSelf->b) 
                                                      >> 3U))) 
                                                 << 3U) 
                                                & (IData)(vlSelf->a))));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
        } else {
            vlSelf->result = (0xfU & (~ (IData)(vlSelf->b)));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
        }
    } else if ((1U & (IData)(vlSelf->sel))) {
        vlSelf->ALU4Bit_All__DOT__t_no_Cin = (0xfU 
                                              & (~ (IData)(vlSelf->b)));
        vlSelf->ALU4Bit_All__DOT__carry_and_result 
            = (0x1fU & ((IData)(1U) + ((IData)(vlSelf->a) 
                                       + (IData)(vlSelf->ALU4Bit_All__DOT__t_no_Cin))));
        vlSelf->result = (0xfU & (IData)(vlSelf->ALU4Bit_All__DOT__carry_and_result));
        vlSelf->carry = (1U & ((IData)(vlSelf->ALU4Bit_All__DOT__carry_and_result) 
                               >> 4U));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->a) 
                                    >> 3U)) == (1U 
                                                & ((IData)(vlSelf->ALU4Bit_All__DOT__t_no_Cin) 
                                                   >> 3U))) 
                            & ((1U & ((IData)(vlSelf->result) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->a) 
                                                     >> 3U))));
        vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
    } else {
        vlSelf->ALU4Bit_All__DOT__t_no_Cin = vlSelf->b;
        vlSelf->ALU4Bit_All__DOT__carry_and_result 
            = (0x1fU & ((IData)(vlSelf->a) + (IData)(vlSelf->ALU4Bit_All__DOT__t_no_Cin)));
        vlSelf->result = (0xfU & (IData)(vlSelf->ALU4Bit_All__DOT__carry_and_result));
        vlSelf->carry = (1U & ((IData)(vlSelf->ALU4Bit_All__DOT__carry_and_result) 
                               >> 4U));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->a) 
                                    >> 3U)) == (1U 
                                                & ((IData)(vlSelf->ALU4Bit_All__DOT__t_no_Cin) 
                                                   >> 3U))) 
                            & ((1U & ((IData)(vlSelf->result) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->a) 
                                                     >> 3U))));
        vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->result)))));
    }
}

void VALU4Bit_All___024root___eval(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___eval\n"); );
    // Body
    VALU4Bit_All___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
}

QData VALU4Bit_All___024root___change_request_1(VALU4Bit_All___024root* vlSelf);

VL_INLINE_OPT QData VALU4Bit_All___024root___change_request(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___change_request\n"); );
    // Body
    return (VALU4Bit_All___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VALU4Bit_All___024root___change_request_1(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU4Bit_All___024root___eval_debug_assertions(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
}
#endif  // VL_DEBUG
