// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbarrelshifter8__Syms.h"


void Vbarrelshifter8___024root__traceInitSub0(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vbarrelshifter8___024root__traceInitTop(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbarrelshifter8__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vbarrelshifter8___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vbarrelshifter8___024root__traceInitSub0(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbarrelshifter8__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+26,"din", false,-1, 7,0);
        tracep->declBus(c+27,"shamt", false,-1, 2,0);
        tracep->declBit(c+28,"lr", false,-1);
        tracep->declBit(c+29,"al", false,-1);
        tracep->declBus(c+30,"dout", false,-1, 7,0);
        tracep->declBus(c+26,"barrelshifter8 din", false,-1, 7,0);
        tracep->declBus(c+27,"barrelshifter8 shamt", false,-1, 2,0);
        tracep->declBit(c+28,"barrelshifter8 lr", false,-1);
        tracep->declBit(c+29,"barrelshifter8 al", false,-1);
        tracep->declBus(c+30,"barrelshifter8 dout", false,-1, 7,0);
        tracep->declBit(c+1,"barrelshifter8 mc_out", false,-1);
        tracep->declBit(c+2,"barrelshifter8 m7a_out", false,-1);
        tracep->declBit(c+3,"barrelshifter8 m6a_out", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m5a_out", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m4a_out", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m3a_out", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m2a_out", false,-1);
        tracep->declBit(c+8,"barrelshifter8 m1a_out", false,-1);
        tracep->declBit(c+9,"barrelshifter8 m0a_out", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m7b_out", false,-1);
        tracep->declBit(c+11,"barrelshifter8 m6b_out", false,-1);
        tracep->declBit(c+12,"barrelshifter8 m5b_out", false,-1);
        tracep->declBit(c+13,"barrelshifter8 m4b_out", false,-1);
        tracep->declBit(c+14,"barrelshifter8 m3b_out", false,-1);
        tracep->declBit(c+15,"barrelshifter8 m2b_out", false,-1);
        tracep->declBit(c+16,"barrelshifter8 m1b_out", false,-1);
        tracep->declBit(c+17,"barrelshifter8 m0b_out", false,-1);
        tracep->declBit(c+42,"barrelshifter8 mc datain0", false,-1);
        tracep->declBit(c+31,"barrelshifter8 mc datain1", false,-1);
        tracep->declBit(c+29,"barrelshifter8 mc sel", false,-1);
        tracep->declBit(c+1,"barrelshifter8 mc dataout", false,-1);
        tracep->declBit(c+31,"barrelshifter8 m7a datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m7a datain1", false,-1);
        tracep->declBit(c+31,"barrelshifter8 m7a datain2", false,-1);
        tracep->declBit(c+32,"barrelshifter8 m7a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m7a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m7a sel1", false,-1);
        tracep->declBit(c+2,"barrelshifter8 m7a dataout", false,-1);
        tracep->declBit(c+32,"barrelshifter8 m6a datain0", false,-1);
        tracep->declBit(c+31,"barrelshifter8 m6a datain1", false,-1);
        tracep->declBit(c+32,"barrelshifter8 m6a datain2", false,-1);
        tracep->declBit(c+34,"barrelshifter8 m6a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m6a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m6a sel1", false,-1);
        tracep->declBit(c+3,"barrelshifter8 m6a dataout", false,-1);
        tracep->declBit(c+34,"barrelshifter8 m5a datain0", false,-1);
        tracep->declBit(c+32,"barrelshifter8 m5a datain1", false,-1);
        tracep->declBit(c+34,"barrelshifter8 m5a datain2", false,-1);
        tracep->declBit(c+35,"barrelshifter8 m5a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m5a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m5a sel1", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m5a dataout", false,-1);
        tracep->declBit(c+35,"barrelshifter8 m4a datain0", false,-1);
        tracep->declBit(c+34,"barrelshifter8 m4a datain1", false,-1);
        tracep->declBit(c+35,"barrelshifter8 m4a datain2", false,-1);
        tracep->declBit(c+36,"barrelshifter8 m4a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m4a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m4a sel1", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m4a dataout", false,-1);
        tracep->declBit(c+36,"barrelshifter8 m3a datain0", false,-1);
        tracep->declBit(c+35,"barrelshifter8 m3a datain1", false,-1);
        tracep->declBit(c+36,"barrelshifter8 m3a datain2", false,-1);
        tracep->declBit(c+37,"barrelshifter8 m3a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m3a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m3a sel1", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m3a dataout", false,-1);
        tracep->declBit(c+37,"barrelshifter8 m2a datain0", false,-1);
        tracep->declBit(c+36,"barrelshifter8 m2a datain1", false,-1);
        tracep->declBit(c+37,"barrelshifter8 m2a datain2", false,-1);
        tracep->declBit(c+38,"barrelshifter8 m2a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m2a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m2a sel1", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m2a dataout", false,-1);
        tracep->declBit(c+38,"barrelshifter8 m1a datain0", false,-1);
        tracep->declBit(c+37,"barrelshifter8 m1a datain1", false,-1);
        tracep->declBit(c+38,"barrelshifter8 m1a datain2", false,-1);
        tracep->declBit(c+39,"barrelshifter8 m1a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m1a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m1a sel1", false,-1);
        tracep->declBit(c+8,"barrelshifter8 m1a dataout", false,-1);
        tracep->declBit(c+39,"barrelshifter8 m0a datain0", false,-1);
        tracep->declBit(c+38,"barrelshifter8 m0a datain1", false,-1);
        tracep->declBit(c+39,"barrelshifter8 m0a datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m0a datain3", false,-1);
        tracep->declBit(c+33,"barrelshifter8 m0a sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m0a sel1", false,-1);
        tracep->declBit(c+9,"barrelshifter8 m0a dataout", false,-1);
        tracep->declBit(c+2,"barrelshifter8 m7b datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m7b datain1", false,-1);
        tracep->declBit(c+2,"barrelshifter8 m7b datain2", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m7b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m7b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m7b sel1", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m7b dataout", false,-1);
        tracep->declBit(c+3,"barrelshifter8 m6b datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m6b datain1", false,-1);
        tracep->declBit(c+3,"barrelshifter8 m6b datain2", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m6b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m6b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m6b sel1", false,-1);
        tracep->declBit(c+11,"barrelshifter8 m6b dataout", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m5b datain0", false,-1);
        tracep->declBit(c+2,"barrelshifter8 m5b datain1", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m5b datain2", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m5b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m5b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m5b sel1", false,-1);
        tracep->declBit(c+12,"barrelshifter8 m5b dataout", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m4b datain0", false,-1);
        tracep->declBit(c+3,"barrelshifter8 m4b datain1", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m4b datain2", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m4b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m4b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m4b sel1", false,-1);
        tracep->declBit(c+13,"barrelshifter8 m4b dataout", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m3b datain0", false,-1);
        tracep->declBit(c+4,"barrelshifter8 m3b datain1", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m3b datain2", false,-1);
        tracep->declBit(c+8,"barrelshifter8 m3b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m3b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m3b sel1", false,-1);
        tracep->declBit(c+14,"barrelshifter8 m3b dataout", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m2b datain0", false,-1);
        tracep->declBit(c+5,"barrelshifter8 m2b datain1", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m2b datain2", false,-1);
        tracep->declBit(c+9,"barrelshifter8 m2b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m2b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m2b sel1", false,-1);
        tracep->declBit(c+15,"barrelshifter8 m2b dataout", false,-1);
        tracep->declBit(c+8,"barrelshifter8 m1b datain0", false,-1);
        tracep->declBit(c+6,"barrelshifter8 m1b datain1", false,-1);
        tracep->declBit(c+8,"barrelshifter8 m1b datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m1b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m1b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m1b sel1", false,-1);
        tracep->declBit(c+16,"barrelshifter8 m1b dataout", false,-1);
        tracep->declBit(c+9,"barrelshifter8 m0b datain0", false,-1);
        tracep->declBit(c+7,"barrelshifter8 m0b datain1", false,-1);
        tracep->declBit(c+9,"barrelshifter8 m0b datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m0b datain3", false,-1);
        tracep->declBit(c+40,"barrelshifter8 m0b sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m0b sel1", false,-1);
        tracep->declBit(c+17,"barrelshifter8 m0b dataout", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m7c datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m7c datain1", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m7c datain2", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m7c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m7c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m7c sel1", false,-1);
        tracep->declBit(c+18,"barrelshifter8 m7c dataout", false,-1);
        tracep->declBit(c+11,"barrelshifter8 m6c datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m6c datain1", false,-1);
        tracep->declBit(c+11,"barrelshifter8 m6c datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m6c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m6c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m6c sel1", false,-1);
        tracep->declBit(c+19,"barrelshifter8 m6c dataout", false,-1);
        tracep->declBit(c+12,"barrelshifter8 m5c datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m5c datain1", false,-1);
        tracep->declBit(c+12,"barrelshifter8 m5c datain2", false,-1);
        tracep->declBit(c+16,"barrelshifter8 m5c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m5c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m5c sel1", false,-1);
        tracep->declBit(c+20,"barrelshifter8 m5c dataout", false,-1);
        tracep->declBit(c+13,"barrelshifter8 m4c datain0", false,-1);
        tracep->declBit(c+1,"barrelshifter8 m4c datain1", false,-1);
        tracep->declBit(c+13,"barrelshifter8 m4c datain2", false,-1);
        tracep->declBit(c+17,"barrelshifter8 m4c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m4c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m4c sel1", false,-1);
        tracep->declBit(c+21,"barrelshifter8 m4c dataout", false,-1);
        tracep->declBit(c+14,"barrelshifter8 m3c datain0", false,-1);
        tracep->declBit(c+10,"barrelshifter8 m3c datain1", false,-1);
        tracep->declBit(c+14,"barrelshifter8 m3c datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m3c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m3c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m3c sel1", false,-1);
        tracep->declBit(c+22,"barrelshifter8 m3c dataout", false,-1);
        tracep->declBit(c+15,"barrelshifter8 m2c datain0", false,-1);
        tracep->declBit(c+11,"barrelshifter8 m2c datain1", false,-1);
        tracep->declBit(c+15,"barrelshifter8 m2c datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m2c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m2c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m2c sel1", false,-1);
        tracep->declBit(c+23,"barrelshifter8 m2c dataout", false,-1);
        tracep->declBit(c+16,"barrelshifter8 m1c datain0", false,-1);
        tracep->declBit(c+12,"barrelshifter8 m1c datain1", false,-1);
        tracep->declBit(c+16,"barrelshifter8 m1c datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m1c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m1c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m1c sel1", false,-1);
        tracep->declBit(c+24,"barrelshifter8 m1c dataout", false,-1);
        tracep->declBit(c+17,"barrelshifter8 m0c datain0", false,-1);
        tracep->declBit(c+13,"barrelshifter8 m0c datain1", false,-1);
        tracep->declBit(c+17,"barrelshifter8 m0c datain2", false,-1);
        tracep->declBit(c+42,"barrelshifter8 m0c datain3", false,-1);
        tracep->declBit(c+41,"barrelshifter8 m0c sel0", false,-1);
        tracep->declBit(c+28,"barrelshifter8 m0c sel1", false,-1);
        tracep->declBit(c+25,"barrelshifter8 m0c dataout", false,-1);
    }
}

void Vbarrelshifter8___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vbarrelshifter8___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vbarrelshifter8___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vbarrelshifter8___024root__traceRegister(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbarrelshifter8__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vbarrelshifter8___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vbarrelshifter8___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vbarrelshifter8___024root__traceCleanup, vlSelf);
    }
}

void Vbarrelshifter8___024root__traceFullSub0(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vbarrelshifter8___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vbarrelshifter8___024root* const __restrict vlSelf = static_cast<Vbarrelshifter8___024root*>(voidSelf);
    Vbarrelshifter8__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vbarrelshifter8___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vbarrelshifter8___024root__traceFullSub0(Vbarrelshifter8___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbarrelshifter8__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->barrelshifter8__DOT__mc_out));
        tracep->fullBit(oldp+2,(vlSelf->barrelshifter8__DOT__m7a_out));
        tracep->fullBit(oldp+3,(vlSelf->barrelshifter8__DOT__m6a_out));
        tracep->fullBit(oldp+4,(vlSelf->barrelshifter8__DOT__m5a_out));
        tracep->fullBit(oldp+5,(vlSelf->barrelshifter8__DOT__m4a_out));
        tracep->fullBit(oldp+6,(vlSelf->barrelshifter8__DOT__m3a_out));
        tracep->fullBit(oldp+7,(vlSelf->barrelshifter8__DOT__m2a_out));
        tracep->fullBit(oldp+8,(vlSelf->barrelshifter8__DOT__m1a_out));
        tracep->fullBit(oldp+9,(vlSelf->barrelshifter8__DOT__m0a_out));
        tracep->fullBit(oldp+10,(vlSelf->barrelshifter8__DOT__m7b_out));
        tracep->fullBit(oldp+11,(vlSelf->barrelshifter8__DOT__m6b_out));
        tracep->fullBit(oldp+12,(vlSelf->barrelshifter8__DOT__m5b_out));
        tracep->fullBit(oldp+13,(vlSelf->barrelshifter8__DOT__m4b_out));
        tracep->fullBit(oldp+14,(vlSelf->barrelshifter8__DOT__m3b_out));
        tracep->fullBit(oldp+15,(vlSelf->barrelshifter8__DOT__m2b_out));
        tracep->fullBit(oldp+16,(vlSelf->barrelshifter8__DOT__m1b_out));
        tracep->fullBit(oldp+17,(vlSelf->barrelshifter8__DOT__m0b_out));
        tracep->fullBit(oldp+18,(vlSelf->barrelshifter8__DOT____Vcellout__m7c__dataout));
        tracep->fullBit(oldp+19,(vlSelf->barrelshifter8__DOT____Vcellout__m6c__dataout));
        tracep->fullBit(oldp+20,(vlSelf->barrelshifter8__DOT____Vcellout__m5c__dataout));
        tracep->fullBit(oldp+21,(vlSelf->barrelshifter8__DOT____Vcellout__m4c__dataout));
        tracep->fullBit(oldp+22,(vlSelf->barrelshifter8__DOT____Vcellout__m3c__dataout));
        tracep->fullBit(oldp+23,(vlSelf->barrelshifter8__DOT____Vcellout__m2c__dataout));
        tracep->fullBit(oldp+24,(vlSelf->barrelshifter8__DOT____Vcellout__m1c__dataout));
        tracep->fullBit(oldp+25,(vlSelf->barrelshifter8__DOT____Vcellout__m0c__dataout));
        tracep->fullCData(oldp+26,(vlSelf->din),8);
        tracep->fullCData(oldp+27,(vlSelf->shamt),3);
        tracep->fullBit(oldp+28,(vlSelf->lr));
        tracep->fullBit(oldp+29,(vlSelf->al));
        tracep->fullCData(oldp+30,(vlSelf->dout),8);
        tracep->fullBit(oldp+31,((1U & ((IData)(vlSelf->din) 
                                        >> 7U))));
        tracep->fullBit(oldp+32,((1U & ((IData)(vlSelf->din) 
                                        >> 6U))));
        tracep->fullBit(oldp+33,((1U & (IData)(vlSelf->shamt))));
        tracep->fullBit(oldp+34,((1U & ((IData)(vlSelf->din) 
                                        >> 5U))));
        tracep->fullBit(oldp+35,((1U & ((IData)(vlSelf->din) 
                                        >> 4U))));
        tracep->fullBit(oldp+36,((1U & ((IData)(vlSelf->din) 
                                        >> 3U))));
        tracep->fullBit(oldp+37,((1U & ((IData)(vlSelf->din) 
                                        >> 2U))));
        tracep->fullBit(oldp+38,((1U & ((IData)(vlSelf->din) 
                                        >> 1U))));
        tracep->fullBit(oldp+39,((1U & (IData)(vlSelf->din))));
        tracep->fullBit(oldp+40,((1U & ((IData)(vlSelf->shamt) 
                                        >> 1U))));
        tracep->fullBit(oldp+41,((1U & ((IData)(vlSelf->shamt) 
                                        >> 2U))));
        tracep->fullBit(oldp+42,(0U));
    }
}
