// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMultiFunctionShiftRegister_NegEdge_8Bit__Syms.h"


void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep);

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VMultiFunctionShiftRegister_NegEdge_8Bit___024root* const __restrict vlSelf = static_cast<VMultiFunctionShiftRegister_NegEdge_8Bit___024root*>(voidSelf);
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clk));
        tracep->chgBit(oldp+1,(vlSelf->inp));
        tracep->chgCData(oldp+2,(vlSelf->sel),3);
        tracep->chgCData(oldp+3,(vlSelf->D),8);
        tracep->chgCData(oldp+4,(vlSelf->Q),8);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VMultiFunctionShiftRegister_NegEdge_8Bit___024root* const __restrict vlSelf = static_cast<VMultiFunctionShiftRegister_NegEdge_8Bit___024root*>(voidSelf);
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
