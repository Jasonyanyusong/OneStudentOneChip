// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVHM__02dRISCV64IM.h for the primary calling header

#include "verilated.h"

#include "VVHM__02dRISCV64IM___024root.h"

VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___eval_static(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_static\n"); );
}

VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___eval_initial(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_initial\n"); );
}

VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___eval_final(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_final\n"); );
}

VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___eval_settle(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___dump_triggers__act(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___dump_triggers__nba(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___ctor_var_reset(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->riscv_32bits_instruction = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
