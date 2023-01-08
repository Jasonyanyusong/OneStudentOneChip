// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister16__Syms.h"


void Vregister16___024root__traceChgSub0(Vregister16___024root* vlSelf, VerilatedVcd* tracep);

void Vregister16___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister16___024root* const __restrict vlSelf = static_cast<Vregister16___024root*>(voidSelf);
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vregister16___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister16___024root__traceChgSub0(Vregister16___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->load));
        tracep->chgBit(oldp+1,(vlSelf->clr));
        tracep->chgBit(oldp+2,(vlSelf->clk));
        tracep->chgSData(oldp+3,(vlSelf->inp),16);
        tracep->chgSData(oldp+4,(vlSelf->q),16);
    }
}

void Vregister16___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vregister16___024root* const __restrict vlSelf = static_cast<Vregister16___024root*>(voidSelf);
    Vregister16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
