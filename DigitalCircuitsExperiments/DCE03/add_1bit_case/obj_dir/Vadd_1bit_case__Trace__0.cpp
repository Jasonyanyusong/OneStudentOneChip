// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_1bit_case__Syms.h"


void Vadd_1bit_case___024root__trace_chg_sub_0(Vadd_1bit_case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_1bit_case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_chg_top_0\n"); );
    // Init
    Vadd_1bit_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_1bit_case___024root*>(voidSelf);
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_1bit_case___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_1bit_case___024root__trace_chg_sub_0(Vadd_1bit_case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->c_i));
    bufp->chgBit(oldp+1,(vlSelf->a_i));
    bufp->chgBit(oldp+2,(vlSelf->b_i));
    bufp->chgBit(oldp+3,(vlSelf->s_i));
    bufp->chgBit(oldp+4,(vlSelf->c_iplus1));
}

void Vadd_1bit_case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_cleanup\n"); );
    // Init
    Vadd_1bit_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_1bit_case___024root*>(voidSelf);
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
