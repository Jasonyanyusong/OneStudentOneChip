// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLogicRightShiftRegister_NegEdge_2Bit__Syms.h"


void VLogicRightShiftRegister_NegEdge_2Bit___024root__traceChgSub0(VLogicRightShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep);

void VLogicRightShiftRegister_NegEdge_2Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VLogicRightShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf = static_cast<VLogicRightShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VLogicRightShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VLogicRightShiftRegister_NegEdge_2Bit___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VLogicRightShiftRegister_NegEdge_2Bit___024root__traceChgSub0(VLogicRightShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

void VLogicRightShiftRegister_NegEdge_2Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VLogicRightShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf = static_cast<VLogicRightShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VLogicRightShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
