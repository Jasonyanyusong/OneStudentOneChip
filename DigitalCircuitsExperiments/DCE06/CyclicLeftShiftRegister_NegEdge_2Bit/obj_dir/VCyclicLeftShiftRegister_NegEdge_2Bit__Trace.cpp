// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCyclicLeftShiftRegister_NegEdge_2Bit__Syms.h"


void VCyclicLeftShiftRegister_NegEdge_2Bit___024root__traceChgSub0(VCyclicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep);

void VCyclicLeftShiftRegister_NegEdge_2Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VCyclicLeftShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf = static_cast<VCyclicLeftShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VCyclicLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VCyclicLeftShiftRegister_NegEdge_2Bit___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VCyclicLeftShiftRegister_NegEdge_2Bit___024root__traceChgSub0(VCyclicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clock));
        tracep->chgBit(oldp+1,(vlSelf->reset));
        tracep->chgCData(oldp+2,(vlSelf->D),2);
        tracep->chgCData(oldp+3,(vlSelf->Q),2);
    }
}

void VCyclicLeftShiftRegister_NegEdge_2Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VCyclicLeftShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf = static_cast<VCyclicLeftShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VCyclicLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
