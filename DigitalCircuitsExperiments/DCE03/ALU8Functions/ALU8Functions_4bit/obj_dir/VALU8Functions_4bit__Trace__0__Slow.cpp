// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU8Functions_4bit__Syms.h"


VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_init_sub__TOP__0(VALU8Functions_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_4bit___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"input_mode_select", false,-1, 2,0);
    tracep->declBus(c+2,"input_a", false,-1, 3,0);
    tracep->declBus(c+3,"input_b", false,-1, 3,0);
    tracep->declBus(c+4,"output_result", false,-1, 3,0);
    tracep->pushNamePrefix("ALU8Functions_4bit ");
    tracep->declBus(c+1,"input_mode_select", false,-1, 2,0);
    tracep->declBus(c+2,"input_a", false,-1, 3,0);
    tracep->declBus(c+3,"input_b", false,-1, 3,0);
    tracep->declBus(c+4,"output_result", false,-1, 3,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_init_top(VALU8Functions_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_4bit___024root__trace_init_top\n"); );
    // Body
    VALU8Functions_4bit___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU8Functions_4bit___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VALU8Functions_4bit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_register(VALU8Functions_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_4bit___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VALU8Functions_4bit___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VALU8Functions_4bit___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VALU8Functions_4bit___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_full_sub_0(VALU8Functions_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_4bit___024root__trace_full_top_0\n"); );
    // Init
    VALU8Functions_4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU8Functions_4bit___024root*>(voidSelf);
    VALU8Functions_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VALU8Functions_4bit___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VALU8Functions_4bit___024root__trace_full_sub_0(VALU8Functions_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_4bit___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->input_mode_select),3);
    bufp->fullCData(oldp+2,(vlSelf->input_a),4);
    bufp->fullCData(oldp+3,(vlSelf->input_b),4);
    bufp->fullCData(oldp+4,(vlSelf->output_result),4);
}
