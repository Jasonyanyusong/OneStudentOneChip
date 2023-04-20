// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "verilated.h"

#include "VALU___024root.h"

VL_INLINE_OPT void VALU___024root___ico_sequent__TOP__0(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___ico_sequent__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h57ba592c__0;
    VlWide<4>/*127:0*/ __Vtemp_h58282069__0;
    VlWide<4>/*127:0*/ __Vtemp_h7123418b__0;
    VlWide<4>/*127:0*/ __Vtemp_h57f53372__0;
    VlWide<4>/*127:0*/ __Vtemp_h4a523f69__0;
    // Body
    VL_EXTEND_WQ(127,64, __Vtemp_h57ba592c__0, (vlSelf->io_DataInA 
                                                + vlSelf->io_DataInB));
    VL_EXTEND_WQ(127,64, __Vtemp_h58282069__0, (vlSelf->io_DataInA 
                                                - vlSelf->io_DataInB));
    VL_EXTEND_WQ(127,64, __Vtemp_h7123418b__0, (~ vlSelf->io_DataInA));
    VL_EXTEND_WQ(127,64, __Vtemp_h57f53372__0, (vlSelf->io_DataInA 
                                                & vlSelf->io_DataInB));
    VL_EXTEND_WQ(127,64, __Vtemp_h4a523f69__0, vlSelf->io_DataInB);
    vlSelf->io_ALUResult = (((QData)((IData)(((1U & (IData)(vlSelf->io_OperateCode))
                                               ? __Vtemp_h57ba592c__0[1U]
                                               : ((2U 
                                                   & (IData)(vlSelf->io_OperateCode))
                                                   ? 
                                                  __Vtemp_h58282069__0[1U]
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->io_OperateCode))
                                                    ? 
                                                   __Vtemp_h7123418b__0[1U]
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->io_OperateCode))
                                                     ? 
                                                    __Vtemp_h57f53372__0[1U]
                                                     : 
                                                    __Vtemp_h4a523f69__0[1U])))))) 
                             << 0x20U) | (QData)((IData)(
                                                         ((1U 
                                                           & (IData)(vlSelf->io_OperateCode))
                                                           ? 
                                                          __Vtemp_h57ba592c__0[0U]
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelf->io_OperateCode))
                                                            ? 
                                                           __Vtemp_h58282069__0[0U]
                                                            : 
                                                           ((4U 
                                                             & (IData)(vlSelf->io_OperateCode))
                                                             ? 
                                                            __Vtemp_h7123418b__0[0U]
                                                             : 
                                                            ((8U 
                                                              & (IData)(vlSelf->io_OperateCode))
                                                              ? 
                                                             __Vtemp_h57f53372__0[0U]
                                                              : 
                                                             __Vtemp_h4a523f69__0[0U])))))));
}

void VALU___024root___eval_ico(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VALU___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VALU___024root___eval_act(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_act\n"); );
}

void VALU___024root___eval_nba(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_nba\n"); );
}

void VALU___024root___eval_triggers__ico(VALU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__ico(VALU___024root* vlSelf);
#endif  // VL_DEBUG
void VALU___024root___eval_triggers__act(VALU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__act(VALU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__nba(VALU___024root* vlSelf);
#endif  // VL_DEBUG

void VALU___024root___eval(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval\n"); );
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
        VALU___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VALU___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("ALU.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VALU___024root___eval_ico(vlSelf);
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
            VALU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VALU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("ALU.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VALU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VALU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("ALU.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VALU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VALU___024root___eval_debug_assertions(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_OperateCode & 0xf0U))) {
        Verilated::overWidthError("io_OperateCode");}
}
#endif  // VL_DEBUG
