// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_4bit_structure.h for the primary calling header

#include "verilated.h"

#include "Vadd_4bit_structure___024root.h"

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_static(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_initial(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_final(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_triggers__stl(Vadd_4bit_structure___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__stl(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_stl(Vadd_4bit_structure___024root* vlSelf);

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_settle(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vadd_4bit_structure___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vadd_4bit_structure___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("add_4bit_structure.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vadd_4bit_structure___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__stl(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vadd_4bit_structure___024root___ico_sequent__TOP__0(Vadd_4bit_structure___024root* vlSelf);

VL_ATTR_COLD void Vadd_4bit_structure___024root___eval_stl(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vadd_4bit_structure___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__ico(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__act(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__nba(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd_4bit_structure___024root___ctor_var_reset(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a_0 = VL_RAND_RESET_I(1);
    vlSelf->b_0 = VL_RAND_RESET_I(1);
    vlSelf->c_in = VL_RAND_RESET_I(1);
    vlSelf->s_0 = VL_RAND_RESET_I(1);
    vlSelf->a_1 = VL_RAND_RESET_I(1);
    vlSelf->b_1 = VL_RAND_RESET_I(1);
    vlSelf->c_1 = VL_RAND_RESET_I(1);
    vlSelf->s_1 = VL_RAND_RESET_I(1);
    vlSelf->a_2 = VL_RAND_RESET_I(1);
    vlSelf->b_2 = VL_RAND_RESET_I(1);
    vlSelf->c_2 = VL_RAND_RESET_I(1);
    vlSelf->s_2 = VL_RAND_RESET_I(1);
    vlSelf->a_3 = VL_RAND_RESET_I(1);
    vlSelf->b_3 = VL_RAND_RESET_I(1);
    vlSelf->c_3 = VL_RAND_RESET_I(1);
    vlSelf->s_3 = VL_RAND_RESET_I(1);
    vlSelf->c_out = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add0_1 = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add1_2 = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add2_3 = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add0__DOT__c_iANDA_D = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add1__DOT__c_iANDA_D = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add2__DOT__c_iANDA_D = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B = VL_RAND_RESET_I(1);
    vlSelf->add_4bit_structure__DOT__add3__DOT__c_iANDA_D = VL_RAND_RESET_I(1);
    vlSelf->__VstlIterCount = 0;
    vlSelf->__VicoIterCount = 0;
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
