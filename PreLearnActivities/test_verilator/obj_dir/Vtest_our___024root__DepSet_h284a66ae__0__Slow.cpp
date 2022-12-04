// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_our.h for the primary calling header

#include "verilated.h"

#include "Vtest_our___024root.h"

VL_ATTR_COLD void Vtest_our___024root___eval_static(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtest_our___024root___eval_initial__TOP(Vtest_our___024root* vlSelf);

VL_ATTR_COLD void Vtest_our___024root___eval_initial(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_initial\n"); );
    // Body
    Vtest_our___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtest_our___024root___eval_initial__TOP(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_initial__TOP\n"); );
    // Body
    VL_WRITEF("Hello World\n");
    VL_FINISH_MT("test_our.v", 5, "");
}

VL_ATTR_COLD void Vtest_our___024root___eval_final(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtest_our___024root___eval_settle(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_our___024root___dump_triggers__act(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_our___024root___dump_triggers__nba(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtest_our___024root___ctor_var_reset(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
