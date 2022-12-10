// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_1bit_case.h for the primary calling header

#include "verilated.h"

#include "Vadd_1bit_case___024root.h"

extern const VlUnpacked<CData/*0:0*/, 8> Vadd_1bit_case__ConstPool__TABLE_h9586605d_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vadd_1bit_case__ConstPool__TABLE_h950ad943_0;

VL_INLINE_OPT void Vadd_1bit_case___024root___ico_sequent__TOP__0(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->b_i) << 2U) | 
                    (((IData)(vlSelf->a_i) << 1U) | (IData)(vlSelf->c_i)));
    vlSelf->s_i = Vadd_1bit_case__ConstPool__TABLE_h9586605d_0
        [__Vtableidx1];
    vlSelf->c_iplus1 = Vadd_1bit_case__ConstPool__TABLE_h950ad943_0
        [__Vtableidx1];
}

void Vadd_1bit_case___024root___eval_ico(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vadd_1bit_case___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vadd_1bit_case___024root___eval_act(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___eval_act\n"); );
}

void Vadd_1bit_case___024root___eval_nba(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___eval_nba\n"); );
}

void Vadd_1bit_case___024root___eval_triggers__ico(Vadd_1bit_case___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_1bit_case___024root___dump_triggers__ico(Vadd_1bit_case___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_1bit_case___024root___eval_triggers__act(Vadd_1bit_case___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_1bit_case___024root___dump_triggers__act(Vadd_1bit_case___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_1bit_case___024root___dump_triggers__nba(Vadd_1bit_case___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_1bit_case___024root___eval(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___eval\n"); );
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
        Vadd_1bit_case___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vadd_1bit_case___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("add_1bit_case.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vadd_1bit_case___024root___eval_ico(vlSelf);
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
            Vadd_1bit_case___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vadd_1bit_case___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("add_1bit_case.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vadd_1bit_case___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vadd_1bit_case___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("add_1bit_case.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vadd_1bit_case___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vadd_1bit_case___024root___eval_debug_assertions(Vadd_1bit_case___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->c_i & 0xfeU))) {
        Verilated::overWidthError("c_i");}
    if (VL_UNLIKELY((vlSelf->a_i & 0xfeU))) {
        Verilated::overWidthError("a_i");}
    if (VL_UNLIKELY((vlSelf->b_i & 0xfeU))) {
        Verilated::overWidthError("b_i");}
}
#endif  // VL_DEBUG
