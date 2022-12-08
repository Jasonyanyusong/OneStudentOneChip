// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode_32to5_for__Syms.h"


void Vencode_32to5_for___024root__trace_chg_sub_0(Vencode_32to5_for___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vencode_32to5_for___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root__trace_chg_top_0\n"); );
    // Init
    Vencode_32to5_for___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_32to5_for___024root*>(voidSelf);
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vencode_32to5_for___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vencode_32to5_for___024root__trace_chg_sub_0(Vencode_32to5_for___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->x),32);
    bufp->chgBit(oldp+1,(vlSelf->en));
    bufp->chgCData(oldp+2,(vlSelf->y),5);
    bufp->chgIData(oldp+3,(vlSelf->encode_32to5_for__DOT__i),32);
}

void Vencode_32to5_for___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_32to5_for___024root__trace_cleanup\n"); );
    // Init
    Vencode_32to5_for___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_32to5_for___024root*>(voidSelf);
    Vencode_32to5_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
