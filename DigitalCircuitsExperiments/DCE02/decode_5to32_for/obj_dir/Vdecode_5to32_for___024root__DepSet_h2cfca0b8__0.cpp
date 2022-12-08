// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode_5to32_for.h for the primary calling header

#include "verilated.h"

#include "Vdecode_5to32_for___024root.h"

VL_INLINE_OPT void Vdecode_5to32_for___024root___ico_sequent__TOP__0(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___ico_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->en) {
        vlSelf->decode_5to32_for__DOT__i = 0x20U;
        vlSelf->y = ((0xfffffff8U & vlSelf->y) | ((
                                                   (2U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 2U) 
                                                  | (((1U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 1U) 
                                                     | (0U 
                                                        == (IData)(vlSelf->x)))));
        vlSelf->y = ((0xffffffc7U & vlSelf->y) | ((
                                                   (5U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 5U) 
                                                  | (((4U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 4U) 
                                                     | ((3U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 3U))));
        vlSelf->y = ((0xfffffe3fU & vlSelf->y) | ((
                                                   (8U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 8U) 
                                                  | (((7U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 7U) 
                                                     | ((6U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 6U))));
        vlSelf->y = ((0xfffff1ffU & vlSelf->y) | ((
                                                   (0xbU 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0xbU) 
                                                  | (((0xaU 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0xaU) 
                                                     | ((9U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 9U))));
        vlSelf->y = ((0xffff8fffU & vlSelf->y) | ((
                                                   (0xeU 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0xeU) 
                                                  | (((0xdU 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0xdU) 
                                                     | ((0xcU 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0xcU))));
        vlSelf->y = ((0xfffc7fffU & vlSelf->y) | ((
                                                   (0x11U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x11U) 
                                                  | (((0x10U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0x10U) 
                                                     | ((0xfU 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0xfU))));
        vlSelf->y = ((0xffe3ffffU & vlSelf->y) | ((
                                                   (0x14U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x14U) 
                                                  | (((0x13U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0x13U) 
                                                     | ((0x12U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0x12U))));
        vlSelf->y = ((0xff1fffffU & vlSelf->y) | ((
                                                   (0x17U 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x17U) 
                                                  | (((0x16U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0x16U) 
                                                     | ((0x15U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0x15U))));
        vlSelf->y = ((0xf8ffffffU & vlSelf->y) | ((
                                                   (0x1aU 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x1aU) 
                                                  | (((0x19U 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0x19U) 
                                                     | ((0x18U 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0x18U))));
        vlSelf->y = ((0xc7ffffffU & vlSelf->y) | ((
                                                   (0x1dU 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x1dU) 
                                                  | (((0x1cU 
                                                       == (IData)(vlSelf->x)) 
                                                      << 0x1cU) 
                                                     | ((0x1bU 
                                                         == (IData)(vlSelf->x)) 
                                                        << 0x1bU))));
        vlSelf->y = ((0x3fffffffU & vlSelf->y) | ((
                                                   (0x1fU 
                                                    == (IData)(vlSelf->x)) 
                                                   << 0x1fU) 
                                                  | ((0x1eU 
                                                      == (IData)(vlSelf->x)) 
                                                     << 0x1eU)));
    } else {
        vlSelf->y = 0U;
    }
}

void Vdecode_5to32_for___024root___eval_ico(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vdecode_5to32_for___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vdecode_5to32_for___024root___eval_act(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval_act\n"); );
}

void Vdecode_5to32_for___024root___eval_nba(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval_nba\n"); );
}

void Vdecode_5to32_for___024root___eval_triggers__ico(Vdecode_5to32_for___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_5to32_for___024root___dump_triggers__ico(Vdecode_5to32_for___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecode_5to32_for___024root___eval_triggers__act(Vdecode_5to32_for___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_5to32_for___024root___dump_triggers__act(Vdecode_5to32_for___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_5to32_for___024root___dump_triggers__nba(Vdecode_5to32_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vdecode_5to32_for___024root___eval(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval\n"); );
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
        Vdecode_5to32_for___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vdecode_5to32_for___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("decode_5to32_for.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vdecode_5to32_for___024root___eval_ico(vlSelf);
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
            Vdecode_5to32_for___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vdecode_5to32_for___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("decode_5to32_for.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vdecode_5to32_for___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vdecode_5to32_for___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("decode_5to32_for.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vdecode_5to32_for___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vdecode_5to32_for___024root___eval_debug_assertions(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xe0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
