// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_4bit_structure__Syms.h"


void Vadd_4bit_structure___024root__trace_chg_sub_0(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_4bit_structure___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_chg_top_0\n"); );
    // Init
    Vadd_4bit_structure___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_4bit_structure___024root*>(voidSelf);
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_4bit_structure___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_4bit_structure___024root__trace_chg_sub_0(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->add_4bit_structure__DOT__add0_1));
        bufp->chgBit(oldp+1,(vlSelf->add_4bit_structure__DOT__add1_2));
        bufp->chgBit(oldp+2,(vlSelf->add_4bit_structure__DOT__add2_3));
        bufp->chgBit(oldp+3,(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A));
        bufp->chgBit(oldp+4,(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B));
        bufp->chgBit(oldp+5,(vlSelf->add_4bit_structure__DOT__add0__DOT__c_iANDA_D));
        bufp->chgBit(oldp+6,(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A));
        bufp->chgBit(oldp+7,(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B));
        bufp->chgBit(oldp+8,(vlSelf->add_4bit_structure__DOT__add1__DOT__c_iANDA_D));
        bufp->chgBit(oldp+9,(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A));
        bufp->chgBit(oldp+10,(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B));
        bufp->chgBit(oldp+11,(vlSelf->add_4bit_structure__DOT__add2__DOT__c_iANDA_D));
        bufp->chgBit(oldp+12,(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A));
        bufp->chgBit(oldp+13,(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B));
        bufp->chgBit(oldp+14,(vlSelf->add_4bit_structure__DOT__add3__DOT__c_iANDA_D));
    }
    bufp->chgBit(oldp+15,(vlSelf->a_0));
    bufp->chgBit(oldp+16,(vlSelf->b_0));
    bufp->chgBit(oldp+17,(vlSelf->c_in));
    bufp->chgBit(oldp+18,(vlSelf->a_1));
    bufp->chgBit(oldp+19,(vlSelf->b_1));
    bufp->chgBit(oldp+20,(vlSelf->c_1));
    bufp->chgBit(oldp+21,(vlSelf->a_2));
    bufp->chgBit(oldp+22,(vlSelf->b_2));
    bufp->chgBit(oldp+23,(vlSelf->c_2));
    bufp->chgBit(oldp+24,(vlSelf->a_3));
    bufp->chgBit(oldp+25,(vlSelf->b_3));
    bufp->chgBit(oldp+26,(vlSelf->c_3));
    bufp->chgBit(oldp+27,(vlSelf->s_0));
    bufp->chgBit(oldp+28,(vlSelf->s_1));
    bufp->chgBit(oldp+29,(vlSelf->s_2));
    bufp->chgBit(oldp+30,(vlSelf->s_3));
    bufp->chgBit(oldp+31,(vlSelf->c_out));
}

void Vadd_4bit_structure___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_cleanup\n"); );
    // Init
    Vadd_4bit_structure___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_4bit_structure___024root*>(voidSelf);
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
