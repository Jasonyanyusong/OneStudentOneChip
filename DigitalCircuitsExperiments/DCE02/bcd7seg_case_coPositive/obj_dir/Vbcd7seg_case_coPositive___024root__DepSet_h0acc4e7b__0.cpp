// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbcd7seg_case_coPositive.h for the primary calling header

#include "verilated.h"

#include "Vbcd7seg_case_coPositive___024root.h"

extern const VlUnpacked<CData/*6:0*/, 16> Vbcd7seg_case_coPositive__ConstPool__TABLE_hc20f331a_0;

VL_INLINE_OPT void Vbcd7seg_case_coPositive___024root___ico_sequent__TOP__0(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = vlSelf->b;
    vlSelf->h = Vbcd7seg_case_coPositive__ConstPool__TABLE_hc20f331a_0
        [__Vtableidx1];
}

void Vbcd7seg_case_coPositive___024root___eval_ico(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vbcd7seg_case_coPositive___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vbcd7seg_case_coPositive___024root___eval_act(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval_act\n"); );
}

void Vbcd7seg_case_coPositive___024root___eval_nba(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval_nba\n"); );
}

void Vbcd7seg_case_coPositive___024root___eval_triggers__ico(Vbcd7seg_case_coPositive___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root___dump_triggers__ico(Vbcd7seg_case_coPositive___024root* vlSelf);
#endif  // VL_DEBUG
void Vbcd7seg_case_coPositive___024root___eval_triggers__act(Vbcd7seg_case_coPositive___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root___dump_triggers__act(Vbcd7seg_case_coPositive___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root___dump_triggers__nba(Vbcd7seg_case_coPositive___024root* vlSelf);
#endif  // VL_DEBUG

void Vbcd7seg_case_coPositive___024root___eval(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval\n"); );
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
        Vbcd7seg_case_coPositive___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vbcd7seg_case_coPositive___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("bcd7seg_case_coPositive.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vbcd7seg_case_coPositive___024root___eval_ico(vlSelf);
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
            Vbcd7seg_case_coPositive___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vbcd7seg_case_coPositive___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("bcd7seg_case_coPositive.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vbcd7seg_case_coPositive___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vbcd7seg_case_coPositive___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("bcd7seg_case_coPositive.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vbcd7seg_case_coPositive___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vbcd7seg_case_coPositive___024root___eval_debug_assertions(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
}
#endif  // VL_DEBUG
