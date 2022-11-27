// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux_2to1_Structure__Syms.h"


void Vmux_2to1_Structure___024root__traceChgSub0(Vmux_2to1_Structure___024root* vlSelf, VerilatedVcd* tracep);

void Vmux_2to1_Structure___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vmux_2to1_Structure___024root* const __restrict vlSelf = static_cast<Vmux_2to1_Structure___024root*>(voidSelf);
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vmux_2to1_Structure___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vmux_2to1_Structure___024root__traceChgSub0(Vmux_2to1_Structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->a));
        tracep->chgBit(oldp+1,(vlSelf->b));
        tracep->chgBit(oldp+2,(vlSelf->s));
        tracep->chgBit(oldp+3,(vlSelf->y));
        tracep->chgBit(oldp+4,(((~ (IData)(vlSelf->s)) 
                                & (IData)(vlSelf->a))));
        tracep->chgBit(oldp+5,(((IData)(vlSelf->s) 
                                & (IData)(vlSelf->b))));
        tracep->chgBit(oldp+6,((1U & (~ (IData)(vlSelf->s)))));
    }
}

void Vmux_2to1_Structure___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vmux_2to1_Structure___024root* const __restrict vlSelf = static_cast<Vmux_2to1_Structure___024root*>(voidSelf);
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
