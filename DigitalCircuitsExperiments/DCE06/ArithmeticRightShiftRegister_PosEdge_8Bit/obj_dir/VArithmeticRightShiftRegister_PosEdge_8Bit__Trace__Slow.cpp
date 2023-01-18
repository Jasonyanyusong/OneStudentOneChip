// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VArithmeticRightShiftRegister_PosEdge_8Bit__Syms.h"


void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceInitSub0(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceInitTop(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceInitSub0(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"D", false,-1, 7,0);
        tracep->declBus(c+4,"Q", false,-1, 7,0);
        tracep->declBit(c+1,"ArithmeticRightShiftRegister_PosEdge_8Bit clock", false,-1);
        tracep->declBit(c+2,"ArithmeticRightShiftRegister_PosEdge_8Bit reset", false,-1);
        tracep->declBus(c+3,"ArithmeticRightShiftRegister_PosEdge_8Bit D", false,-1, 7,0);
        tracep->declBus(c+4,"ArithmeticRightShiftRegister_PosEdge_8Bit Q", false,-1, 7,0);
    }
}

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceRegister(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceCleanup, vlSelf);
    }
}

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullSub0(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VArithmeticRightShiftRegister_PosEdge_8Bit___024root* const __restrict vlSelf = static_cast<VArithmeticRightShiftRegister_PosEdge_8Bit___024root*>(voidSelf);
    VArithmeticRightShiftRegister_PosEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VArithmeticRightShiftRegister_PosEdge_8Bit___024root__traceFullSub0(VArithmeticRightShiftRegister_PosEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticRightShiftRegister_PosEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clock));
        tracep->fullBit(oldp+2,(vlSelf->reset));
        tracep->fullCData(oldp+3,(vlSelf->D),8);
        tracep->fullCData(oldp+4,(vlSelf->Q),8);
    }
}
