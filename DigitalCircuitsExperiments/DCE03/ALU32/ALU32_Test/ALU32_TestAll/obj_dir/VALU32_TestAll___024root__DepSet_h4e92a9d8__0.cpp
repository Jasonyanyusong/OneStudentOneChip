// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_TestAll.h for the primary calling header

#include "verilated.h"

#include "VALU32_TestAll___024root.h"

VL_INLINE_OPT void VALU32_TestAll___024root___ico_sequent__TOP__0(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->carry = (1U & ((vlSelf->a & vlSelf->b) 
                           >> 0x1eU));
    vlSelf->ALU32_TestAll__DOT__b_withCin = (((- (IData)((IData)(vlSelf->sub_add))) 
                                              ^ vlSelf->b) 
                                             + (IData)(vlSelf->sub_add));
    vlSelf->result = (vlSelf->a + vlSelf->ALU32_TestAll__DOT__b_withCin);
    vlSelf->overflow = (((vlSelf->a >> 0x1fU) == (vlSelf->ALU32_TestAll__DOT__b_withCin 
                                                  >> 0x1fU)) 
                        & ((vlSelf->result >> 0x1fU) 
                           != (vlSelf->a >> 0x1fU)));
    vlSelf->zero = (1U & (~ (IData)((0U != vlSelf->result))));
}

void VALU32_TestAll___024root___eval_ico(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VALU32_TestAll___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VALU32_TestAll___024root___eval_act(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___eval_act\n"); );
}

void VALU32_TestAll___024root___eval_nba(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___eval_nba\n"); );
}

void VALU32_TestAll___024root___eval_triggers__ico(VALU32_TestAll___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestAll___024root___dump_triggers__ico(VALU32_TestAll___024root* vlSelf);
#endif  // VL_DEBUG
void VALU32_TestAll___024root___eval_triggers__act(VALU32_TestAll___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestAll___024root___dump_triggers__act(VALU32_TestAll___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestAll___024root___dump_triggers__nba(VALU32_TestAll___024root* vlSelf);
#endif  // VL_DEBUG

void VALU32_TestAll___024root___eval(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___eval\n"); );
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
        VALU32_TestAll___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VALU32_TestAll___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("ALU32_TestAll.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VALU32_TestAll___024root___eval_ico(vlSelf);
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
            VALU32_TestAll___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VALU32_TestAll___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("ALU32_TestAll.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VALU32_TestAll___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VALU32_TestAll___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("ALU32_TestAll.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VALU32_TestAll___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VALU32_TestAll___024root___eval_debug_assertions(VALU32_TestAll___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sub_add & 0xfeU))) {
        Verilated::overWidthError("sub_add");}
}
#endif  // VL_DEBUG
