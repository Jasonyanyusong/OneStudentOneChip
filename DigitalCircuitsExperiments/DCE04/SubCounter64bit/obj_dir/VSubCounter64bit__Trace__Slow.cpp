// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSubCounter64bit__Syms.h"


void VSubCounter64bit___024root__traceInitSub0(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter64bit___024root__traceInitTop(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter64bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VSubCounter64bit___024root__traceInitSub0(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declQuad(c+3,"out_q", false,-1, 63,0);
        tracep->declBit(c+1,"SubCounter64bit clk", false,-1);
        tracep->declBit(c+2,"SubCounter64bit en", false,-1);
        tracep->declQuad(c+3,"SubCounter64bit out_q", false,-1, 63,0);
    }
}

void VSubCounter64bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VSubCounter64bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VSubCounter64bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VSubCounter64bit___024root__traceRegister(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VSubCounter64bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VSubCounter64bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VSubCounter64bit___024root__traceCleanup, vlSelf);
    }
}

void VSubCounter64bit___024root__traceFullSub0(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter64bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VSubCounter64bit___024root* const __restrict vlSelf = static_cast<VSubCounter64bit___024root*>(voidSelf);
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter64bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VSubCounter64bit___024root__traceFullSub0(VSubCounter64bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter64bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullQData(oldp+3,(vlSelf->out_q),64);
    }
}
