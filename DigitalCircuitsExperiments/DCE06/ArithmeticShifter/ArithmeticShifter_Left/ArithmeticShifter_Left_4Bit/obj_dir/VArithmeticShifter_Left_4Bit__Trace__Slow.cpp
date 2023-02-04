// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VArithmeticShifter_Left_4Bit__Syms.h"


void VArithmeticShifter_Left_4Bit___024root__traceInitSub0(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticShifter_Left_4Bit___024root__traceInitTop(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticShifter_Left_4Bit___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VArithmeticShifter_Left_4Bit___024root__traceInitSub0(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"clr", false,-1);
        tracep->declBit(c+3,"load", false,-1);
        tracep->declBus(c+4,"inp", false,-1, 3,0);
        tracep->declBus(c+5,"outp", false,-1, 3,0);
        tracep->declBit(c+1,"ArithmeticShifter_Left_4Bit clk", false,-1);
        tracep->declBit(c+2,"ArithmeticShifter_Left_4Bit clr", false,-1);
        tracep->declBit(c+3,"ArithmeticShifter_Left_4Bit load", false,-1);
        tracep->declBus(c+4,"ArithmeticShifter_Left_4Bit inp", false,-1, 3,0);
        tracep->declBus(c+5,"ArithmeticShifter_Left_4Bit outp", false,-1, 3,0);
    }
}

void VArithmeticShifter_Left_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VArithmeticShifter_Left_4Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VArithmeticShifter_Left_4Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VArithmeticShifter_Left_4Bit___024root__traceRegister(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VArithmeticShifter_Left_4Bit___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VArithmeticShifter_Left_4Bit___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VArithmeticShifter_Left_4Bit___024root__traceCleanup, vlSelf);
    }
}

void VArithmeticShifter_Left_4Bit___024root__traceFullSub0(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VArithmeticShifter_Left_4Bit___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VArithmeticShifter_Left_4Bit___024root* const __restrict vlSelf = static_cast<VArithmeticShifter_Left_4Bit___024root*>(voidSelf);
    VArithmeticShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VArithmeticShifter_Left_4Bit___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VArithmeticShifter_Left_4Bit___024root__traceFullSub0(VArithmeticShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VArithmeticShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk));
        tracep->fullBit(oldp+2,(vlSelf->clr));
        tracep->fullBit(oldp+3,(vlSelf->load));
        tracep->fullCData(oldp+4,(vlSelf->inp),4);
        tracep->fullCData(oldp+5,(vlSelf->outp),4);
    }
}
