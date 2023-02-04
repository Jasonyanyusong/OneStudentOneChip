// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VBarrelShifter_8Bit__Syms.h"


void VBarrelShifter_8Bit___024root__traceChgSub0(VBarrelShifter_8Bit___024root* vlSelf, VerilatedVcd* tracep);

void VBarrelShifter_8Bit___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VBarrelShifter_8Bit___024root* const __restrict vlSelf = static_cast<VBarrelShifter_8Bit___024root*>(voidSelf);
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VBarrelShifter_8Bit___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VBarrelShifter_8Bit___024root__traceChgSub0(VBarrelShifter_8Bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlSelf->BarrelShifter_8Bit__DOT__mc_out));
            tracep->chgBit(oldp+1,(vlSelf->BarrelShifter_8Bit__DOT__m7a_out));
            tracep->chgBit(oldp+2,(vlSelf->BarrelShifter_8Bit__DOT__m6a_out));
            tracep->chgBit(oldp+3,(vlSelf->BarrelShifter_8Bit__DOT__m5a_out));
            tracep->chgBit(oldp+4,(vlSelf->BarrelShifter_8Bit__DOT__m4a_out));
            tracep->chgBit(oldp+5,(vlSelf->BarrelShifter_8Bit__DOT__m3a_out));
            tracep->chgBit(oldp+6,(vlSelf->BarrelShifter_8Bit__DOT__m2a_out));
            tracep->chgBit(oldp+7,(vlSelf->BarrelShifter_8Bit__DOT__m1a_out));
            tracep->chgBit(oldp+8,(vlSelf->BarrelShifter_8Bit__DOT__m0a_out));
            tracep->chgBit(oldp+9,(vlSelf->BarrelShifter_8Bit__DOT__m7b_out));
            tracep->chgBit(oldp+10,(vlSelf->BarrelShifter_8Bit__DOT__m6b_out));
            tracep->chgBit(oldp+11,(vlSelf->BarrelShifter_8Bit__DOT__m5b_out));
            tracep->chgBit(oldp+12,(vlSelf->BarrelShifter_8Bit__DOT__m4b_out));
            tracep->chgBit(oldp+13,(vlSelf->BarrelShifter_8Bit__DOT__m3b_out));
            tracep->chgBit(oldp+14,(vlSelf->BarrelShifter_8Bit__DOT__m2b_out));
            tracep->chgBit(oldp+15,(vlSelf->BarrelShifter_8Bit__DOT__m1b_out));
            tracep->chgBit(oldp+16,(vlSelf->BarrelShifter_8Bit__DOT__m0b_out));
            tracep->chgBit(oldp+17,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout));
            tracep->chgBit(oldp+18,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout));
            tracep->chgBit(oldp+19,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout));
            tracep->chgBit(oldp+20,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout));
            tracep->chgBit(oldp+21,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout));
            tracep->chgBit(oldp+22,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout));
            tracep->chgBit(oldp+23,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout));
            tracep->chgBit(oldp+24,(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout));
        }
        tracep->chgCData(oldp+25,(vlSelf->din),8);
        tracep->chgCData(oldp+26,(vlSelf->shamt),3);
        tracep->chgBit(oldp+27,(vlSelf->lr));
        tracep->chgBit(oldp+28,(vlSelf->al));
        tracep->chgCData(oldp+29,(vlSelf->dout),8);
        tracep->chgBit(oldp+30,((1U & ((IData)(vlSelf->din) 
                                       >> 7U))));
        tracep->chgBit(oldp+31,((1U & ((IData)(vlSelf->din) 
                                       >> 6U))));
        tracep->chgBit(oldp+32,((1U & (IData)(vlSelf->shamt))));
        tracep->chgBit(oldp+33,((1U & ((IData)(vlSelf->din) 
                                       >> 5U))));
        tracep->chgBit(oldp+34,((1U & ((IData)(vlSelf->din) 
                                       >> 4U))));
        tracep->chgBit(oldp+35,((1U & ((IData)(vlSelf->din) 
                                       >> 3U))));
        tracep->chgBit(oldp+36,((1U & ((IData)(vlSelf->din) 
                                       >> 2U))));
        tracep->chgBit(oldp+37,((1U & ((IData)(vlSelf->din) 
                                       >> 1U))));
        tracep->chgBit(oldp+38,((1U & (IData)(vlSelf->din))));
        tracep->chgBit(oldp+39,((1U & ((IData)(vlSelf->shamt) 
                                       >> 1U))));
        tracep->chgBit(oldp+40,((1U & ((IData)(vlSelf->shamt) 
                                       >> 2U))));
    }
}

void VBarrelShifter_8Bit___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VBarrelShifter_8Bit___024root* const __restrict vlSelf = static_cast<VBarrelShifter_8Bit___024root*>(voidSelf);
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
