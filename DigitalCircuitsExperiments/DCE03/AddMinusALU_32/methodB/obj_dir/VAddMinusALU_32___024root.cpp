// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddMinusALU_32.h for the primary calling header

#include "VAddMinusALU_32___024root.h"
#include "VAddMinusALU_32__Syms.h"

//==========

VL_INLINE_OPT void VAddMinusALU_32___024root___combo__TOP__1(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->AddMinusALU_32__DOT__t_no_Cin = ((- (IData)((IData)(vlSelf->sub_add))) 
                                             ^ (vlSelf->b 
                                                + (IData)(vlSelf->sub_add)));
    vlSelf->carry = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->a)) 
                                            + (QData)((IData)(vlSelf->AddMinusALU_32__DOT__t_no_Cin))) 
                                           >> 0x20U))));
    vlSelf->result = (vlSelf->a + vlSelf->AddMinusALU_32__DOT__t_no_Cin);
    vlSelf->zero = (1U & (~ (IData)((0U != vlSelf->result))));
    vlSelf->overflow = (((vlSelf->a >> 0x1fU) == (vlSelf->AddMinusALU_32__DOT__t_no_Cin 
                                                  >> 0x1fU)) 
                        & ((vlSelf->result >> 0x1fU) 
                           != (vlSelf->a >> 0x1fU)));
}

void VAddMinusALU_32___024root___eval(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___eval\n"); );
    // Body
    VAddMinusALU_32___024root___combo__TOP__1(vlSelf);
}

QData VAddMinusALU_32___024root___change_request_1(VAddMinusALU_32___024root* vlSelf);

VL_INLINE_OPT QData VAddMinusALU_32___024root___change_request(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___change_request\n"); );
    // Body
    return (VAddMinusALU_32___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VAddMinusALU_32___024root___change_request_1(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAddMinusALU_32___024root___eval_debug_assertions(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sub_add & 0xfeU))) {
        Verilated::overWidthError("sub_add");}
}
#endif  // VL_DEBUG
