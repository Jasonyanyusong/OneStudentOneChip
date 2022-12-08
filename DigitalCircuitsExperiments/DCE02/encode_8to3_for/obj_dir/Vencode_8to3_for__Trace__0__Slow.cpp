// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode_8to3_for__Syms.h"


VL_ATTR_COLD void Vencode_8to3_for___024root__trace_init_sub__TOP__0(Vencode_8to3_for___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_8to3_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_8to3_for___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"x", false,-1, 7,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"y", false,-1, 2,0);
    tracep->pushNamePrefix("encode_8to3_for ");
    tracep->declBus(c+1,"x", false,-1, 7,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"y", false,-1, 2,0);
    tracep->declBus(c+4,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_init_top(Vencode_8to3_for___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_8to3_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_8to3_for___024root__trace_init_top\n"); );
    // Body
    Vencode_8to3_for___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vencode_8to3_for___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vencode_8to3_for___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_register(Vencode_8to3_for___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_8to3_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_8to3_for___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vencode_8to3_for___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vencode_8to3_for___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vencode_8to3_for___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_full_sub_0(Vencode_8to3_for___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_8to3_for___024root__trace_full_top_0\n"); );
    // Init
    Vencode_8to3_for___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_8to3_for___024root*>(voidSelf);
    Vencode_8to3_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vencode_8to3_for___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vencode_8to3_for___024root__trace_full_sub_0(Vencode_8to3_for___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_8to3_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_8to3_for___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->x),8);
    bufp->fullBit(oldp+2,(vlSelf->en));
    bufp->fullCData(oldp+3,(vlSelf->y),3);
    bufp->fullIData(oldp+4,(vlSelf->encode_8to3_for__DOT__i),32);
}
