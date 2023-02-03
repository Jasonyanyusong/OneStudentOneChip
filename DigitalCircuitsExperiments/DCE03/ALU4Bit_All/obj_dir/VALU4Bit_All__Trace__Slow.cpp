// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU4Bit_All__Syms.h"


void VALU4Bit_All___024root__traceInitSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4Bit_All___024root__traceInitTop(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4Bit_All___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VALU4Bit_All___024root__traceInitSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+5,"sel", false,-1, 2,0);
        tracep->declBus(c+6,"a", false,-1, 3,0);
        tracep->declBus(c+7,"b", false,-1, 3,0);
        tracep->declBus(c+8,"result", false,-1, 3,0);
        tracep->declBit(c+9,"overflow", false,-1);
        tracep->declBit(c+10,"carry", false,-1);
        tracep->declBit(c+11,"zero", false,-1);
        tracep->declBus(c+5,"ALU4Bit_All sel", false,-1, 2,0);
        tracep->declBus(c+6,"ALU4Bit_All a", false,-1, 3,0);
        tracep->declBus(c+7,"ALU4Bit_All b", false,-1, 3,0);
        tracep->declBus(c+8,"ALU4Bit_All result", false,-1, 3,0);
        tracep->declBit(c+9,"ALU4Bit_All overflow", false,-1);
        tracep->declBit(c+10,"ALU4Bit_All carry", false,-1);
        tracep->declBit(c+11,"ALU4Bit_All zero", false,-1);
        tracep->declBit(c+1,"ALU4Bit_All Cin", false,-1);
        tracep->declBus(c+2,"ALU4Bit_All t_no_Cin", false,-1, 3,0);
        tracep->declBus(c+3,"ALU4Bit_All carry_and_result", false,-1, 4,0);
        tracep->declBus(c+4,"ALU4Bit_All i", false,-1, 31,0);
    }
}

void VALU4Bit_All___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VALU4Bit_All___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VALU4Bit_All___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VALU4Bit_All___024root__traceRegister(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VALU4Bit_All___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VALU4Bit_All___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VALU4Bit_All___024root__traceCleanup, vlSelf);
    }
}

void VALU4Bit_All___024root__traceFullSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4Bit_All___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VALU4Bit_All___024root* const __restrict vlSelf = static_cast<VALU4Bit_All___024root*>(voidSelf);
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4Bit_All___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VALU4Bit_All___024root__traceFullSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->ALU4Bit_All__DOT__Cin));
        tracep->fullCData(oldp+2,(vlSelf->ALU4Bit_All__DOT__t_no_Cin),4);
        tracep->fullCData(oldp+3,(vlSelf->ALU4Bit_All__DOT__carry_and_result),5);
        tracep->fullIData(oldp+4,(vlSelf->ALU4Bit_All__DOT__i),32);
        tracep->fullCData(oldp+5,(vlSelf->sel),3);
        tracep->fullCData(oldp+6,(vlSelf->a),4);
        tracep->fullCData(oldp+7,(vlSelf->b),4);
        tracep->fullCData(oldp+8,(vlSelf->result),4);
        tracep->fullBit(oldp+9,(vlSelf->overflow));
        tracep->fullBit(oldp+10,(vlSelf->carry));
        tracep->fullBit(oldp+11,(vlSelf->zero));
    }
}
