// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMultiShifter_4Bit__Syms.h"


void VMultiShifter_4Bit___024root__traceInitSub0(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VMultiShifter_4Bit___024root__traceInitTop(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VMultiShifter_4Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VMultiShifter_4Bit___024root__traceInitSub0(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBus(c+2,"sel", false,-1, 2,0);
        tracep->declBus(c+3,"inp", false,-1, 3,0);
        tracep->declBus(c+4,"outp", false,-1, 3,0);
        tracep->declBit(c+1,"MultiShifter_4Bit clk", false,-1);
        tracep->declBus(c+2,"MultiShifter_4Bit sel", false,-1, 2,0);
        tracep->declBus(c+3,"MultiShifter_4Bit inp", false,-1, 3,0);
        tracep->declBus(c+4,"MultiShifter_4Bit outp", false,-1, 3,0);
    }
}

void VMultiShifter_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VMultiShifter_4Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VMultiShifter_4Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VMultiShifter_4Bit___024root__traceRegister(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VMultiShifter_4Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VMultiShifter_4Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VMultiShifter_4Bit___024root__traceCleanup, vlSelf);
    }
}

void VMultiShifter_4Bit___024root__traceFullSub0(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VMultiShifter_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VMultiShifter_4Bit___024root* const __restrict vlSelf = static_cast<VMultiShifter_4Bit___024root*>(voidSelf);
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VMultiShifter_4Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VMultiShifter_4Bit___024root__traceFullSub0(VMultiShifter_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiShifter_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullCData(oldp+2,(vlSelf->sel),3);
        tracep->fullCData(oldp+3,(vlSelf->inp),4);
        tracep->fullCData(oldp+4,(vlSelf->outp),4);
    }
}
