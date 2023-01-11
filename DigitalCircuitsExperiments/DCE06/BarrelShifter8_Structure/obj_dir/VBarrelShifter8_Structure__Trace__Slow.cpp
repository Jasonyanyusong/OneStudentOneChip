// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VBarrelShifter8_Structure__Syms.h"


void VBarrelShifter8_Structure___024root__traceInitSub0(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VBarrelShifter8_Structure___024root__traceInitTop(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VBarrelShifter8_Structure___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VBarrelShifter8_Structure___024root__traceInitSub0(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+26,"din", false,-1, 7,0);
        tracep->declBus(c+27,"shamt", false,-1, 2,0);
        tracep->declBit(c+28,"lr", false,-1);
        tracep->declBit(c+29,"al", false,-1);
        tracep->declBus(c+30,"dout", false,-1, 7,0);
        tracep->declBus(c+26,"BarrelShifter8_Structure din", false,-1, 7,0);
        tracep->declBus(c+27,"BarrelShifter8_Structure shamt", false,-1, 2,0);
        tracep->declBit(c+28,"BarrelShifter8_Structure lr", false,-1);
        tracep->declBit(c+29,"BarrelShifter8_Structure al", false,-1);
        tracep->declBus(c+30,"BarrelShifter8_Structure dout", false,-1, 7,0);
        tracep->declBit(c+1,"BarrelShifter8_Structure mc_out", false,-1);
        tracep->declBit(c+2,"BarrelShifter8_Structure m7a_out", false,-1);
        tracep->declBit(c+3,"BarrelShifter8_Structure m6a_out", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m5a_out", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m4a_out", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m3a_out", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m2a_out", false,-1);
        tracep->declBit(c+8,"BarrelShifter8_Structure m1a_out", false,-1);
        tracep->declBit(c+9,"BarrelShifter8_Structure m0a_out", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m7b_out", false,-1);
        tracep->declBit(c+11,"BarrelShifter8_Structure m6b_out", false,-1);
        tracep->declBit(c+12,"BarrelShifter8_Structure m5b_out", false,-1);
        tracep->declBit(c+13,"BarrelShifter8_Structure m4b_out", false,-1);
        tracep->declBit(c+14,"BarrelShifter8_Structure m3b_out", false,-1);
        tracep->declBit(c+15,"BarrelShifter8_Structure m2b_out", false,-1);
        tracep->declBit(c+16,"BarrelShifter8_Structure m1b_out", false,-1);
        tracep->declBit(c+17,"BarrelShifter8_Structure m0b_out", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure mc datain0", false,-1);
        tracep->declBit(c+31,"BarrelShifter8_Structure mc datain1", false,-1);
        tracep->declBit(c+29,"BarrelShifter8_Structure mc sel", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure mc dataout", false,-1);
        tracep->declBit(c+31,"BarrelShifter8_Structure m7a datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m7a datain1", false,-1);
        tracep->declBit(c+31,"BarrelShifter8_Structure m7a datain2", false,-1);
        tracep->declBit(c+32,"BarrelShifter8_Structure m7a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m7a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m7a sel1", false,-1);
        tracep->declBit(c+2,"BarrelShifter8_Structure m7a dataout", false,-1);
        tracep->declBit(c+32,"BarrelShifter8_Structure m6a datain0", false,-1);
        tracep->declBit(c+31,"BarrelShifter8_Structure m6a datain1", false,-1);
        tracep->declBit(c+32,"BarrelShifter8_Structure m6a datain2", false,-1);
        tracep->declBit(c+34,"BarrelShifter8_Structure m6a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m6a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m6a sel1", false,-1);
        tracep->declBit(c+3,"BarrelShifter8_Structure m6a dataout", false,-1);
        tracep->declBit(c+34,"BarrelShifter8_Structure m5a datain0", false,-1);
        tracep->declBit(c+32,"BarrelShifter8_Structure m5a datain1", false,-1);
        tracep->declBit(c+34,"BarrelShifter8_Structure m5a datain2", false,-1);
        tracep->declBit(c+35,"BarrelShifter8_Structure m5a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m5a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m5a sel1", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m5a dataout", false,-1);
        tracep->declBit(c+35,"BarrelShifter8_Structure m4a datain0", false,-1);
        tracep->declBit(c+34,"BarrelShifter8_Structure m4a datain1", false,-1);
        tracep->declBit(c+35,"BarrelShifter8_Structure m4a datain2", false,-1);
        tracep->declBit(c+36,"BarrelShifter8_Structure m4a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m4a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m4a sel1", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m4a dataout", false,-1);
        tracep->declBit(c+36,"BarrelShifter8_Structure m3a datain0", false,-1);
        tracep->declBit(c+35,"BarrelShifter8_Structure m3a datain1", false,-1);
        tracep->declBit(c+36,"BarrelShifter8_Structure m3a datain2", false,-1);
        tracep->declBit(c+37,"BarrelShifter8_Structure m3a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m3a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m3a sel1", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m3a dataout", false,-1);
        tracep->declBit(c+37,"BarrelShifter8_Structure m2a datain0", false,-1);
        tracep->declBit(c+36,"BarrelShifter8_Structure m2a datain1", false,-1);
        tracep->declBit(c+37,"BarrelShifter8_Structure m2a datain2", false,-1);
        tracep->declBit(c+38,"BarrelShifter8_Structure m2a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m2a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m2a sel1", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m2a dataout", false,-1);
        tracep->declBit(c+38,"BarrelShifter8_Structure m1a datain0", false,-1);
        tracep->declBit(c+37,"BarrelShifter8_Structure m1a datain1", false,-1);
        tracep->declBit(c+38,"BarrelShifter8_Structure m1a datain2", false,-1);
        tracep->declBit(c+39,"BarrelShifter8_Structure m1a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m1a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m1a sel1", false,-1);
        tracep->declBit(c+8,"BarrelShifter8_Structure m1a dataout", false,-1);
        tracep->declBit(c+39,"BarrelShifter8_Structure m0a datain0", false,-1);
        tracep->declBit(c+38,"BarrelShifter8_Structure m0a datain1", false,-1);
        tracep->declBit(c+39,"BarrelShifter8_Structure m0a datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m0a datain3", false,-1);
        tracep->declBit(c+33,"BarrelShifter8_Structure m0a sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m0a sel1", false,-1);
        tracep->declBit(c+9,"BarrelShifter8_Structure m0a dataout", false,-1);
        tracep->declBit(c+2,"BarrelShifter8_Structure m7b datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m7b datain1", false,-1);
        tracep->declBit(c+2,"BarrelShifter8_Structure m7b datain2", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m7b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m7b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m7b sel1", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m7b dataout", false,-1);
        tracep->declBit(c+3,"BarrelShifter8_Structure m6b datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m6b datain1", false,-1);
        tracep->declBit(c+3,"BarrelShifter8_Structure m6b datain2", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m6b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m6b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m6b sel1", false,-1);
        tracep->declBit(c+11,"BarrelShifter8_Structure m6b dataout", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m5b datain0", false,-1);
        tracep->declBit(c+2,"BarrelShifter8_Structure m5b datain1", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m5b datain2", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m5b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m5b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m5b sel1", false,-1);
        tracep->declBit(c+12,"BarrelShifter8_Structure m5b dataout", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m4b datain0", false,-1);
        tracep->declBit(c+3,"BarrelShifter8_Structure m4b datain1", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m4b datain2", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m4b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m4b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m4b sel1", false,-1);
        tracep->declBit(c+13,"BarrelShifter8_Structure m4b dataout", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m3b datain0", false,-1);
        tracep->declBit(c+4,"BarrelShifter8_Structure m3b datain1", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m3b datain2", false,-1);
        tracep->declBit(c+8,"BarrelShifter8_Structure m3b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m3b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m3b sel1", false,-1);
        tracep->declBit(c+14,"BarrelShifter8_Structure m3b dataout", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m2b datain0", false,-1);
        tracep->declBit(c+5,"BarrelShifter8_Structure m2b datain1", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m2b datain2", false,-1);
        tracep->declBit(c+9,"BarrelShifter8_Structure m2b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m2b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m2b sel1", false,-1);
        tracep->declBit(c+15,"BarrelShifter8_Structure m2b dataout", false,-1);
        tracep->declBit(c+8,"BarrelShifter8_Structure m1b datain0", false,-1);
        tracep->declBit(c+6,"BarrelShifter8_Structure m1b datain1", false,-1);
        tracep->declBit(c+8,"BarrelShifter8_Structure m1b datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m1b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m1b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m1b sel1", false,-1);
        tracep->declBit(c+16,"BarrelShifter8_Structure m1b dataout", false,-1);
        tracep->declBit(c+9,"BarrelShifter8_Structure m0b datain0", false,-1);
        tracep->declBit(c+7,"BarrelShifter8_Structure m0b datain1", false,-1);
        tracep->declBit(c+9,"BarrelShifter8_Structure m0b datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m0b datain3", false,-1);
        tracep->declBit(c+40,"BarrelShifter8_Structure m0b sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m0b sel1", false,-1);
        tracep->declBit(c+17,"BarrelShifter8_Structure m0b dataout", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m7c datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m7c datain1", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m7c datain2", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m7c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m7c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m7c sel1", false,-1);
        tracep->declBit(c+18,"BarrelShifter8_Structure m7c dataout", false,-1);
        tracep->declBit(c+11,"BarrelShifter8_Structure m6c datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m6c datain1", false,-1);
        tracep->declBit(c+11,"BarrelShifter8_Structure m6c datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m6c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m6c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m6c sel1", false,-1);
        tracep->declBit(c+19,"BarrelShifter8_Structure m6c dataout", false,-1);
        tracep->declBit(c+12,"BarrelShifter8_Structure m5c datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m5c datain1", false,-1);
        tracep->declBit(c+12,"BarrelShifter8_Structure m5c datain2", false,-1);
        tracep->declBit(c+16,"BarrelShifter8_Structure m5c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m5c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m5c sel1", false,-1);
        tracep->declBit(c+20,"BarrelShifter8_Structure m5c dataout", false,-1);
        tracep->declBit(c+13,"BarrelShifter8_Structure m4c datain0", false,-1);
        tracep->declBit(c+1,"BarrelShifter8_Structure m4c datain1", false,-1);
        tracep->declBit(c+13,"BarrelShifter8_Structure m4c datain2", false,-1);
        tracep->declBit(c+17,"BarrelShifter8_Structure m4c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m4c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m4c sel1", false,-1);
        tracep->declBit(c+21,"BarrelShifter8_Structure m4c dataout", false,-1);
        tracep->declBit(c+14,"BarrelShifter8_Structure m3c datain0", false,-1);
        tracep->declBit(c+10,"BarrelShifter8_Structure m3c datain1", false,-1);
        tracep->declBit(c+14,"BarrelShifter8_Structure m3c datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m3c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m3c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m3c sel1", false,-1);
        tracep->declBit(c+22,"BarrelShifter8_Structure m3c dataout", false,-1);
        tracep->declBit(c+15,"BarrelShifter8_Structure m2c datain0", false,-1);
        tracep->declBit(c+11,"BarrelShifter8_Structure m2c datain1", false,-1);
        tracep->declBit(c+15,"BarrelShifter8_Structure m2c datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m2c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m2c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m2c sel1", false,-1);
        tracep->declBit(c+23,"BarrelShifter8_Structure m2c dataout", false,-1);
        tracep->declBit(c+16,"BarrelShifter8_Structure m1c datain0", false,-1);
        tracep->declBit(c+12,"BarrelShifter8_Structure m1c datain1", false,-1);
        tracep->declBit(c+16,"BarrelShifter8_Structure m1c datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m1c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m1c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m1c sel1", false,-1);
        tracep->declBit(c+24,"BarrelShifter8_Structure m1c dataout", false,-1);
        tracep->declBit(c+17,"BarrelShifter8_Structure m0c datain0", false,-1);
        tracep->declBit(c+13,"BarrelShifter8_Structure m0c datain1", false,-1);
        tracep->declBit(c+17,"BarrelShifter8_Structure m0c datain2", false,-1);
        tracep->declBit(c+42,"BarrelShifter8_Structure m0c datain3", false,-1);
        tracep->declBit(c+41,"BarrelShifter8_Structure m0c sel0", false,-1);
        tracep->declBit(c+28,"BarrelShifter8_Structure m0c sel1", false,-1);
        tracep->declBit(c+25,"BarrelShifter8_Structure m0c dataout", false,-1);
    }
}

void VBarrelShifter8_Structure___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VBarrelShifter8_Structure___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VBarrelShifter8_Structure___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VBarrelShifter8_Structure___024root__traceRegister(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VBarrelShifter8_Structure___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VBarrelShifter8_Structure___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VBarrelShifter8_Structure___024root__traceCleanup, vlSelf);
    }
}

void VBarrelShifter8_Structure___024root__traceFullSub0(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VBarrelShifter8_Structure___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VBarrelShifter8_Structure___024root* const __restrict vlSelf = static_cast<VBarrelShifter8_Structure___024root*>(voidSelf);
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VBarrelShifter8_Structure___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VBarrelShifter8_Structure___024root__traceFullSub0(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->BarrelShifter8_Structure__DOT__mc_out));
        tracep->fullBit(oldp+2,(vlSelf->BarrelShifter8_Structure__DOT__m7a_out));
        tracep->fullBit(oldp+3,(vlSelf->BarrelShifter8_Structure__DOT__m6a_out));
        tracep->fullBit(oldp+4,(vlSelf->BarrelShifter8_Structure__DOT__m5a_out));
        tracep->fullBit(oldp+5,(vlSelf->BarrelShifter8_Structure__DOT__m4a_out));
        tracep->fullBit(oldp+6,(vlSelf->BarrelShifter8_Structure__DOT__m3a_out));
        tracep->fullBit(oldp+7,(vlSelf->BarrelShifter8_Structure__DOT__m2a_out));
        tracep->fullBit(oldp+8,(vlSelf->BarrelShifter8_Structure__DOT__m1a_out));
        tracep->fullBit(oldp+9,(vlSelf->BarrelShifter8_Structure__DOT__m0a_out));
        tracep->fullBit(oldp+10,(vlSelf->BarrelShifter8_Structure__DOT__m7b_out));
        tracep->fullBit(oldp+11,(vlSelf->BarrelShifter8_Structure__DOT__m6b_out));
        tracep->fullBit(oldp+12,(vlSelf->BarrelShifter8_Structure__DOT__m5b_out));
        tracep->fullBit(oldp+13,(vlSelf->BarrelShifter8_Structure__DOT__m4b_out));
        tracep->fullBit(oldp+14,(vlSelf->BarrelShifter8_Structure__DOT__m3b_out));
        tracep->fullBit(oldp+15,(vlSelf->BarrelShifter8_Structure__DOT__m2b_out));
        tracep->fullBit(oldp+16,(vlSelf->BarrelShifter8_Structure__DOT__m1b_out));
        tracep->fullBit(oldp+17,(vlSelf->BarrelShifter8_Structure__DOT__m0b_out));
        tracep->fullBit(oldp+18,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m7c__dataout));
        tracep->fullBit(oldp+19,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m6c__dataout));
        tracep->fullBit(oldp+20,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m5c__dataout));
        tracep->fullBit(oldp+21,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m4c__dataout));
        tracep->fullBit(oldp+22,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m3c__dataout));
        tracep->fullBit(oldp+23,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m2c__dataout));
        tracep->fullBit(oldp+24,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m1c__dataout));
        tracep->fullBit(oldp+25,(vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m0c__dataout));
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
