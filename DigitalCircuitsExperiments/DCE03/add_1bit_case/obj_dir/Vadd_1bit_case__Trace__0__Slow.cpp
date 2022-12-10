// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_1bit_case__Syms.h"


VL_ATTR_COLD void Vadd_1bit_case___024root__trace_init_sub__TOP__0(Vadd_1bit_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"c_i", false,-1);
    tracep->declBit(c+2,"a_i", false,-1);
    tracep->declBit(c+3,"b_i", false,-1);
    tracep->declBit(c+4,"s_i", false,-1);
    tracep->declBit(c+5,"c_iplus1", false,-1);
    tracep->pushNamePrefix("add_1bit_case ");
    tracep->declBit(c+1,"c_i", false,-1);
    tracep->declBit(c+2,"a_i", false,-1);
    tracep->declBit(c+3,"b_i", false,-1);
    tracep->declBit(c+4,"s_i", false,-1);
    tracep->declBit(c+5,"c_iplus1", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_init_top(Vadd_1bit_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_init_top\n"); );
    // Body
    Vadd_1bit_case___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_1bit_case___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_1bit_case___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_register(Vadd_1bit_case___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd_1bit_case___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd_1bit_case___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd_1bit_case___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_full_sub_0(Vadd_1bit_case___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_full_top_0\n"); );
    // Init
    Vadd_1bit_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_1bit_case___024root*>(voidSelf);
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_1bit_case___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_full_sub_0(Vadd_1bit_case___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_1bit_case___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->c_i));
    bufp->fullBit(oldp+2,(vlSelf->a_i));
    bufp->fullBit(oldp+3,(vlSelf->b_i));
    bufp->fullBit(oldp+4,(vlSelf->s_i));
    bufp->fullBit(oldp+5,(vlSelf->c_iplus1));
}
