// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMultiFunctionShiftRegister_NegEdge_8Bit__Syms.h"


void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceInitSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceInitTop(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceInitSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"inp", false,-1);
        tracep->declBus(c+3,"sel", false,-1, 2,0);
        tracep->declBus(c+4,"D", false,-1, 7,0);
        tracep->declBus(c+5,"Q", false,-1, 7,0);
        tracep->declBit(c+1,"MultiFunctionShiftRegister_NegEdge_8Bit clk", false,-1);
        tracep->declBit(c+2,"MultiFunctionShiftRegister_NegEdge_8Bit inp", false,-1);
        tracep->declBus(c+3,"MultiFunctionShiftRegister_NegEdge_8Bit sel", false,-1, 2,0);
        tracep->declBus(c+4,"MultiFunctionShiftRegister_NegEdge_8Bit D", false,-1, 7,0);
        tracep->declBus(c+5,"MultiFunctionShiftRegister_NegEdge_8Bit Q", false,-1, 7,0);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceRegister(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceCleanup, vlSelf);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VMultiFunctionShiftRegister_NegEdge_8Bit___024root* const __restrict vlSelf = static_cast<VMultiFunctionShiftRegister_NegEdge_8Bit___024root*>(voidSelf);
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VMultiFunctionShiftRegister_NegEdge_8Bit___024root__traceFullSub0(VMultiFunctionShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->inp));
        tracep->fullCData(oldp+3,(vlSelf->sel),3);
        tracep->fullCData(oldp+4,(vlSelf->D),8);
        tracep->fullCData(oldp+5,(vlSelf->Q),8);
    }
}
