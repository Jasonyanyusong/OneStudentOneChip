// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVHM__02dRISCV64IM.h for the primary calling header

#include "verilated.h"

#include "VVHM__02dRISCV64IM___024root.h"

void VVHM__02dRISCV64IM___024root___eval_act(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_act\n"); );
}

VL_INLINE_OPT void VVHM__02dRISCV64IM___024root___nba_sequent__TOP__0(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ RV64IM_VHM__DOT__opcode;
    CData/*4:0*/ RV64IM_VHM__DOT__rd;
    CData/*2:0*/ RV64IM_VHM__DOT__funct3;
    IData/*31:0*/ RV64IM_VHM__DOT__imm_U;
    IData/*20:0*/ RV64IM_VHM__DOT__imm_J;
    VlUnpacked<QData/*63:0*/, 32> RV64IM_VHM__DOT__sim_integer_register;
    // Body
    RV64IM_VHM__DOT__opcode = (0x7fU & vlSelf->riscv_32bits_instruction);
    RV64IM_VHM__DOT__funct3 = (7U & (vlSelf->riscv_32bits_instruction 
                                     >> 0xcU));
    RV64IM_VHM__DOT__imm_J = ((0x7ffU & RV64IM_VHM__DOT__imm_J) 
                              | ((0x100000U & (vlSelf->riscv_32bits_instruction 
                                               >> 0xbU)) 
                                 | ((0xff000U & vlSelf->riscv_32bits_instruction) 
                                    | (0x800U & (vlSelf->riscv_32bits_instruction 
                                                 >> 9U)))));
    RV64IM_VHM__DOT__rd = (0x1fU & (vlSelf->riscv_32bits_instruction 
                                    >> 7U));
    RV64IM_VHM__DOT__imm_J = ((0x1ff800U & RV64IM_VHM__DOT__imm_J) 
                              | (0x7feU & (vlSelf->riscv_32bits_instruction 
                                           >> 0x14U)));
    RV64IM_VHM__DOT__imm_U = (0xfffff000U & vlSelf->riscv_32bits_instruction);
    if ((0x40U & (IData)(RV64IM_VHM__DOT__opcode))) {
        if ((0x20U & (IData)(RV64IM_VHM__DOT__opcode))) {
            if ((0x10U & (IData)(RV64IM_VHM__DOT__opcode))) {
                vlSelf->vhm_status = 1U;
            } else if ((8U & (IData)(RV64IM_VHM__DOT__opcode))) {
                if ((4U & (IData)(RV64IM_VHM__DOT__opcode))) {
                    if ((2U & (IData)(RV64IM_VHM__DOT__opcode))) {
                        if ((1U & (IData)(RV64IM_VHM__DOT__opcode))) {
                            RV64IM_VHM__DOT__sim_integer_register[RV64IM_VHM__DOT__rd] 
                                = (4ULL + vlSelf->RV64IM_VHM__DOT__vhm_pc);
                            vlSelf->vhm_status = 0U;
                        } else {
                            vlSelf->vhm_status = 1U;
                        }
                    } else {
                        vlSelf->vhm_status = 1U;
                    }
                } else {
                    vlSelf->vhm_status = 1U;
                }
            } else if ((4U & (IData)(RV64IM_VHM__DOT__opcode))) {
                if ((2U & (IData)(RV64IM_VHM__DOT__opcode))) {
                    if ((1U & (IData)(RV64IM_VHM__DOT__opcode))) {
                        if ((0U == (IData)(RV64IM_VHM__DOT__funct3))) {
                            RV64IM_VHM__DOT__sim_integer_register[RV64IM_VHM__DOT__rd] 
                                = (4ULL + vlSelf->RV64IM_VHM__DOT__vhm_pc);
                            vlSelf->vhm_status = 0U;
                        } else {
                            vlSelf->vhm_status = 1U;
                        }
                    } else {
                        vlSelf->vhm_status = 1U;
                    }
                } else {
                    vlSelf->vhm_status = 1U;
                }
            } else {
                vlSelf->vhm_status = 1U;
            }
        } else {
            vlSelf->vhm_status = 1U;
        }
    } else if ((0x20U & (IData)(RV64IM_VHM__DOT__opcode))) {
        if ((0x10U & (IData)(RV64IM_VHM__DOT__opcode))) {
            if ((8U & (IData)(RV64IM_VHM__DOT__opcode))) {
                vlSelf->vhm_status = 1U;
            } else if ((4U & (IData)(RV64IM_VHM__DOT__opcode))) {
                if ((2U & (IData)(RV64IM_VHM__DOT__opcode))) {
                    if ((1U & (IData)(RV64IM_VHM__DOT__opcode))) {
                        RV64IM_VHM__DOT__sim_integer_register[RV64IM_VHM__DOT__rd] 
                            = (QData)((IData)(RV64IM_VHM__DOT__imm_U));
                        vlSelf->vhm_status = 0U;
                    } else {
                        vlSelf->vhm_status = 1U;
                    }
                } else {
                    vlSelf->vhm_status = 1U;
                }
            } else {
                vlSelf->vhm_status = 1U;
            }
        } else {
            vlSelf->vhm_status = 1U;
        }
    } else if ((0x10U & (IData)(RV64IM_VHM__DOT__opcode))) {
        if ((8U & (IData)(RV64IM_VHM__DOT__opcode))) {
            vlSelf->vhm_status = 1U;
        } else if ((4U & (IData)(RV64IM_VHM__DOT__opcode))) {
            if ((2U & (IData)(RV64IM_VHM__DOT__opcode))) {
                if ((1U & (IData)(RV64IM_VHM__DOT__opcode))) {
                    RV64IM_VHM__DOT__sim_integer_register[RV64IM_VHM__DOT__rd] 
                        = (vlSelf->RV64IM_VHM__DOT__vhm_pc 
                           + (QData)((IData)(RV64IM_VHM__DOT__imm_U)));
                    vlSelf->vhm_status = 0U;
                } else {
                    vlSelf->vhm_status = 1U;
                }
            } else {
                vlSelf->vhm_status = 1U;
            }
        } else {
            vlSelf->vhm_status = 1U;
        }
    } else {
        vlSelf->vhm_status = 1U;
    }
    RV64IM_VHM__DOT__sim_integer_register[0U] = 0ULL;
}

void VVHM__02dRISCV64IM___024root___eval_nba(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VVHM__02dRISCV64IM___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VVHM__02dRISCV64IM___024root___eval_triggers__act(VVHM__02dRISCV64IM___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___dump_triggers__act(VVHM__02dRISCV64IM___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VVHM__02dRISCV64IM___024root___dump_triggers__nba(VVHM__02dRISCV64IM___024root* vlSelf);
#endif  // VL_DEBUG

void VVHM__02dRISCV64IM___024root___eval(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval\n"); );
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
            VVHM__02dRISCV64IM___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VVHM__02dRISCV64IM___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("VHM-RISCV64IM.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VVHM__02dRISCV64IM___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VVHM__02dRISCV64IM___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("VHM-RISCV64IM.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VVHM__02dRISCV64IM___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VVHM__02dRISCV64IM___024root___eval_debug_assertions(VVHM__02dRISCV64IM___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVHM__02dRISCV64IM__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVHM__02dRISCV64IM___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
