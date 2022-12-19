// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter.h for the primary calling header

#include "verilated.h"

#include "VAddCounter___024root.h"

void VAddCounter___024root___eval_act(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval_act\n"); );
}

VL_INLINE_OPT void VAddCounter___024root___nba_sequent__TOP__0(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->out_q = ((IData)(vlSelf->en) ? (7U & ((IData)(1U) 
                                                  + (IData)(vlSelf->out_q)))
                      : 0U);
}

void VAddCounter___024root___eval_nba(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VAddCounter___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VAddCounter___024root___eval_triggers__act(VAddCounter___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAddCounter___024root___dump_triggers__act(VAddCounter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VAddCounter___024root___dump_triggers__nba(VAddCounter___024root* vlSelf);
#endif  // VL_DEBUG

void VAddCounter___024root___eval(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VAddCounter___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VAddCounter___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("AddCounter.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VAddCounter___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VAddCounter___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("AddCounter.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VAddCounter___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VAddCounter___024root___eval_debug_assertions(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
