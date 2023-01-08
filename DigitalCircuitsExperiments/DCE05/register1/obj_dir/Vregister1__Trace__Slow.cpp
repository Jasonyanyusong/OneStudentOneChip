// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister1__Syms.h"


void Vregister1___024root__traceInitSub0(Vregister1___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister1___024root__traceInitTop(Vregister1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister1___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vregister1___024root__traceInitSub0(Vregister1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"load", false,-1);
        tracep->declBit(c+2,"clr", false,-1);
        tracep->declBit(c+3,"clk", false,-1);
        tracep->declBit(c+4,"inp", false,-1);
        tracep->declBit(c+5,"q", false,-1);
        tracep->declBit(c+1,"register1 load", false,-1);
        tracep->declBit(c+2,"register1 clr", false,-1);
        tracep->declBit(c+3,"register1 clk", false,-1);
        tracep->declBit(c+4,"register1 inp", false,-1);
        tracep->declBit(c+5,"register1 q", false,-1);
    }
}

void Vregister1___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vregister1___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vregister1___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vregister1___024root__traceRegister(Vregister1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vregister1___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vregister1___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vregister1___024root__traceCleanup, vlSelf);
    }
}

void Vregister1___024root__traceFullSub0(Vregister1___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister1___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister1___024root* const __restrict vlSelf = static_cast<Vregister1___024root*>(voidSelf);
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister1___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister1___024root__traceFullSub0(Vregister1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->load));
        tracep->fullBit(oldp+2,(vlSelf->clr));
        tracep->fullBit(oldp+3,(vlSelf->clk));
        tracep->fullBit(oldp+4,(vlSelf->inp));
        tracep->fullBit(oldp+5,(vlSelf->q));
    }
}
