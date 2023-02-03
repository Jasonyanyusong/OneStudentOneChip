// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAddMinusALU_32__Syms.h"


void VAddMinusALU_32___024root__traceChgSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep);

void VAddMinusALU_32___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VAddMinusALU_32___024root* const __restrict vlSelf = static_cast<VAddMinusALU_32___024root*>(voidSelf);
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VAddMinusALU_32___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VAddMinusALU_32___024root__traceChgSub0(VAddMinusALU_32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->sub_add));
        tracep->chgIData(oldp+1,(vlSelf->a),32);
        tracep->chgIData(oldp+2,(vlSelf->b),32);
        tracep->chgBit(oldp+3,(vlSelf->carry));
        tracep->chgBit(oldp+4,(vlSelf->zero));
        tracep->chgBit(oldp+5,(vlSelf->overflow));
        tracep->chgIData(oldp+6,(vlSelf->result),32);
        tracep->chgIData(oldp+7,(vlSelf->AddMinusALU_32__DOT__t_no_Cin),32);
    }
}

void VAddMinusALU_32___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VAddMinusALU_32___024root* const __restrict vlSelf = static_cast<VAddMinusALU_32___024root*>(voidSelf);
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
