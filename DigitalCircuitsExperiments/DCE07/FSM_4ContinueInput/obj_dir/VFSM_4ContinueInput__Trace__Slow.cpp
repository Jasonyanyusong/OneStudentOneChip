// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFSM_4ContinueInput__Syms.h"


void VFSM_4ContinueInput___024root__traceInitSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VFSM_4ContinueInput___024root__traceInitTop(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VFSM_4ContinueInput___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VFSM_4ContinueInput___024root__traceInitSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+64,"clk", false,-1);
        tracep->declBit(c+65,"in", false,-1);
        tracep->declBit(c+66,"reset", false,-1);
        tracep->declBit(c+67,"out", false,-1);
        tracep->declBit(c+64,"FSM_4ContinueInput clk", false,-1);
        tracep->declBit(c+65,"FSM_4ContinueInput in", false,-1);
        tracep->declBit(c+66,"FSM_4ContinueInput reset", false,-1);
        tracep->declBit(c+67,"FSM_4ContinueInput out", false,-1);
        tracep->declBus(c+68,"FSM_4ContinueInput S0", false,-1, 3,0);
        tracep->declBus(c+69,"FSM_4ContinueInput S1", false,-1, 3,0);
        tracep->declBus(c+70,"FSM_4ContinueInput S2", false,-1, 3,0);
        tracep->declBus(c+71,"FSM_4ContinueInput S3", false,-1, 3,0);
        tracep->declBus(c+72,"FSM_4ContinueInput S4", false,-1, 3,0);
        tracep->declBus(c+73,"FSM_4ContinueInput S5", false,-1, 3,0);
        tracep->declBus(c+74,"FSM_4ContinueInput S6", false,-1, 3,0);
        tracep->declBus(c+75,"FSM_4ContinueInput S7", false,-1, 3,0);
        tracep->declBus(c+76,"FSM_4ContinueInput S8", false,-1, 3,0);
        tracep->declBus(c+31,"FSM_4ContinueInput state_din", false,-1, 3,0);
        tracep->declBus(c+28,"FSM_4ContinueInput state_dout", false,-1, 3,0);
        tracep->declBit(c+77,"FSM_4ContinueInput state_wen", false,-1);
        tracep->declBit(c+64,"FSM_4ContinueInput state Module_clock", false,-1);
        tracep->declBit(c+66,"FSM_4ContinueInput state Module_reset", false,-1);
        tracep->declBit(c+77,"FSM_4ContinueInput state Module_write_enable", false,-1);
        tracep->declBus(c+31,"FSM_4ContinueInput state Module_input", false,-1, 3,0);
        tracep->declBus(c+28,"FSM_4ContinueInput state Module_output", false,-1, 3,0);
        tracep->declBus(c+78,"FSM_4ContinueInput outMux NR_KEY", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput outMux KEY_LEN", false,-1, 31,0);
        tracep->declBus(c+80,"FSM_4ContinueInput outMux DATA_LEN", false,-1, 31,0);
        tracep->declBus(c+67,"FSM_4ContinueInput outMux out", false,-1, 0,0);
        tracep->declBus(c+28,"FSM_4ContinueInput outMux key", false,-1, 3,0);
        tracep->declBus(c+81,"FSM_4ContinueInput outMux default_out", false,-1, 0,0);
        tracep->declQuad(c+82,"FSM_4ContinueInput outMux lut", false,-1, 44,0);
        tracep->declBus(c+78,"FSM_4ContinueInput outMux i0 NR_KEY", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput outMux i0 KEY_LEN", false,-1, 31,0);
        tracep->declBus(c+80,"FSM_4ContinueInput outMux i0 DATA_LEN", false,-1, 31,0);
        tracep->declBus(c+80,"FSM_4ContinueInput outMux i0 HAS_DEFAULT", false,-1, 31,0);
        tracep->declBus(c+67,"FSM_4ContinueInput outMux i0 out", false,-1, 0,0);
        tracep->declBus(c+28,"FSM_4ContinueInput outMux i0 key", false,-1, 3,0);
        tracep->declBus(c+81,"FSM_4ContinueInput outMux i0 default_out", false,-1, 0,0);
        tracep->declQuad(c+82,"FSM_4ContinueInput outMux i0 lut", false,-1, 44,0);
        tracep->declBus(c+84,"FSM_4ContinueInput outMux i0 PAIR_LEN", false,-1, 31,0);
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+1+i*1,"FSM_4ContinueInput outMux i0 pair_list", true,(i+0), 4,0);}}
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+10+i*1,"FSM_4ContinueInput outMux i0 key_list", true,(i+0), 3,0);}}
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+19+i*1,"FSM_4ContinueInput outMux i0 data_list", true,(i+0), 0,0);}}
        tracep->declBus(c+29,"FSM_4ContinueInput outMux i0 lut_out", false,-1, 0,0);
        tracep->declBit(c+30,"FSM_4ContinueInput outMux i0 hit", false,-1);
        tracep->declBus(c+85,"FSM_4ContinueInput outMux i0 i", false,-1, 31,0);
        tracep->declBus(c+78,"FSM_4ContinueInput stateMux NR_KEY", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput stateMux KEY_LEN", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput stateMux DATA_LEN", false,-1, 31,0);
        tracep->declBus(c+31,"FSM_4ContinueInput stateMux out", false,-1, 3,0);
        tracep->declBus(c+28,"FSM_4ContinueInput stateMux key", false,-1, 3,0);
        tracep->declBus(c+68,"FSM_4ContinueInput stateMux default_out", false,-1, 3,0);
        tracep->declArray(c+32,"FSM_4ContinueInput stateMux lut", false,-1, 71,0);
        tracep->declBus(c+78,"FSM_4ContinueInput stateMux i0 NR_KEY", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput stateMux i0 KEY_LEN", false,-1, 31,0);
        tracep->declBus(c+79,"FSM_4ContinueInput stateMux i0 DATA_LEN", false,-1, 31,0);
        tracep->declBus(c+80,"FSM_4ContinueInput stateMux i0 HAS_DEFAULT", false,-1, 31,0);
        tracep->declBus(c+31,"FSM_4ContinueInput stateMux i0 out", false,-1, 3,0);
        tracep->declBus(c+28,"FSM_4ContinueInput stateMux i0 key", false,-1, 3,0);
        tracep->declBus(c+68,"FSM_4ContinueInput stateMux i0 default_out", false,-1, 3,0);
        tracep->declArray(c+32,"FSM_4ContinueInput stateMux i0 lut", false,-1, 71,0);
        tracep->declBus(c+86,"FSM_4ContinueInput stateMux i0 PAIR_LEN", false,-1, 31,0);
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+35+i*1,"FSM_4ContinueInput stateMux i0 pair_list", true,(i+0), 7,0);}}
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+44+i*1,"FSM_4ContinueInput stateMux i0 key_list", true,(i+0), 3,0);}}
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+53+i*1,"FSM_4ContinueInput stateMux i0 data_list", true,(i+0), 3,0);}}
        tracep->declBus(c+62,"FSM_4ContinueInput stateMux i0 lut_out", false,-1, 3,0);
        tracep->declBit(c+63,"FSM_4ContinueInput stateMux i0 hit", false,-1);
        tracep->declBus(c+85,"FSM_4ContinueInput stateMux i0 i", false,-1, 31,0);
    }
}

