// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMSPC_V_ALU.h for the primary calling header

#include "verilated.h"

#include "VMSPC_V_ALU___024root.h"

void VMSPC_V_ALU___024root___eval_act(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_act\n"); );
}

VL_INLINE_OPT void VMSPC_V_ALU___024root___nba_sequent__TOP__0(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___nba_sequent__TOP__0\n"); );
    // Body
    if ((8U & (IData)(vlSelf->sel))) {
        if ((4U & (IData)(vlSelf->sel))) {
            if ((1U & (~ ((IData)(vlSelf->sel) >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->sel)))) {
                    vlSelf->booloutp = (1U & (IData)(
                                                     VL_SHIFTR_QQQ(64,64,64, vlSelf->inpa, vlSelf->inpb)));
                }
            }
        } else if ((2U & (IData)(vlSelf->sel))) {
            vlSelf->booloutp = (1U & ((1U & (IData)(vlSelf->sel))
                                       ? (IData)(VL_SHIFTL_QQQ(64,64,64, vlSelf->inpa, vlSelf->inpb))
                                       : (IData)(VL_SHIFTR_QQQ(64,64,64, vlSelf->inpa, vlSelf->inpb))));
        }
    } else if ((4U & (IData)(vlSelf->sel))) {
        if ((2U & (IData)(vlSelf->sel))) {
            vlSelf->booloutp = ((1U & (IData)(vlSelf->sel))
                                 ? (vlSelf->inpa == vlSelf->inpb)
                                 : (vlSelf->inpa < vlSelf->inpb));
        }
    }
    if ((1U & (~ ((IData)(vlSelf->sel) >> 3U)))) {
        if ((4U & (IData)(vlSelf->sel))) {
            if ((1U & (~ ((IData)(vlSelf->sel) >> 1U)))) {
                vlSelf->numoutp = ((1U & (IData)(vlSelf->sel))
                                    ? (vlSelf->inpa 
                                       ^ vlSelf->inpb)
                                    : (vlSelf->inpa 
                                       | vlSelf->inpb));
            }
        } else {
            vlSelf->numoutp = ((2U & (IData)(vlSelf->sel))
                                ? ((1U & (IData)(vlSelf->sel))
                                    ? (vlSelf->inpa 
                                       & vlSelf->inpb)
                                    : (~ vlSelf->inpa))
                                : ((1U & (IData)(vlSelf->sel))
                                    ? (vlSelf->inpa 
                                       - vlSelf->inpb)
                                    : (vlSelf->inpa 
                                       + vlSelf->inpb)));
        }
    }
}

void VMSPC_V_ALU___024root___eval_nba(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VMSPC_V_ALU___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VMSPC_V_ALU___024root___eval_triggers__act(VMSPC_V_ALU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VMSPC_V_ALU___024root___dump_triggers__act(VMSPC_V_ALU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VMSPC_V_ALU___024root___dump_triggers__nba(VMSPC_V_ALU___024root* vlSelf);
#endif  // VL_DEBUG

void VMSPC_V_ALU___024root___eval(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval\n"); );
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
            VMSPC_V_ALU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VMSPC_V_ALU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("MSPC_V_ALU.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VMSPC_V_ALU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VMSPC_V_ALU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("MSPC_V_ALU.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VMSPC_V_ALU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VMSPC_V_ALU___024root___eval_debug_assertions(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sel & 0xf0U))) {
        Verilated::overWidthError("sel");}
}
#endif  // VL_DEBUG
