// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_datastream_16__Syms.h"


VL_ATTR_COLD void Vadd_datastream_16___024root__trace_init_sub__TOP__0(Vadd_datastream_16___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_16___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"in_x", false,-1, 15,0);
    tracep->declBus(c+2,"in_y", false,-1, 15,0);
    tracep->declBus(c+3,"out_s", false,-1, 15,0);
    tracep->pushNamePrefix("add_datastream_1 ");
    tracep->declBus(c+1,"in_x", false,-1, 15,0);
    tracep->declBus(c+2,"in_y", false,-1, 15,0);
    tracep->declBus(c+3,"out_s", false,-1, 15,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_init_top(Vadd_datastream_16___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_16___024root__trace_init_top\n"); );
    // Body
    Vadd_datastream_16___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_datastream_16___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_datastream_16___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_register(Vadd_datastream_16___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_16___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd_datastream_16___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd_datastream_16___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd_datastream_16___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_full_sub_0(Vadd_datastream_16___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_16___024root__trace_full_top_0\n"); );
    // Init
    Vadd_datastream_16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_datastream_16___024root*>(voidSelf);
    Vadd_datastream_16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_datastream_16___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_datastream_16___024root__trace_full_sub_0(Vadd_datastream_16___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_16___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->in_x),16);
    bufp->fullSData(oldp+2,(vlSelf->in_y),16);
    bufp->fullSData(oldp+3,(vlSelf->out_s),16);
}
