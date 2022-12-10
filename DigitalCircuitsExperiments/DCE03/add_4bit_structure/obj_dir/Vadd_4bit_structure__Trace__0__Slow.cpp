// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_4bit_structure__Syms.h"


VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_init_sub__TOP__0(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+16,"a_0", false,-1);
    tracep->declBit(c+17,"b_0", false,-1);
    tracep->declBit(c+18,"c_in", false,-1);
    tracep->declBit(c+19,"a_1", false,-1);
    tracep->declBit(c+20,"b_1", false,-1);
    tracep->declBit(c+21,"c_1", false,-1);
    tracep->declBit(c+22,"a_2", false,-1);
    tracep->declBit(c+23,"b_2", false,-1);
    tracep->declBit(c+24,"c_2", false,-1);
    tracep->declBit(c+25,"a_3", false,-1);
    tracep->declBit(c+26,"b_3", false,-1);
    tracep->declBit(c+27,"c_3", false,-1);
    tracep->declBit(c+28,"s_0", false,-1);
    tracep->declBit(c+29,"s_1", false,-1);
    tracep->declBit(c+30,"s_2", false,-1);
    tracep->declBit(c+31,"s_3", false,-1);
    tracep->declBit(c+32,"c_out", false,-1);
    tracep->pushNamePrefix("add_4bit_structure ");
    tracep->declBit(c+16,"a_0", false,-1);
    tracep->declBit(c+17,"b_0", false,-1);
    tracep->declBit(c+18,"c_in", false,-1);
    tracep->declBit(c+19,"a_1", false,-1);
    tracep->declBit(c+20,"b_1", false,-1);
    tracep->declBit(c+21,"c_1", false,-1);
    tracep->declBit(c+22,"a_2", false,-1);
    tracep->declBit(c+23,"b_2", false,-1);
    tracep->declBit(c+24,"c_2", false,-1);
    tracep->declBit(c+25,"a_3", false,-1);
    tracep->declBit(c+26,"b_3", false,-1);
    tracep->declBit(c+27,"c_3", false,-1);
    tracep->declBit(c+28,"s_0", false,-1);
    tracep->declBit(c+29,"s_1", false,-1);
    tracep->declBit(c+30,"s_2", false,-1);
    tracep->declBit(c+31,"s_3", false,-1);
    tracep->declBit(c+32,"c_out", false,-1);
    tracep->declBit(c+1,"add0_1", false,-1);
    tracep->declBit(c+2,"add1_2", false,-1);
    tracep->declBit(c+3,"add2_3", false,-1);
    tracep->pushNamePrefix("add0 ");
    tracep->declBit(c+18,"c_i", false,-1);
    tracep->declBit(c+16,"a_i", false,-1);
    tracep->declBit(c+17,"b_i", false,-1);
    tracep->declBit(c+28,"s_i", false,-1);
    tracep->declBit(c+1,"c_iplus1", false,-1);
    tracep->declBit(c+4,"a_iEXORb_i_A", false,-1);
    tracep->declBit(c+5,"a_iANDb_i_B", false,-1);
    tracep->declBit(c+6,"c_iANDA_D", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBit(c+16,"a", false,-1);
    tracep->declBit(c+17,"b", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i2 ");
    tracep->declBit(c+16,"a", false,-1);
    tracep->declBit(c+17,"b", false,-1);
    tracep->declBit(c+5,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBit(c+18,"a", false,-1);
    tracep->declBit(c+4,"b", false,-1);
    tracep->declBit(c+28,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i4 ");
    tracep->declBit(c+4,"a", false,-1);
    tracep->declBit(c+18,"b", false,-1);
    tracep->declBit(c+6,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i5 ");
    tracep->declBit(c+6,"a", false,-1);
    tracep->declBit(c+5,"b", false,-1);
    tracep->declBit(c+1,"y", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("add1 ");
    tracep->declBit(c+1,"c_i", false,-1);
    tracep->declBit(c+19,"a_i", false,-1);
    tracep->declBit(c+20,"b_i", false,-1);
    tracep->declBit(c+29,"s_i", false,-1);
    tracep->declBit(c+2,"c_iplus1", false,-1);
    tracep->declBit(c+7,"a_iEXORb_i_A", false,-1);
    tracep->declBit(c+8,"a_iANDb_i_B", false,-1);
    tracep->declBit(c+9,"c_iANDA_D", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBit(c+19,"a", false,-1);
    tracep->declBit(c+20,"b", false,-1);
    tracep->declBit(c+7,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i2 ");
    tracep->declBit(c+19,"a", false,-1);
    tracep->declBit(c+20,"b", false,-1);
    tracep->declBit(c+8,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+7,"b", false,-1);
    tracep->declBit(c+29,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i4 ");
    tracep->declBit(c+7,"a", false,-1);
    tracep->declBit(c+1,"b", false,-1);
    tracep->declBit(c+9,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i5 ");
    tracep->declBit(c+9,"a", false,-1);
    tracep->declBit(c+8,"b", false,-1);
    tracep->declBit(c+2,"y", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("add2 ");
    tracep->declBit(c+2,"c_i", false,-1);
    tracep->declBit(c+22,"a_i", false,-1);
    tracep->declBit(c+23,"b_i", false,-1);
    tracep->declBit(c+30,"s_i", false,-1);
    tracep->declBit(c+3,"c_iplus1", false,-1);
    tracep->declBit(c+10,"a_iEXORb_i_A", false,-1);
    tracep->declBit(c+11,"a_iANDb_i_B", false,-1);
    tracep->declBit(c+12,"c_iANDA_D", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBit(c+22,"a", false,-1);
    tracep->declBit(c+23,"b", false,-1);
    tracep->declBit(c+10,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i2 ");
    tracep->declBit(c+22,"a", false,-1);
    tracep->declBit(c+23,"b", false,-1);
    tracep->declBit(c+11,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBit(c+2,"a", false,-1);
    tracep->declBit(c+10,"b", false,-1);
    tracep->declBit(c+30,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i4 ");
    tracep->declBit(c+10,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+12,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i5 ");
    tracep->declBit(c+12,"a", false,-1);
    tracep->declBit(c+11,"b", false,-1);
    tracep->declBit(c+3,"y", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("add3 ");
    tracep->declBit(c+3,"c_i", false,-1);
    tracep->declBit(c+25,"a_i", false,-1);
    tracep->declBit(c+26,"b_i", false,-1);
    tracep->declBit(c+31,"s_i", false,-1);
    tracep->declBit(c+32,"c_iplus1", false,-1);
    tracep->declBit(c+13,"a_iEXORb_i_A", false,-1);
    tracep->declBit(c+14,"a_iANDb_i_B", false,-1);
    tracep->declBit(c+15,"c_iANDA_D", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBit(c+25,"a", false,-1);
    tracep->declBit(c+26,"b", false,-1);
    tracep->declBit(c+13,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i2 ");
    tracep->declBit(c+25,"a", false,-1);
    tracep->declBit(c+26,"b", false,-1);
    tracep->declBit(c+14,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBit(c+3,"a", false,-1);
    tracep->declBit(c+13,"b", false,-1);
    tracep->declBit(c+31,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i4 ");
    tracep->declBit(c+13,"a", false,-1);
    tracep->declBit(c+3,"b", false,-1);
    tracep->declBit(c+15,"y", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i5 ");
    tracep->declBit(c+15,"a", false,-1);
    tracep->declBit(c+14,"b", false,-1);
    tracep->declBit(c+32,"y", false,-1);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_init_top(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_init_top\n"); );
    // Body
    Vadd_4bit_structure___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_4bit_structure___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_4bit_structure___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_register(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd_4bit_structure___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd_4bit_structure___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd_4bit_structure___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_full_sub_0(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_full_top_0\n"); );
    // Init
    Vadd_4bit_structure___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_4bit_structure___024root*>(voidSelf);
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_4bit_structure___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_full_sub_0(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->add_4bit_structure__DOT__add0_1));
    bufp->fullBit(oldp+2,(vlSelf->add_4bit_structure__DOT__add1_2));
    bufp->fullBit(oldp+3,(vlSelf->add_4bit_structure__DOT__add2_3));
    bufp->fullBit(oldp+4,(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A));
    bufp->fullBit(oldp+5,(vlSelf->add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B));
    bufp->fullBit(oldp+6,(vlSelf->add_4bit_structure__DOT__add0__DOT__c_iANDA_D));
    bufp->fullBit(oldp+7,(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A));
    bufp->fullBit(oldp+8,(vlSelf->add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B));
    bufp->fullBit(oldp+9,(vlSelf->add_4bit_structure__DOT__add1__DOT__c_iANDA_D));
    bufp->fullBit(oldp+10,(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A));
    bufp->fullBit(oldp+11,(vlSelf->add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B));
    bufp->fullBit(oldp+12,(vlSelf->add_4bit_structure__DOT__add2__DOT__c_iANDA_D));
    bufp->fullBit(oldp+13,(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A));
    bufp->fullBit(oldp+14,(vlSelf->add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B));
    bufp->fullBit(oldp+15,(vlSelf->add_4bit_structure__DOT__add3__DOT__c_iANDA_D));
    bufp->fullBit(oldp+16,(vlSelf->a_0));
    bufp->fullBit(oldp+17,(vlSelf->b_0));
    bufp->fullBit(oldp+18,(vlSelf->c_in));
    bufp->fullBit(oldp+19,(vlSelf->a_1));
    bufp->fullBit(oldp+20,(vlSelf->b_1));
    bufp->fullBit(oldp+21,(vlSelf->c_1));
    bufp->fullBit(oldp+22,(vlSelf->a_2));
    bufp->fullBit(oldp+23,(vlSelf->b_2));
    bufp->fullBit(oldp+24,(vlSelf->c_2));
    bufp->fullBit(oldp+25,(vlSelf->a_3));
    bufp->fullBit(oldp+26,(vlSelf->b_3));
    bufp->fullBit(oldp+27,(vlSelf->c_3));
    bufp->fullBit(oldp+28,(vlSelf->s_0));
    bufp->fullBit(oldp+29,(vlSelf->s_1));
    bufp->fullBit(oldp+30,(vlSelf->s_2));
    bufp->fullBit(oldp+31,(vlSelf->s_3));
    bufp->fullBit(oldp+32,(vlSelf->c_out));
}
