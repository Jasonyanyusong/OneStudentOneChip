// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU32_TestAll__Syms.h"


VL_ATTR_COLD void VALU32_TestAll___024root__trace_init_sub__TOP__0(VALU32_TestAll___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"sub_add", false,-1);
    tracep->declBus(c+2,"a", false,-1, 31,0);
    tracep->declBus(c+3,"b", false,-1, 31,0);
    tracep->declBus(c+4,"carry", false,-1, 0,0);
    tracep->declBit(c+5,"zero", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBus(c+7,"result", false,-1, 31,0);
    tracep->pushNamePrefix("ALU32_TestAll ");
    tracep->declBit(c+1,"sub_add", false,-1);
    tracep->declBus(c+2,"a", false,-1, 31,0);
    tracep->declBus(c+3,"b", false,-1, 31,0);
    tracep->declBus(c+4,"carry", false,-1, 0,0);
    tracep->declBit(c+5,"zero", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBus(c+7,"result", false,-1, 31,0);
    tracep->declBus(c+8,"b_withCin", false,-1, 31,0);
    tracep->declBus(c+9,"testF1S1B1T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B1T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B1T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B1T1_expected_overflow", false,-1);
    tracep->declBus(c+11,"testF1S1B1T2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B1T2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B1T2_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B1T2_expected_overflow", false,-1);
    tracep->declBus(c+12,"testF1S1B1T3_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B1T3_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B1T3_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B1T3_expected_overflow", false,-1);
    tracep->declBus(c+13,"testF1S1B2T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B2T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B2T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B2T1_expected_overflow", false,-1);
    tracep->declBus(c+11,"testF1S1B2T2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B2T2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B2T2_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B2T2_expected_overflow", false,-1);
    tracep->declBus(c+14,"testF1S1B3T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B3T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B3T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B3T1_expected_overflow", false,-1);
    tracep->declBus(c+11,"testF1S1B3T2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S1B3T2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S1B3T2_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S1B3T2_expected_overflow", false,-1);
    tracep->declBus(c+15,"testF1S2B1T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF1S2B1T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF1S2B1T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF1S2B1T1_expected_overflow", false,-1);
    tracep->declBus(c+13,"testF2S1B1T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B1T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF2S1B1T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF2S1B1T1_expected_overflow", false,-1);
    tracep->declBus(c+9,"testF2S1B2T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B2T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF2S1B2T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF2S1B2T1_expected_overflow", false,-1);
    tracep->declBus(c+11,"testF2S1B2T2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B2T2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+16,"testF2S1B1T2_expected_zero", false,-1);
    tracep->declBit(c+17,"testF2S1B1T2_expected_overflow", false,-1);
    tracep->declBit(c+10,"testF2S1B2T2_expected_overflow", false,-1);
    tracep->declBit(c+10,"testF2S1B2T2_expected_zero", false,-1);
    tracep->declBus(c+18,"testF2S1B2T3_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B2T3_expected_carry", false,-1, 0,0);
    tracep->declBit(c+19,"testF2S1B1T3_expected_zero", false,-1);
    tracep->declBit(c+20,"testF2S1B1T3_expected_overflow", false,-1);
    tracep->declBit(c+10,"testF2S1B2T3_expected_overflow", false,-1);
    tracep->declBit(c+10,"testF2S1B2T3_expected_zero", false,-1);
    tracep->declBus(c+18,"testF2S1B3T1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B3T1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF2S1B3T1_expected_zero", false,-1);
    tracep->declBit(c+10,"testF2S1B3T1_expected_overflow", false,-1);
    tracep->declBus(c+11,"testF2S1B3T2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B3T2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF2S1B3T2_expected_zero", false,-1);
    tracep->declBit(c+10,"testF2S1B3T2_expected_overflow", false,-1);
    tracep->declBus(c+9,"testF2S1B3T3_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"testF2S1B3T3_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"testF2S1B3T3_expected_zero", false,-1);
    tracep->declBit(c+10,"testF2S1B3T3_expected_overflow", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VALU32_TestAll___024root__trace_init_top(VALU32_TestAll___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root__trace_init_top\n"); );
    // Body
    VALU32_TestAll___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VALU32_TestAll___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU32_TestAll___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU32_TestAll___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VALU32_TestAll___024root__trace_register(VALU32_TestAll___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VALU32_TestAll___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VALU32_TestAll___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VALU32_TestAll___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VALU32_TestAll___024root__trace_full_sub_0(VALU32_TestAll___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VALU32_TestAll___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root__trace_full_top_0\n"); );
    // Init
    VALU32_TestAll___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32_TestAll___024root*>(voidSelf);
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VALU32_TestAll___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VALU32_TestAll___024root__trace_full_sub_0(VALU32_TestAll___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestAll__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestAll___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->sub_add));
    bufp->fullIData(oldp+2,(vlSelf->a),32);
    bufp->fullIData(oldp+3,(vlSelf->b),32);
    bufp->fullBit(oldp+4,(vlSelf->carry));
    bufp->fullBit(oldp+5,(vlSelf->zero));
    bufp->fullBit(oldp+6,(vlSelf->overflow));
    bufp->fullIData(oldp+7,(vlSelf->result),32);
    bufp->fullIData(oldp+8,(vlSelf->ALU32_TestAll__DOT__b_withCin),32);
    bufp->fullIData(oldp+9,(0x33829b9cU),32);
    bufp->fullBit(oldp+10,(0U));
    bufp->fullIData(oldp+11,(0U),32);
    bufp->fullIData(oldp+12,(0xf14865dfU),32);
    bufp->fullIData(oldp+13,(0x423a35c6U),32);
    bufp->fullIData(oldp+14,(0xbdc5ca3aU),32);
    bufp->fullIData(oldp+15,(0x46aea154U),32);
    bufp->fullBit(oldp+16,(vlSelf->ALU32_TestAll__DOT__testF2S1B1T2_expected_zero));
    bufp->fullBit(oldp+17,(vlSelf->ALU32_TestAll__DOT__testF2S1B1T2_expected_overflow));
    bufp->fullIData(oldp+18,(0xcc7d6464U),32);
    bufp->fullBit(oldp+19,(vlSelf->ALU32_TestAll__DOT__testF2S1B1T3_expected_zero));
    bufp->fullBit(oldp+20,(vlSelf->ALU32_TestAll__DOT__testF2S1B1T3_expected_overflow));
}
