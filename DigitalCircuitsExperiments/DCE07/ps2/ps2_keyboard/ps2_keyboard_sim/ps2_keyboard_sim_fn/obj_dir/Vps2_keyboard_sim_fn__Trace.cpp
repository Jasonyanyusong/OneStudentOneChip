// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2_keyboard_sim_fn__Syms.h"


void Vps2_keyboard_sim_fn___024root__traceChgSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep);

void Vps2_keyboard_sim_fn___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vps2_keyboard_sim_fn___024root* const __restrict vlSelf = static_cast<Vps2_keyboard_sim_fn___024root*>(voidSelf);
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vps2_keyboard_sim_fn___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vps2_keyboard_sim_fn___024root__traceChgSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgSData(oldp+0,(vlSelf->ps2_keyboard_sim_fn__DOT__buffer),10);
            tracep->chgCData(oldp+1,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[0]),8);
            tracep->chgCData(oldp+2,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[1]),8);
            tracep->chgCData(oldp+3,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[2]),8);
            tracep->chgCData(oldp+4,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[3]),8);
            tracep->chgCData(oldp+5,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[4]),8);
            tracep->chgCData(oldp+6,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[5]),8);
            tracep->chgCData(oldp+7,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[6]),8);
            tracep->chgCData(oldp+8,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[7]),8);
            tracep->chgCData(oldp+9,(vlSelf->ps2_keyboard_sim_fn__DOT__w_ptr),3);
            tracep->chgCData(oldp+10,(vlSelf->ps2_keyboard_sim_fn__DOT__r_ptr),3);
            tracep->chgCData(oldp+11,(vlSelf->ps2_keyboard_sim_fn__DOT__count),4);
            tracep->chgCData(oldp+12,(vlSelf->ps2_keyboard_sim_fn__DOT__ps2_clk_sync),3);
            tracep->chgBit(oldp+13,((IData)((4U == 
                                             (6U & (IData)(vlSelf->ps2_keyboard_sim_fn__DOT__ps2_clk_sync))))));
        }
        tracep->chgBit(oldp+14,(vlSelf->clk));
        tracep->chgBit(oldp+15,(vlSelf->clrn));
        tracep->chgBit(oldp+16,(vlSelf->ps2_clk));
        tracep->chgBit(oldp+17,(vlSelf->ps2_data));
        tracep->chgBit(oldp+18,(vlSelf->nextdata_n));
        tracep->chgCData(oldp+19,(vlSelf->data),8);
        tracep->chgBit(oldp+20,(vlSelf->ready));
        tracep->chgBit(oldp+21,(vlSelf->overflow));
    }
}

void Vps2_keyboard_sim_fn___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    Vps2_keyboard_sim_fn___024root* const __restrict vlSelf = static_cast<Vps2_keyboard_sim_fn___024root*>(voidSelf);
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
