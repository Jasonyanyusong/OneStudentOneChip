// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode_32to5_for.h for the primary calling header

#include "verilated.h"

#include "Vencode_32to5_for___024root.h"

VL_INLINE_OPT void Vencode_32to5_for___024root___ico_sequent__TOP__0(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___ico_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->en) {
        vlSelf->encode_32to5_for__DOT__i = 0x20U;
        vlSelf->y = 0U;
        if ((1U & vlSelf->x)) {
            vlSelf->y = 0U;
        }
        if ((2U & vlSelf->x)) {
            vlSelf->y = 1U;
        }
        if ((4U & vlSelf->x)) {
            vlSelf->y = 2U;
        }
        if ((8U & vlSelf->x)) {
            vlSelf->y = 3U;
        }
        if ((0x10U & vlSelf->x)) {
            vlSelf->y = 4U;
        }
        if ((0x20U & vlSelf->x)) {
            vlSelf->y = 5U;
        }
        if ((0x40U & vlSelf->x)) {
            vlSelf->y = 6U;
        }
        if ((0x80U & vlSelf->x)) {
            vlSelf->y = 7U;
        }
        if ((0x100U & vlSelf->x)) {
            vlSelf->y = 8U;
        }
        if ((0x200U & vlSelf->x)) {
            vlSelf->y = 9U;
        }
        if ((0x400U & vlSelf->x)) {
            vlSelf->y = 0xaU;
        }
        if ((0x800U & vlSelf->x)) {
            vlSelf->y = 0xbU;
        }
        if ((0x1000U & vlSelf->x)) {
            vlSelf->y = 0xcU;
        }
        if ((0x2000U & vlSelf->x)) {
            vlSelf->y = 0xdU;
        }
        if ((0x4000U & vlSelf->x)) {
            vlSelf->y = 0xeU;
        }
        if ((0x8000U & vlSelf->x)) {
            vlSelf->y = 0xfU;
        }
        if ((0x10000U & vlSelf->x)) {
            vlSelf->y = 0x10U;
        }
        if ((0x20000U & vlSelf->x)) {
            vlSelf->y = 0x11U;
        }
        if ((0x40000U & vlSelf->x)) {
            vlSelf->y = 0x12U;
        }
        if ((0x80000U & vlSelf->x)) {
            vlSelf->y = 0x13U;
        }
        if ((0x100000U & vlSelf->x)) {
            vlSelf->y = 0x14U;
        }
        if ((0x200000U & vlSelf->x)) {
            vlSelf->y = 0x15U;
        }
        if ((0x400000U & vlSelf->x)) {
            vlSelf->y = 0x16U;
        }
        if ((0x800000U & vlSelf->x)) {
            vlSelf->y = 0x17U;
        }
        if ((0x1000000U & vlSelf->x)) {
            vlSelf->y = 0x18U;
        }
        if ((0x2000000U & vlSelf->x)) {
            vlSelf->y = 0x19U;
        }
        if ((0x4000000U & vlSelf->x)) {
            vlSelf->y = 0x1aU;
        }
        if ((0x8000000U & vlSelf->x)) {
            vlSelf->y = 0x1bU;
        }
        if ((0x10000000U & vlSelf->x)) {
            vlSelf->y = 0x1cU;
        }
        if ((0x20000000U & vlSelf->x)) {
            vlSelf->y = 0x1dU;
        }
        if ((0x40000000U & vlSelf->x)) {
            vlSelf->y = 0x1eU;
        }
        if ((vlSelf->x >> 0x1fU)) {
            vlSelf->y = 0x1fU;
        }
    } else {
        vlSelf->y = 0U;
    }
}

void Vencode_32to5_for___024root___eval_ico(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vencode_32to5_for___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vencode_32to5_for___024root___eval_act(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___eval_act\n"); );
}

void Vencode_32to5_for___024root___eval_nba(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___eval_nba\n"); );
}

void Vencode_32to5_for___024root___eval_triggers__ico(Vencode_32to5_for___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode_32to5_for___024root___dump_triggers__ico(Vencode_32to5_for___024root* vlSelf);
#endif  // VL_DEBUG
void Vencode_32to5_for___024root___eval_triggers__act(Vencode_32to5_for___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode_32to5_for___024root___dump_triggers__act(Vencode_32to5_for___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode_32to5_for___024root___dump_triggers__nba(Vencode_32to5_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode_32to5_for___024root___eval(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vencode_32to5_for___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vencode_32to5_for___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("encode_32to5_for.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vencode_32to5_for___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vencode_32to5_for___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vencode_32to5_for___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("encode_32to5_for.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vencode_32to5_for___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vencode_32to5_for___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("encode_32to5_for.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vencode_32to5_for___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vencode_32to5_for___024root___eval_debug_assertions(Vencode_32to5_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
