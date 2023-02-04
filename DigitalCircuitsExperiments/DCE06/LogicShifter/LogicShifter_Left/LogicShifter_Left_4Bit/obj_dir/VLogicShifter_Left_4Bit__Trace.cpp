// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLogicShifter_Left_4Bit__Syms.h"


void VLogicShifter_Left_4Bit___024root__traceChgSub0(VLogicShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep);

void VLogicShifter_Left_4Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VLogicShifter_Left_4Bit___024root* const __restrict vlSelf = static_cast<VLogicShifter_Left_4Bit___024root*>(voidSelf);
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VLogicShifter_Left_4Bit___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VLogicShifter_Left_4Bit___024root__traceChgSub0(VLogicShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clk));
        tracep->chgBit(oldp+1,(vlSelf->clr));
        tracep->chgBit(oldp+2,(vlSelf->load));
        tracep->chgCData(oldp+3,(vlSelf->inp),4);
        tracep->chgCData(oldp+4,(vlSelf->outp),4);
    }
}

void VLogicShifter_Left_4Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VLogicShifter_Left_4Bit___024root* const __restrict vlSelf = static_cast<VLogicShifter_Left_4Bit___024root*>(voidSelf);
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
