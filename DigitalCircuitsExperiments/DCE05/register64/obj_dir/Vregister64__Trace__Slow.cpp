// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister64__Syms.h"


void Vregister64___024root__traceInitSub0(Vregister64___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister64___024root__traceInitTop(Vregister64___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister64___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vregister64___024root__traceInitSub0(Vregister64___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"load", false,-1);
        tracep->declBit(c+2,"clr", false,-1);
        tracep->declBit(c+3,"clk", false,-1);
        tracep->declQuad(c+4,"inp", false,-1, 63,0);
        tracep->declQuad(c+6,"q", false,-1, 63,0);
        tracep->declBit(c+1,"register64 load", false,-1);
        tracep->declBit(c+2,"register64 clr", false,-1);
        tracep->declBit(c+3,"register64 clk", false,-1);
        tracep->declQuad(c+4,"register64 inp", false,-1, 63,0);
        tracep->declQuad(c+6,"register64 q", false,-1, 63,0);
    }
}

void Vregister64___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vregister64___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vregister64___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vregister64___024root__traceRegister(Vregister64___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vregister64___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vregister64___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vregister64___024root__traceCleanup, vlSelf);
    }
}

void Vregister64___024root__traceFullSub0(Vregister64___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vregister64___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vregister64___024root* const __restrict vlSelf = static_cast<Vregister64___024root*>(voidSelf);
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vregister64___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vregister64___024root__traceFullSub0(Vregister64___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vregister64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->load));
        tracep->fullBit(oldp+2,(vlSelf->clr));
        tracep->fullBit(oldp+3,(vlSelf->clk));
        tracep->fullQData(oldp+4,(vlSelf->inp),64);
        tracep->fullQData(oldp+6,(vlSelf->q),64);
    }
}
