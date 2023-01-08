// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister4__Syms.h"


void Vregister4___024root__traceChgSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep);

void Vregister4___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister4___024root* const __restrict vlSelf = static_cast<Vregister4___024root*>(voidSelf);
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vregister4___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister4___024root__traceChgSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->load));
        tracep->chgBit(oldp+1,(vlSelf->clr));
        tracep->chgBit(oldp+2,(vlSelf->clk));
        tracep->chgCData(oldp+3,(vlSelf->inp),4);
        tracep->chgCData(oldp+4,(vlSelf->q),4);
    }
}

void Vregister4___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vregister4___024root* const __restrict vlSelf = static_cast<Vregister4___024root*>(voidSelf);
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
