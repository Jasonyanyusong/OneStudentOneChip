// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAddMinusALU_32__Syms.h"


void VAddMinusALU_32___024root__traceInitSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VAddMinusALU_32___024root__traceInitTop(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VAddMinusALU_32___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VAddMinusALU_32___024root__traceInitSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"sub_add", false,-1);
        tracep->declBus(c+2,"a", false,-1, 31,0);
        tracep->declBus(c+3,"b", false,-1, 31,0);
        tracep->declBit(c+4,"carry", false,-1);
        tracep->declBit(c+5,"zero", false,-1);
        tracep->declBit(c+6,"overflow", false,-1);
        tracep->declBus(c+7,"result", false,-1, 31,0);
        tracep->declBit(c+1,"AddMinusALU_32 sub_add", false,-1);
        tracep->declBus(c+2,"AddMinusALU_32 a", false,-1, 31,0);
        tracep->declBus(c+3,"AddMinusALU_32 b", false,-1, 31,0);
        tracep->declBit(c+4,"AddMinusALU_32 carry", false,-1);
        tracep->declBit(c+5,"AddMinusALU_32 zero", false,-1);
        tracep->declBit(c+6,"AddMinusALU_32 overflow", false,-1);
        tracep->declBus(c+7,"AddMinusALU_32 result", false,-1, 31,0);
        tracep->declBit(c+1,"AddMinusALU_32 Cin", false,-1);
        tracep->declBus(c+8,"AddMinusALU_32 t_no_Cin", false,-1, 31,0);
    }
}

void VAddMinusALU_32___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VAddMinusALU_32___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VAddMinusALU_32___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VAddMinusALU_32___024root__traceRegister(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VAddMinusALU_32___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VAddMinusALU_32___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VAddMinusALU_32___024root__traceCleanup, vlSelf);
    }
}

void VAddMinusALU_32___024root__traceFullSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VAddMinusALU_32___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VAddMinusALU_32___024root* const __restrict vlSelf = static_cast<VAddMinusALU_32___024root*>(voidSelf);
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VAddMinusALU_32___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VAddMinusALU_32___024root__traceFullSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->sub_add));
        tracep->fullIData(oldp+2,(vlSelf->a),32);
        tracep->fullIData(oldp+3,(vlSelf->b),32);
        tracep->fullBit(oldp+4,(vlSelf->carry));
        tracep->fullBit(oldp+5,(vlSelf->zero));
        tracep->fullBit(oldp+6,(vlSelf->overflow));
        tracep->fullIData(oldp+7,(vlSelf->result),32);
        tracep->fullIData(oldp+8,(vlSelf->AddMinusALU_32__DOT__t_no_Cin),32);
    }
}
