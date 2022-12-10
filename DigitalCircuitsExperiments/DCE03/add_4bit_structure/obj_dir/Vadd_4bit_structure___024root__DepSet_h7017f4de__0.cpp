// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_4bit_structure.h for the primary calling header

#include "verilated.h"

#include "Vadd_4bit_structure___024root.h"

extern const VlUnpacked<CData/*0:0*/, 4> Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0;
extern const VlUnpacked<CData/*0:0*/, 4> Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0;
extern const VlUnpacked<CData/*0:0*/, 4> Vadd_4bit_structure__ConstPool__TABLE_h4881bd17_0;

VL_INLINE_OPT void Vadd_4bit_structure___024root___ico_sequent__TOP__0(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vtableidx1;
    CData/*1:0*/ __Vtableidx2;
    CData/*1:0*/ __Vtableidx3;
    CData/*1:0*/ __Vtableidx4;
    CData/*1:0*/ __Vtableidx5;
    CData/*1:0*/ __Vtableidx6;
    CData/*1:0*/ __Vtableidx7;
    CData/*1:0*/ __Vtableidx8;
    CData/*1:0*/ __Vtableidx9;
    CData/*1:0*/ __Vtableidx10;
    CData/*1:0*/ __Vtableidx11;
    CData/*1:0*/ __Vtableidx12;
    CData/*1:0*/ __Vtableidx13;
    CData/*1:0*/ __Vtableidx14;
    CData/*1:0*/ __Vtableidx15;
    CData/*1:0*/ __Vtableidx16;
    CData/*1:0*/ __Vtableidx17;
    CData/*1:0*/ __Vtableidx18;
    CData/*1:0*/ __Vtableidx19;
    CData/*1:0*/ __Vtableidx20;
    // Body
    __Vtableidx17 = (((IData)(vlSelf->b_3) << 1U) | (IData)(vlSelf->a_3));
    vlSelf->add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx17];
    __Vtableidx16 = (((IData)(vlSelf->b_3) << 1U) | (IData)(vlSelf->a_3));
    vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A 
        = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx16];
    __Vtableidx12 = (((IData)(vlSelf->b_2) << 1U) | (IData)(vlSelf->a_2));
    vlSelf->add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx12];
    __Vtableidx11 = (((IData)(vlSelf->b_2) << 1U) | (IData)(vlSelf->a_2));
    vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A 
        = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx11];
    __Vtableidx7 = (((IData)(vlSelf->b_1) << 1U) | (IData)(vlSelf->a_1));
    vlSelf->add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx7];
    __Vtableidx6 = (((IData)(vlSelf->b_1) << 1U) | (IData)(vlSelf->a_1));
    vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A 
        = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx6];
    __Vtableidx2 = (((IData)(vlSelf->b_0) << 1U) | (IData)(vlSelf->a_0));
    vlSelf->add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx2];
    __Vtableidx1 = (((IData)(vlSelf->b_0) << 1U) | (IData)(vlSelf->a_0));
    vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A 
        = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx1];
    __Vtableidx3 = (((IData)(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A) 
                     << 1U) | (IData)(vlSelf->c_in));
    vlSelf->s_0 = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx3];
    __Vtableidx4 = (((IData)(vlSelf->c_in) << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A));
    vlSelf->add_4bit_structure__DOT__add0__DOT__c_iANDA_D 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx4];
    __Vtableidx5 = (((IData)(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B) 
                     << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add0__DOT__c_iANDA_D));
    vlSelf->add_4bit_structure__DOT__add0_1 = Vadd_4bit_structure__ConstPool__TABLE_h4881bd17_0
        [__Vtableidx5];
    __Vtableidx8 = (((IData)(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A) 
                     << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add0_1));
    vlSelf->s_1 = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx8];
    __Vtableidx9 = (((IData)(vlSelf->add_4bit_structure__DOT__add0_1) 
                     << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A));
    vlSelf->add_4bit_structure__DOT__add1__DOT__c_iANDA_D 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx9];
    __Vtableidx10 = (((IData)(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add1__DOT__c_iANDA_D));
    vlSelf->add_4bit_structure__DOT__add1_2 = Vadd_4bit_structure__ConstPool__TABLE_h4881bd17_0
        [__Vtableidx10];
    __Vtableidx13 = (((IData)(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add1_2));
    vlSelf->s_2 = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx13];
    __Vtableidx14 = (((IData)(vlSelf->add_4bit_structure__DOT__add1_2) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A));
    vlSelf->add_4bit_structure__DOT__add2__DOT__c_iANDA_D 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx14];
    __Vtableidx15 = (((IData)(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add2__DOT__c_iANDA_D));
    vlSelf->add_4bit_structure__DOT__add2_3 = Vadd_4bit_structure__ConstPool__TABLE_h4881bd17_0
        [__Vtableidx15];
    __Vtableidx18 = (((IData)(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add2_3));
    vlSelf->s_3 = Vadd_4bit_structure__ConstPool__TABLE_h4903c59f_0
        [__Vtableidx18];
    __Vtableidx19 = (((IData)(vlSelf->add_4bit_structure__DOT__add2_3) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A));
    vlSelf->add_4bit_structure__DOT__add3__DOT__c_iANDA_D 
        = Vadd_4bit_structure__ConstPool__TABLE_hea96f6d0_0
        [__Vtableidx19];
    __Vtableidx20 = (((IData)(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B) 
                      << 1U) | (IData)(vlSelf->add_4bit_structure__DOT__add3__DOT__c_iANDA_D));
    vlSelf->c_out = Vadd_4bit_structure__ConstPool__TABLE_h4881bd17_0
        [__Vtableidx20];
}

void Vadd_4bit_structure___024root___eval_ico(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vadd_4bit_structure___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vadd_4bit_structure___024root___eval_act(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_act\n"); );
}

void Vadd_4bit_structure___024root___eval_nba(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_nba\n"); );
}

void Vadd_4bit_structure___024root___eval_triggers__ico(Vadd_4bit_structure___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__ico(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_4bit_structure___024root___eval_triggers__act(Vadd_4bit_structure___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__act(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__nba(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_4bit_structure___024root___eval(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval\n"); );
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
        Vadd_4bit_structure___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vadd_4bit_structure___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("add_4bit_structure.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vadd_4bit_structure___024root___eval_ico(vlSelf);
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
            Vadd_4bit_structure___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vadd_4bit_structure___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("add_4bit_structure.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vadd_4bit_structure___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vadd_4bit_structure___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("add_4bit_structure.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vadd_4bit_structure___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vadd_4bit_structure___024root___eval_debug_assertions(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a_0 & 0xfeU))) {
        Verilated::overWidthError("a_0");}
    if (VL_UNLIKELY((vlSelf->b_0 & 0xfeU))) {
        Verilated::overWidthError("b_0");}
    if (VL_UNLIKELY((vlSelf->c_in & 0xfeU))) {
        Verilated::overWidthError("c_in");}
    if (VL_UNLIKELY((vlSelf->a_1 & 0xfeU))) {
        Verilated::overWidthError("a_1");}
    if (VL_UNLIKELY((vlSelf->b_1 & 0xfeU))) {
        Verilated::overWidthError("b_1");}
    if (VL_UNLIKELY((vlSelf->c_1 & 0xfeU))) {
        Verilated::overWidthError("c_1");}
    if (VL_UNLIKELY((vlSelf->a_2 & 0xfeU))) {
        Verilated::overWidthError("a_2");}
    if (VL_UNLIKELY((vlSelf->b_2 & 0xfeU))) {
        Verilated::overWidthError("b_2");}
    if (VL_UNLIKELY((vlSelf->c_2 & 0xfeU))) {
        Verilated::overWidthError("c_2");}
    if (VL_UNLIKELY((vlSelf->a_3 & 0xfeU))) {
        Verilated::overWidthError("a_3");}
    if (VL_UNLIKELY((vlSelf->b_3 & 0xfeU))) {
        Verilated::overWidthError("b_3");}
    if (VL_UNLIKELY((vlSelf->c_3 & 0xfeU))) {
        Verilated::overWidthError("c_3");}
}
#endif  // VL_DEBUG
