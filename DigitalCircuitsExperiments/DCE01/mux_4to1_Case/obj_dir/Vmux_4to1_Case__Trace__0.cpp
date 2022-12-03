// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux_4to1_Case__Syms.h"


void Vmux_4to1_Case___024root__trace_chg_sub_0(Vmux_4to1_Case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmux_4to1_Case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_4to1_Case___024root__trace_chg_top_0\n"); );
    // Init
    Vmux_4to1_Case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux_4to1_Case___024root*>(voidSelf);
    Vmux_4to1_Case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmux_4to1_Case___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vmux_4to1_Case___024root__trace_chg_sub_0(Vmux_4to1_Case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_4to1_Case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_4to1_Case___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->a),4);
    bufp->chgCData(oldp+1,(vlSelf->s),2);
    bufp->chgBit(oldp+2,(vlSelf->y));
}

void Vmux_4to1_Case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_4to1_Case___024root__trace_cleanup\n"); );
    // Init
    Vmux_4to1_Case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux_4to1_Case___024root*>(voidSelf);
    Vmux_4to1_Case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
