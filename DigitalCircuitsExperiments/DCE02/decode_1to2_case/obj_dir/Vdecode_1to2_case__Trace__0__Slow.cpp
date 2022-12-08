// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecode_1to2_case__Syms.h"


VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_init_sub__TOP__0(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"x", false,-1, 0,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"y", false,-1, 1,0);
    tracep->pushNamePrefix("decode_1to2_case ");
    tracep->declBus(c+1,"x", false,-1, 0,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"y", false,-1, 1,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_init_top(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_init_top\n"); );
    // Body
    Vdecode_1to2_case___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdecode_1to2_case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdecode_1to2_case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_register(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdecode_1to2_case___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdecode_1to2_case___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdecode_1to2_case___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_full_sub_0(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_full_top_0\n"); );
    // Init
    Vdecode_1to2_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode_1to2_case___024root*>(voidSelf);
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdecode_1to2_case___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdecode_1to2_case___024root__trace_full_sub_0(Vdecode_1to2_case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_1to2_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_1to2_case___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->x));
    bufp->fullBit(oldp+2,(vlSelf->en));
    bufp->fullCData(oldp+3,(vlSelf->y),2);
}
