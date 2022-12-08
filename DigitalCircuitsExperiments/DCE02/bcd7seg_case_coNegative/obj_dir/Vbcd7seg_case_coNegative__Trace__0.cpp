// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbcd7seg_case_coNegative__Syms.h"


void Vbcd7seg_case_coNegative___024root__trace_chg_sub_0(Vbcd7seg_case_coNegative___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vbcd7seg_case_coNegative___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coNegative___024root__trace_chg_top_0\n"); );
    // Init
    Vbcd7seg_case_coNegative___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcd7seg_case_coNegative___024root*>(voidSelf);
    Vbcd7seg_case_coNegative__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbcd7seg_case_coNegative___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vbcd7seg_case_coNegative___024root__trace_chg_sub_0(Vbcd7seg_case_coNegative___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coNegative__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coNegative___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->b),4);
    bufp->chgCData(oldp+1,(vlSelf->h),7);
}

void Vbcd7seg_case_coNegative___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coNegative___024root__trace_cleanup\n"); );
    // Init
    Vbcd7seg_case_coNegative___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcd7seg_case_coNegative___024root*>(voidSelf);
    Vbcd7seg_case_coNegative__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
