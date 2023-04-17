// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMSPC_V_ALU.h for the primary calling header

#include "verilated.h"

#include "VMSPC_V_ALU___024root.h"

VL_ATTR_COLD void VMSPC_V_ALU___024root___eval_static(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_static\n"); );
}

VL_ATTR_COLD void VMSPC_V_ALU___024root___eval_initial(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__sel = vlSelf->sel;
}

VL_ATTR_COLD void VMSPC_V_ALU___024root___eval_final(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_final\n"); );
}

VL_ATTR_COLD void VMSPC_V_ALU___024root___eval_settle(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMSPC_V_ALU___024root___dump_triggers__act(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([changed] sel)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VMSPC_V_ALU___024root___dump_triggers__nba(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([changed] sel)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VMSPC_V_ALU___024root___ctor_var_reset(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->inpa = VL_RAND_RESET_Q(64);
    vlSelf->inpb = VL_RAND_RESET_Q(64);
    vlSelf->sel = VL_RAND_RESET_I(4);
    vlSelf->booloutp = VL_RAND_RESET_I(1);
    vlSelf->numoutp = VL_RAND_RESET_Q(64);
    vlSelf->__Vtrigrprev__TOP__sel = VL_RAND_RESET_I(4);
    vlSelf->__VactDidInit = 0;
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
