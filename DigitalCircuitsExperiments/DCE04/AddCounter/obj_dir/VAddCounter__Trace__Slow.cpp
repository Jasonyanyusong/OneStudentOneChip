// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAddCounter__Syms.h"


void VAddCounter___024root__traceInitSub0(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VAddCounter___024root__traceInitTop(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VAddCounter___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VAddCounter___024root__traceInitSub0(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"out_q", false,-1, 2,0);
        tracep->declBit(c+1,"AddCounter clk", false,-1);
        tracep->declBit(c+2,"AddCounter en", false,-1);
        tracep->declBus(c+3,"AddCounter out_q", false,-1, 2,0);
    }
}

void VAddCounter___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VAddCounter___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VAddCounter___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VAddCounter___024root__traceRegister(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VAddCounter___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VAddCounter___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VAddCounter___024root__traceCleanup, vlSelf);
    }
}

void VAddCounter___024root__traceFullSub0(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VAddCounter___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VAddCounter___024root* const __restrict vlSelf = static_cast<VAddCounter___024root*>(voidSelf);
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VAddCounter___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VAddCounter___024root__traceFullSub0(VAddCounter___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->out_q),3);
    }
}
