// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms.h"


void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceInitSub0(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceInitTop(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceInitSub0(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"D", false,-1, 1,0);
        tracep->declBus(c+4,"Q", false,-1, 1,0);
        tracep->declBit(c+1,"ArithmeticLeftShiftRegister_NegEdge_2Bit clock", false,-1);
        tracep->declBit(c+2,"ArithmeticLeftShiftRegister_NegEdge_2Bit reset", false,-1);
        tracep->declBus(c+3,"ArithmeticLeftShiftRegister_NegEdge_2Bit D", false,-1, 1,0);
        tracep->declBus(c+4,"ArithmeticLeftShiftRegister_NegEdge_2Bit Q", false,-1, 1,0);
    }
}

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceRegister(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceCleanup, vlSelf);
    }
}

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullSub0(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf = static_cast<VArithmeticLeftShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VArithmeticLeftShiftRegister_NegEdge_2Bit___024root__traceFullSub0(VArithmeticLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
