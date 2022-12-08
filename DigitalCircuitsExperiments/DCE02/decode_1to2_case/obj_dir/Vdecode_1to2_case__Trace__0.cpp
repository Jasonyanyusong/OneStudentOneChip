// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecode_1to2_case__Syms.h"


void Vdecode_1to2_case___024root__trace_chg_sub_0(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdecode_1to2_case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_chg_top_0\n"); );
    // Init
    Vdecode_1to2_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode_1to2_case___024root*>(voidSelf);
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdecode_1to2_case___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdecode_1to2_case___024root__trace_chg_sub_0(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->x));
    bufp->chgBit(oldp+1,(vlSelf->en));
    bufp->chgCData(oldp+2,(vlSelf->y),2);
}

void Vdecode_1to2_case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_cleanup\n"); );
    // Init
    Vdecode_1to2_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode_1to2_case___024root*>(voidSelf);
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
