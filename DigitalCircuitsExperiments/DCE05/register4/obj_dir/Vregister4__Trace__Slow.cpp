// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister4__Syms.h"


void Vregister4___024root__traceInitSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister4___024root__traceInitTop(Vregister4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister4___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vregister4___024root__traceInitSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"load", false,-1);
        tracep->declBit(c+2,"clr", false,-1);
        tracep->declBit(c+3,"clk", false,-1);
        tracep->declBus(c+4,"inp", false,-1, 3,0);
        tracep->declBus(c+5,"q", false,-1, 3,0);
        tracep->declBit(c+1,"register4 load", false,-1);
        tracep->declBit(c+2,"register4 clr", false,-1);
        tracep->declBit(c+3,"register4 clk", false,-1);
        tracep->declBus(c+4,"register4 inp", false,-1, 3,0);
        tracep->declBus(c+5,"register4 q", false,-1, 3,0);
    }
}

void Vregister4___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vregister4___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vregister4___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vregister4___024root__traceRegister(Vregister4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vregister4___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vregister4___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vregister4___024root__traceCleanup, vlSelf);
    }
}

void Vregister4___024root__traceFullSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister4___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister4___024root* const __restrict vlSelf = static_cast<Vregister4___024root*>(voidSelf);
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister4___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister4___024root__traceFullSub0(Vregister4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->load));
        tracep->fullBit(oldp+2,(vlSelf->clr));
        tracep->fullBit(oldp+3,(vlSelf->clk));
        tracep->fullCData(oldp+4,(vlSelf->inp),4);
        tracep->fullCData(oldp+5,(vlSelf->q),4);
    }
}
