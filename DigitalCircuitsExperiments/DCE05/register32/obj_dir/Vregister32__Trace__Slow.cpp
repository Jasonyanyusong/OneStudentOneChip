// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister32__Syms.h"


void Vregister32___024root__traceInitSub0(Vregister32___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister32___024root__traceInitTop(Vregister32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister32___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vregister32___024root__traceInitSub0(Vregister32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"load", false,-1);
        tracep->declBit(c+2,"clr", false,-1);
        tracep->declBit(c+3,"clk", false,-1);
        tracep->declBus(c+4,"inp", false,-1, 31,0);
        tracep->declBus(c+5,"q", false,-1, 31,0);
        tracep->declBit(c+1,"register32 load", false,-1);
        tracep->declBit(c+2,"register32 clr", false,-1);
        tracep->declBit(c+3,"register32 clk", false,-1);
        tracep->declBus(c+4,"register32 inp", false,-1, 31,0);
        tracep->declBus(c+5,"register32 q", false,-1, 31,0);
    }
}

void Vregister32___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vregister32___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vregister32___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vregister32___024root__traceRegister(Vregister32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vregister32___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vregister32___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vregister32___024root__traceCleanup, vlSelf);
    }
}

void Vregister32___024root__traceFullSub0(Vregister32___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister32___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister32___024root* const __restrict vlSelf = static_cast<Vregister32___024root*>(voidSelf);
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister32___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister32___024root__traceFullSub0(Vregister32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->load));
        tracep->fullBit(oldp+2,(vlSelf->clr));
        tracep->fullBit(oldp+3,(vlSelf->clk));
        tracep->fullIData(oldp+4,(vlSelf->inp),32);
        tracep->fullIData(oldp+5,(vlSelf->q),32);
    }
}
