// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2_keyboard_sim_fn__Syms.h"


void Vps2_keyboard_sim_fn___024root__traceInitSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vps2_keyboard_sim_fn___024root__traceInitTop(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vps2_keyboard_sim_fn___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vps2_keyboard_sim_fn___024root__traceInitSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+15,"clk", false,-1);
        tracep->declBit(c+16,"clrn", false,-1);
        tracep->declBit(c+17,"ps2_clk", false,-1);
        tracep->declBit(c+18,"ps2_data", false,-1);
        tracep->declBit(c+19,"nextdata_n", false,-1);
        tracep->declBus(c+20,"data", false,-1, 7,0);
        tracep->declBit(c+21,"ready", false,-1);
        tracep->declBit(c+22,"overflow", false,-1);
        tracep->declBit(c+15,"ps2_keyboard_sim_fn clk", false,-1);
        tracep->declBit(c+16,"ps2_keyboard_sim_fn clrn", false,-1);
        tracep->declBit(c+17,"ps2_keyboard_sim_fn ps2_clk", false,-1);
        tracep->declBit(c+18,"ps2_keyboard_sim_fn ps2_data", false,-1);
        tracep->declBit(c+19,"ps2_keyboard_sim_fn nextdata_n", false,-1);
        tracep->declBus(c+20,"ps2_keyboard_sim_fn data", false,-1, 7,0);
        tracep->declBit(c+21,"ps2_keyboard_sim_fn ready", false,-1);
        tracep->declBit(c+22,"ps2_keyboard_sim_fn overflow", false,-1);
        tracep->declBus(c+1,"ps2_keyboard_sim_fn buffer", false,-1, 9,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+2+i*1,"ps2_keyboard_sim_fn fifo", true,(i+0), 7,0);}}
        tracep->declBus(c+10,"ps2_keyboard_sim_fn w_ptr", false,-1, 2,0);
        tracep->declBus(c+11,"ps2_keyboard_sim_fn r_ptr", false,-1, 2,0);
        tracep->declBus(c+12,"ps2_keyboard_sim_fn count", false,-1, 3,0);
        tracep->declBus(c+13,"ps2_keyboard_sim_fn ps2_clk_sync", false,-1, 2,0);
        tracep->declBit(c+14,"ps2_keyboard_sim_fn sampling", false,-1);
    }
}

void Vps2_keyboard_sim_fn___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vps2_keyboard_sim_fn___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vps2_keyboard_sim_fn___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vps2_keyboard_sim_fn___024root__traceRegister(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vps2_keyboard_sim_fn___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vps2_keyboard_sim_fn___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vps2_keyboard_sim_fn___024root__traceCleanup, vlSelf);
    }
}

void Vps2_keyboard_sim_fn___024root__traceFullSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vps2_keyboard_sim_fn___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vps2_keyboard_sim_fn___024root* const __restrict vlSelf = static_cast<Vps2_keyboard_sim_fn___024root*>(voidSelf);
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vps2_keyboard_sim_fn___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vps2_keyboard_sim_fn___024root__traceFullSub0(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlSelf->ps2_keyboard_sim_fn__DOT__buffer),10);
        tracep->fullCData(oldp+2,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[0]),8);
        tracep->fullCData(oldp+3,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[1]),8);
        tracep->fullCData(oldp+4,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[2]),8);
        tracep->fullCData(oldp+5,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[3]),8);
        tracep->fullCData(oldp+6,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[4]),8);
        tracep->fullCData(oldp+7,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[5]),8);
        tracep->fullCData(oldp+8,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[6]),8);
        tracep->fullCData(oldp+9,(vlSelf->ps2_keyboard_sim_fn__DOT__fifo[7]),8);
        tracep->fullCData(oldp+10,(vlSelf->ps2_keyboard_sim_fn__DOT__w_ptr),3);
        tracep->fullCData(oldp+11,(vlSelf->ps2_keyboard_sim_fn__DOT__r_ptr),3);
        tracep->fullCData(oldp+12,(vlSelf->ps2_keyboard_sim_fn__DOT__count),4);
        tracep->fullCData(oldp+13,(vlSelf->ps2_keyboard_sim_fn__DOT__ps2_clk_sync),3);
        tracep->fullBit(oldp+14,((IData)((4U == (6U 
                                                 & (IData)(vlSelf->ps2_keyboard_sim_fn__DOT__ps2_clk_sync))))));
        tracep->fullBit(oldp+15,(vlSelf->clk));
        tracep->fullBit(oldp+16,(vlSelf->clrn));
        tracep->fullBit(oldp+17,(vlSelf->ps2_clk));
        tracep->fullBit(oldp+18,(vlSelf->ps2_data));
        tracep->fullBit(oldp+19,(vlSelf->nextdata_n));
        tracep->fullCData(oldp+20,(vlSelf->data),8);
        tracep->fullBit(oldp+21,(vlSelf->ready));
        tracep->fullBit(oldp+22,(vlSelf->overflow));
    }
}
