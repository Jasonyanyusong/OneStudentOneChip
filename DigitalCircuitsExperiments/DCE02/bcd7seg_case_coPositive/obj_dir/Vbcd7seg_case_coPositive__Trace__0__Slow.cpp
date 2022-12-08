// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbcd7seg_case_coPositive__Syms.h"


VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_init_sub__TOP__0(Vbcd7seg_case_coPositive___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"b", false,-1, 3,0);
    tracep->declBus(c+2,"h", false,-1, 6,0);
    tracep->pushNamePrefix("bcd7seg_case_coPositive ");
    tracep->declBus(c+1,"b", false,-1, 3,0);
    tracep->declBus(c+2,"h", false,-1, 6,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_init_top(Vbcd7seg_case_coPositive___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root__trace_init_top\n"); );
    // Body
    Vbcd7seg_case_coPositive___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbcd7seg_case_coPositive___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbcd7seg_case_coPositive___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_register(Vbcd7seg_case_coPositive___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vbcd7seg_case_coPositive___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vbcd7seg_case_coPositive___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vbcd7seg_case_coPositive___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_full_sub_0(Vbcd7seg_case_coPositive___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root__trace_full_top_0\n"); );
    // Init
    Vbcd7seg_case_coPositive___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcd7seg_case_coPositive___024root*>(voidSelf);
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbcd7seg_case_coPositive___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root__trace_full_sub_0(Vbcd7seg_case_coPositive___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->b),4);
    bufp->fullCData(oldp+2,(vlSelf->h),7);
}