void VFSM_4ContinueInput___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VFSM_4ContinueInput___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VFSM_4ContinueInput___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VFSM_4ContinueInput___024root__traceRegister(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VFSM_4ContinueInput___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VFSM_4ContinueInput___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VFSM_4ContinueInput___024root__traceCleanup, vlSelf);
    }
}

void VFSM_4ContinueInput___024root__traceFullSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VFSM_4ContinueInput___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VFSM_4ContinueInput___024root* const __restrict vlSelf = static_cast<VFSM_4ContinueInput___024root*>(voidSelf);
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VFSM_4ContinueInput___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VFSM_4ContinueInput___024root__traceFullSub0(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[0]),5);
        tracep->fullCData(oldp+2,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[1]),5);
        tracep->fullCData(oldp+3,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[2]),5);
        tracep->fullCData(oldp+4,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[3]),5);
        tracep->fullCData(oldp+5,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[4]),5);
        tracep->fullCData(oldp+6,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[5]),5);
        tracep->fullCData(oldp+7,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[6]),5);
        tracep->fullCData(oldp+8,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[7]),5);
        tracep->fullCData(oldp+9,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[8]),5);
        tracep->fullCData(oldp+10,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[0]),4);
        tracep->fullCData(oldp+11,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[1]),4);
        tracep->fullCData(oldp+12,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[2]),4);
        tracep->fullCData(oldp+13,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[3]),4);
        tracep->fullCData(oldp+14,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[4]),4);
        tracep->fullCData(oldp+15,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[5]),4);
        tracep->fullCData(oldp+16,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[6]),4);
        tracep->fullCData(oldp+17,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[7]),4);
        tracep->fullCData(oldp+18,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[8]),4);
        tracep->fullBit(oldp+19,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[0]));
        tracep->fullBit(oldp+20,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[1]));
        tracep->fullBit(oldp+21,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[2]));
        tracep->fullBit(oldp+22,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[3]));
        tracep->fullBit(oldp+23,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[4]));
        tracep->fullBit(oldp+24,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[5]));
        tracep->fullBit(oldp+25,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[6]));
        tracep->fullBit(oldp+26,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[7]));
        tracep->fullBit(oldp+27,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[8]));
        tracep->fullCData(oldp+28,(vlSelf->FSM_4ContinueInput__DOT__state_dout),4);
        tracep->fullBit(oldp+29,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out));
        tracep->fullBit(oldp+30,(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit));
        tracep->fullCData(oldp+31,(vlSelf->FSM_4ContinueInput__DOT__state_din),4);
        tracep->fullWData(oldp+32,(vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut),72);
        tracep->fullCData(oldp+35,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[0]),8);
        tracep->fullCData(oldp+36,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[1]),8);
        tracep->fullCData(oldp+37,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[2]),8);
        tracep->fullCData(oldp+38,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[3]),8);
        tracep->fullCData(oldp+39,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[4]),8);
        tracep->fullCData(oldp+40,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[5]),8);
        tracep->fullCData(oldp+41,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[6]),8);
        tracep->fullCData(oldp+42,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[7]),8);
        tracep->fullCData(oldp+43,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[8]),8);
        tracep->fullCData(oldp+44,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[0]),4);
        tracep->fullCData(oldp+45,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[1]),4);
        tracep->fullCData(oldp+46,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[2]),4);
        tracep->fullCData(oldp+47,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[3]),4);
        tracep->fullCData(oldp+48,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[4]),4);
        tracep->fullCData(oldp+49,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[5]),4);
        tracep->fullCData(oldp+50,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[6]),4);
        tracep->fullCData(oldp+51,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[7]),4);
        tracep->fullCData(oldp+52,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[8]),4);
        tracep->fullCData(oldp+53,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[0]),4);
        tracep->fullCData(oldp+54,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[1]),4);
        tracep->fullCData(oldp+55,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[2]),4);
        tracep->fullCData(oldp+56,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[3]),4);
        tracep->fullCData(oldp+57,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[4]),4);
        tracep->fullCData(oldp+58,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[5]),4);
        tracep->fullCData(oldp+59,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[6]),4);
        tracep->fullCData(oldp+60,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[7]),4);
        tracep->fullCData(oldp+61,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[8]),4);
        tracep->fullCData(oldp+62,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out),4);
        tracep->fullBit(oldp+63,(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit));
        tracep->fullBit(oldp+64,(vlSelf->clk));
        tracep->fullBit(oldp+65,(vlSelf->in));
        tracep->fullBit(oldp+66,(vlSelf->reset));
        tracep->fullBit(oldp+67,(vlSelf->out));
        tracep->fullCData(oldp+68,(0U),4);
        tracep->fullCData(oldp+69,(1U),4);
        tracep->fullCData(oldp+70,(2U),4);
        tracep->fullCData(oldp+71,(3U),4);
        tracep->fullCData(oldp+72,(4U),4);
        tracep->fullCData(oldp+73,(5U),4);
        tracep->fullCData(oldp+74,(6U),4);
        tracep->fullCData(oldp+75,(7U),4);
        tracep->fullCData(oldp+76,(8U),4);
        tracep->fullBit(oldp+77,(1U));
        tracep->fullIData(oldp+78,(9U),32);
        tracep->fullIData(oldp+79,(4U),32);
        tracep->fullIData(oldp+80,(1U),32);
        tracep->fullBit(oldp+81,(0U));
        tracep->fullQData(oldp+82,(0x110c9531d1ULL),45);
        tracep->fullIData(oldp+84,(5U),32);
        tracep->fullIData(oldp+85,(9U),32);
        tracep->fullIData(oldp+86,(8U),32);
    }
}
