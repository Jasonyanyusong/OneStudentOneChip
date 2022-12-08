// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode_2to1_case__Syms.h"


void Vencode_2to1_case___024root__trace_chg_sub_0(Vencode_2to1_case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vencode_2to1_case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_2to1_case___024root__trace_chg_top_0\n"); );
    // Init
    Vencode_2to1_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_2to1_case___024root*>(voidSelf);
    Vencode_2to1_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vencode_2to1_case___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vencode_2to1_case___024root__trace_chg_sub_0(Vencode_2to1_case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_2to1_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_2to1_case___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->x),2);
    bufp->chgBit(oldp+1,(vlSelf->en));
    bufp->chgBit(oldp+2,(vlSelf->y));
}

void Vencode_2to1_case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_2to1_case___024root__trace_cleanup\n"); );
    // Init
    Vencode_2to1_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_2to1_case___024root*>(voidSelf);
    Vencode_2to1_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
