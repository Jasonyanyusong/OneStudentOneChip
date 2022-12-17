// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_Test.h for the primary calling header

#include "verilated.h"

#include "VALU32_Test___024root.h"

VL_ATTR_COLD void VALU32_Test___024root___eval_static(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_static\n"); );
}

VL_ATTR_COLD void VALU32_Test___024root___eval_initial(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_initial\n"); );
}

VL_ATTR_COLD void VALU32_Test___024root___eval_final(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_final\n"); );
}

VL_ATTR_COLD void VALU32_Test___024root___eval_triggers__stl(VALU32_Test___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__stl(VALU32_Test___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___eval_stl(VALU32_Test___024root* vlSelf);

VL_ATTR_COLD void VALU32_Test___024root___eval_settle(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VALU32_Test___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VALU32_Test___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("ALU32_Test.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VALU32_Test___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__stl(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VALU32_Test___024root___ico_sequent__TOP__0(VALU32_Test___024root* vlSelf);

VL_ATTR_COLD void VALU32_Test___024root___eval_stl(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VALU32_Test___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__ico(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__act(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__nba(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU32_Test___024root___ctor_var_reset(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sub_add = VL_RAND_RESET_I(1);
    vlSelf->a = VL_RAND_RESET_I(32);
    vlSelf->b = VL_RAND_RESET_I(32);
    vlSelf->carry = VL_RAND_RESET_I(1);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->ALU32_Test__DOT__b_withCin = VL_RAND_RESET_I(32);
    vlSelf->ALU32_Test__DOT__testF2S1B1T2_expected_zero = VL_RAND_RESET_I(1);
    vlSelf->ALU32_Test__DOT__testF2S1B1T2_expected_overflow = VL_RAND_RESET_I(1);
    vlSelf->ALU32_Test__DOT__testF2S1B1T3_expected_zero = VL_RAND_RESET_I(1);
    vlSelf->ALU32_Test__DOT__testF2S1B1T3_expected_overflow = VL_RAND_RESET_I(1);
    vlSelf->__VstlIterCount = 0;
    vlSelf->__VicoIterCount = 0;
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
