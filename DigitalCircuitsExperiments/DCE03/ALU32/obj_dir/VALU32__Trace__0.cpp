// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU32__Syms.h"


void VALU32___024root__trace_chg_sub_0(VALU32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VALU32___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32___024root__trace_chg_top_0\n"); );
    // Init
    VALU32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32___024root*>(voidSelf);
    VALU32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VALU32___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VALU32___024root__trace_chg_sub_0(VALU32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->sub_add));
    bufp->chgIData(oldp+1,(vlSelf->a),32);
    bufp->chgIData(oldp+2,(vlSelf->b),32);
    bufp->chgBit(oldp+3,(vlSelf->carry));
    bufp->chgBit(oldp+4,(vlSelf->zero));
    bufp->chgBit(oldp+5,(vlSelf->overflow));
    bufp->chgIData(oldp+6,(vlSelf->result),32);
    bufp->chgIData(oldp+7,(vlSelf->ALU32__DOT__b_withCin),32);
}

void VALU32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32___024root__trace_cleanup\n"); );
    // Init
    VALU32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32___024root*>(voidSelf);
    VALU32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
