// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSubCounter__Syms.h"


void VSubCounter___024root__traceInitSub0(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter___024root__traceInitTop(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VSubCounter___024root__traceInitSub0(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"out_q", false,-1, 2,0);
        tracep->declBit(c+1,"SubCounter clk", false,-1);
        tracep->declBit(c+2,"SubCounter en", false,-1);
        tracep->declBus(c+3,"SubCounter out_q", false,-1, 2,0);
    }
}

void VSubCounter___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VSubCounter___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VSubCounter___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VSubCounter___024root__traceRegister(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VSubCounter___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VSubCounter___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VSubCounter___024root__traceCleanup, vlSelf);
    }
}

void VSubCounter___024root__traceFullSub0(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VSubCounter___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VSubCounter___024root* const __restrict vlSelf = static_cast<VSubCounter___024root*>(voidSelf);
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VSubCounter___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VSubCounter___024root__traceFullSub0(VSubCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->out_q),3);
    }
}
