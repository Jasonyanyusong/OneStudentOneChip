// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU4Bit_All__Syms.h"


void VALU4Bit_All___024root__traceChgSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep);

void VALU4Bit_All___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VALU4Bit_All___024root* const __restrict vlSelf = static_cast<VALU4Bit_All___024root*>(voidSelf);
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VALU4Bit_All___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VALU4Bit_All___024root__traceChgSub0(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlSelf->ALU4Bit_All__DOT__Cin));
            tracep->chgCData(oldp+1,(vlSelf->ALU4Bit_All__DOT__t_no_Cin),4);
            tracep->chgCData(oldp+2,(vlSelf->ALU4Bit_All__DOT__carry_and_result),5);
            tracep->chgIData(oldp+3,(vlSelf->ALU4Bit_All__DOT__i),32);
        }
        tracep->chgCData(oldp+4,(vlSelf->sel),3);
        tracep->chgCData(oldp+5,(vlSelf->a),4);
        tracep->chgCData(oldp+6,(vlSelf->b),4);
        tracep->chgCData(oldp+7,(vlSelf->result),4);
        tracep->chgBit(oldp+8,(vlSelf->overflow));
        tracep->chgBit(oldp+9,(vlSelf->carry));
        tracep->chgBit(oldp+10,(vlSelf->zero));
    }
}

void VALU4Bit_All___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VALU4Bit_All___024root* const __restrict vlSelf = static_cast<VALU4Bit_All___024root*>(voidSelf);
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
