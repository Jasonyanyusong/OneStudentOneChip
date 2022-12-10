// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_datastream_2__Syms.h"


void Vadd_datastream_2___024root__trace_chg_sub_0(Vadd_datastream_2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_datastream_2___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_2___024root__trace_chg_top_0\n"); );
    // Init
    Vadd_datastream_2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_datastream_2___024root*>(voidSelf);
    Vadd_datastream_2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_datastream_2___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_datastream_2___024root__trace_chg_sub_0(Vadd_datastream_2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_2___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->in_x),2);
    bufp->chgCData(oldp+1,(vlSelf->in_y),2);
    bufp->chgCData(oldp+2,(vlSelf->out_s),2);
}

void Vadd_datastream_2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_2___024root__trace_cleanup\n"); );
    // Init
    Vadd_datastream_2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_datastream_2___024root*>(voidSelf);
    Vadd_datastream_2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
