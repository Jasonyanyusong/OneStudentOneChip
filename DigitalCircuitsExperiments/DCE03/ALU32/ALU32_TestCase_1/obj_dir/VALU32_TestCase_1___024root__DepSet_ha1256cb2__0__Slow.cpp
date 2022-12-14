// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_TestCase_1.h for the primary calling header

#include "verilated.h"

#include "VALU32_TestCase_1___024root.h"

VL_ATTR_COLD void VALU32_TestCase_1___024root___eval_static(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___eval_static\n"); );
}

VL_ATTR_COLD void VALU32_TestCase_1___024root___eval_initial(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__sub_add = vlSelf->sub_add;
}

VL_ATTR_COLD void VALU32_TestCase_1___024root___eval_final(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___eval_final\n"); );
}

VL_ATTR_COLD void VALU32_TestCase_1___024root___eval_settle(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestCase_1___024root___dump_triggers__act(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([changed] sub_add)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestCase_1___024root___dump_triggers__nba(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([changed] sub_add)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU32_TestCase_1___024root___ctor_var_reset(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sub_add = VL_RAND_RESET_I(1);
    vlSelf->a = VL_RAND_RESET_I(32);
    vlSelf->b = VL_RAND_RESET_I(32);
    vlSelf->carry = VL_RAND_RESET_I(1);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->ALU32_TestCase_1__DOT__b_withCin = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__sub_add = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
