// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSubCounter1bit__Syms.h"


void VSubCounter1bit___024root__traceInitSub0(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter1bit___024root__traceInitTop(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter1bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VSubCounter1bit___024root__traceInitSub0(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"out_q", false,-1, 0,0);
        tracep->declBit(c+1,"SubCounter1bit clk", false,-1);
        tracep->declBit(c+2,"SubCounter1bit en", false,-1);
        tracep->declBus(c+3,"SubCounter1bit out_q", false,-1, 0,0);
    }
}

void VSubCounter1bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VSubCounter1bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VSubCounter1bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VSubCounter1bit___024root__traceRegister(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VSubCounter1bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VSubCounter1bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VSubCounter1bit___024root__traceCleanup, vlSelf);
    }
}

void VSubCounter1bit___024root__traceFullSub0(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter1bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VSubCounter1bit___024root* const __restrict vlSelf = static_cast<VSubCounter1bit___024root*>(voidSelf);
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter1bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VSubCounter1bit___024root__traceFullSub0(VSubCounter1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullBit(oldp+3,(vlSelf->out_q));
    }
}
