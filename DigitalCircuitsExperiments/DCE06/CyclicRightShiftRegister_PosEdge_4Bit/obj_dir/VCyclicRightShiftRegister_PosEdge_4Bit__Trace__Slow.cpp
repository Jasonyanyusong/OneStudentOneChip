// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCyclicRightShiftRegister_PosEdge_4Bit__Syms.h"


void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceInitSub0(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceInitTop(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceInitSub0(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"D", false,-1, 3,0);
        tracep->declBus(c+4,"Q", false,-1, 3,0);
        tracep->declBit(c+1,"CyclicRightShiftRegister_PosEdge_4Bit clock", false,-1);
        tracep->declBit(c+2,"CyclicRightShiftRegister_PosEdge_4Bit reset", false,-1);
        tracep->declBus(c+3,"CyclicRightShiftRegister_PosEdge_4Bit D", false,-1, 3,0);
        tracep->declBus(c+4,"CyclicRightShiftRegister_PosEdge_4Bit Q", false,-1, 3,0);
    }
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceRegister(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceCleanup, vlSelf);
    }
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullSub0(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VCyclicRightShiftRegister_PosEdge_4Bit___024root* const __restrict vlSelf = static_cast<VCyclicRightShiftRegister_PosEdge_4Bit___024root*>(voidSelf);
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VCyclicRightShiftRegister_PosEdge_4Bit___024root__traceFullSub0(VCyclicRightShiftRegister_PosEdge_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clock));
        tracep->fullBit(oldp+2,(vlSelf->reset));
        tracep->fullCData(oldp+3,(vlSelf->D),4);
        tracep->fullCData(oldp+4,(vlSelf->Q),4);
    }
}
