// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU8Functions_8bit__Syms.h"


void VALU8Functions_8bit___024root__trace_chg_sub_0(VALU8Functions_8bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VALU8Functions_8bit___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_8bit___024root__trace_chg_top_0\n"); );
    // Init
    VALU8Functions_8bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU8Functions_8bit___024root*>(voidSelf);
    VALU8Functions_8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VALU8Functions_8bit___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VALU8Functions_8bit___024root__trace_chg_sub_0(VALU8Functions_8bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_8bit___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->input_mode_select),3);
    bufp->chgCData(oldp+1,(vlSelf->input_a),8);
    bufp->chgCData(oldp+2,(vlSelf->input_b),8);
    bufp->chgCData(oldp+3,(vlSelf->output_result),8);
}

void VALU8Functions_8bit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_8bit___024root__trace_cleanup\n"); );
    // Init
    VALU8Functions_8bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU8Functions_8bit___024root*>(voidSelf);
    VALU8Functions_8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
