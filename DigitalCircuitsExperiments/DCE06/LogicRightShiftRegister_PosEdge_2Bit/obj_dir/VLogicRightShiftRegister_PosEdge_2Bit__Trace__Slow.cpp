// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLogicRightShiftRegister_PosEdge_2Bit__Syms.h"


void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceInitSub0(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceInitTop(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VLogicRightShiftRegister_PosEdge_2Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceInitSub0(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"D", false,-1, 1,0);
        tracep->declBus(c+4,"Q", false,-1, 1,0);
        tracep->declBit(c+1,"LogicRightShiftRegister_PosEdge_2Bit clock", false,-1);
        tracep->declBit(c+2,"LogicRightShiftRegister_PosEdge_2Bit reset", false,-1);
        tracep->declBus(c+3,"LogicRightShiftRegister_PosEdge_2Bit D", false,-1, 1,0);
        tracep->declBus(c+4,"LogicRightShiftRegister_PosEdge_2Bit Q", false,-1, 1,0);
    }
}

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceRegister(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VLogicRightShiftRegister_PosEdge_2Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VLogicRightShiftRegister_PosEdge_2Bit___024root__traceCleanup, vlSelf);
    }
}

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullSub0(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VLogicRightShiftRegister_PosEdge_2Bit___024root* const __restrict vlSelf = static_cast<VLogicRightShiftRegister_PosEdge_2Bit___024root*>(voidSelf);
    VLogicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VLogicRightShiftRegister_PosEdge_2Bit___024root__traceFullSub0(VLogicRightShiftRegister_PosEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VLogicRightShiftRegister_PosEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clock));
        tracep->fullBit(oldp+2,(vlSelf->reset));
        tracep->fullCData(oldp+3,(vlSelf->D),2);
        tracep->fullCData(oldp+4,(vlSelf->Q),2);
    }
}
