// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU32_Test__Syms.h"


VL_ATTR_COLD void VALU32_Test___024root__trace_init_sub__TOP__0(VALU32_Test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root__trace_init_sub__TOP__0\n"); );
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
    tracep->pushNamePrefix("ALU32_Test ");
    tracep->declBit(c+1,"sub_add", false,-1);
    tracep->declBus(c+2,"a", false,-1, 31,0);
    tracep->declBus(c+3,"b", false,-1, 31,0);
    tracep->declBus(c+4,"carry", false,-1, 0,0);
    tracep->declBit(c+5,"zero", false,-1);
    tracep->declBit(c+6,"overflow", false,-1);
    tracep->declBus(c+7,"result", false,-1, 31,0);
    tracep->declBus(c+8,"b_withCin", false,-1, 31,0);
    tracep->declBus(c+9,"test1_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"test1_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"test1_expected_zero", false,-1);
    tracep->declBit(c+10,"test1_expected_overflow", false,-1);
    tracep->declBus(c+11,"test2_expected_result", false,-1, 31,0);
    tracep->declBus(c+10,"test2_expected_carry", false,-1, 0,0);
    tracep->declBit(c+10,"test2_expected_zero", false,-1);
    tracep->declBit(c+10,"test2_expected_overflow", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VALU32_Test___024root__trace_init_top(VALU32_Test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root__trace_init_top\n"); );
    // Body
    VALU32_Test___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VALU32_Test___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU32_Test___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU32_Test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VALU32_Test___024root__trace_register(VALU32_Test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VALU32_Test___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VALU32_Test___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VALU32_Test___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VALU32_Test___024root__trace_full_sub_0(VALU32_Test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VALU32_Test___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root__trace_full_top_0\n"); );
    // Init
    VALU32_Test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32_Test___024root*>(voidSelf);
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VALU32_Test___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VALU32_Test___024root__trace_full_sub_0(VALU32_Test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root__trace_full_sub_0\n"); );
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
    bufp->fullIData(oldp+8,(vlSelf->ALU32_Test__DOT__b_withCin),32);
    bufp->fullIData(oldp+9,(0x33829b9cU),32);
    bufp->fullBit(oldp+10,(0U));
    bufp->fullIData(oldp+11,(0xf14865dfU),32);
}
