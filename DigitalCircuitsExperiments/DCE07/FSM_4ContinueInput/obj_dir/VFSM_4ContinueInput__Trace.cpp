// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFSM_4ContinueInput__Syms.h"


void VFSM_4ContinueInput___024root__traceChgSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep);

void VFSM_4ContinueInput___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VFSM_4ContinueInput___024root* const __restrict vlSelf = static_cast<VFSM_4ContinueInput___024root*>(voidSelf);
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VFSM_4ContinueInput___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VFSM_4ContinueInput___024root__traceChgSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
            tracep->chgCData(oldp+0,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[0]),5);
            tracep->chgCData(oldp+1,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[1]),5);
            tracep->chgCData(oldp+2,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[2]),5);
            tracep->chgCData(oldp+3,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[3]),5);
            tracep->chgCData(oldp+4,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[4]),5);
            tracep->chgCData(oldp+5,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[5]),5);
            tracep->chgCData(oldp+6,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[6]),5);
            tracep->chgCData(oldp+7,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[7]),5);
            tracep->chgCData(oldp+8,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[8]),5);
            tracep->chgCData(oldp+9,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[0]),4);
            tracep->chgCData(oldp+10,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[1]),4);
            tracep->chgCData(oldp+11,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[2]),4);
            tracep->chgCData(oldp+12,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[3]),4);
            tracep->chgCData(oldp+13,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[4]),4);
            tracep->chgCData(oldp+14,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[5]),4);
            tracep->chgCData(oldp+15,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[6]),4);
            tracep->chgCData(oldp+16,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[7]),4);
            tracep->chgCData(oldp+17,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[8]),4);
            tracep->chgBit(oldp+18,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[0]));
            tracep->chgBit(oldp+19,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[1]));
            tracep->chgBit(oldp+20,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[2]));
            tracep->chgBit(oldp+21,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[3]));
            tracep->chgBit(oldp+22,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[4]));
            tracep->chgBit(oldp+23,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[5]));
            tracep->chgBit(oldp+24,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[6]));
            tracep->chgBit(oldp+25,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[7]));
            tracep->chgBit(oldp+26,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[8]));
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+27,(vlSelf->FSM_4ContinueInput__DOT__state_dout),4);
            tracep->chgBit(oldp+28,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out));
            tracep->chgBit(oldp+29,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit));
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+30,(vlSelf->FSM_4ContinueInput__DOT__state_din),4);
            tracep->chgWData(oldp+31,(vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut),72);
            tracep->chgCData(oldp+34,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[0]),8);
            tracep->chgCData(oldp+35,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[1]),8);
            tracep->chgCData(oldp+36,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[2]),8);
            tracep->chgCData(oldp+37,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[3]),8);
            tracep->chgCData(oldp+38,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[4]),8);
            tracep->chgCData(oldp+39,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[5]),8);
            tracep->chgCData(oldp+40,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[6]),8);
            tracep->chgCData(oldp+41,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[7]),8);
            tracep->chgCData(oldp+42,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[8]),8);
            tracep->chgCData(oldp+43,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[0]),4);
            tracep->chgCData(oldp+44,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[1]),4);
            tracep->chgCData(oldp+45,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[2]),4);
            tracep->chgCData(oldp+46,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[3]),4);
            tracep->chgCData(oldp+47,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[4]),4);
            tracep->chgCData(oldp+48,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[5]),4);
            tracep->chgCData(oldp+49,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[6]),4);
            tracep->chgCData(oldp+50,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[7]),4);
            tracep->chgCData(oldp+51,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[8]),4);
            tracep->chgCData(oldp+52,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[0]),4);
            tracep->chgCData(oldp+53,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[1]),4);
            tracep->chgCData(oldp+54,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[2]),4);
            tracep->chgCData(oldp+55,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[3]),4);
            tracep->chgCData(oldp+56,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[4]),4);
            tracep->chgCData(oldp+57,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[5]),4);
            tracep->chgCData(oldp+58,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[6]),4);
            tracep->chgCData(oldp+59,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[7]),4);
            tracep->chgCData(oldp+60,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[8]),4);
            tracep->chgCData(oldp+61,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out),4);
            tracep->chgBit(oldp+62,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit));
        }
        tracep->chgBit(oldp+63,(vlSelf->clk));
        tracep->chgBit(oldp+64,(vlSelf->in));
        tracep->chgBit(oldp+65,(vlSelf->reset));
        tracep->chgBit(oldp+66,(vlSelf->out));
    }
}

void VFSM_4ContinueInput___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VFSM_4ContinueInput___024root* const __restrict vlSelf = static_cast<VFSM_4ContinueInput___024root*>(voidSelf);
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
