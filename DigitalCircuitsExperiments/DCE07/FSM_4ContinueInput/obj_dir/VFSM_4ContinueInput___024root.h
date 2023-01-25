// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFSM_4ContinueInput.h for the primary calling header

#ifndef VERILATED_VFSM_4CONTINUEINPUT___024ROOT_H_
#define VERILATED_VFSM_4CONTINUEINPUT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VFSM_4ContinueInput__Syms;
class VFSM_4ContinueInput_VerilatedVcd;


//----------

VL_MODULE(VFSM_4ContinueInput___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(in,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(out,0,0);

    // LOCAL SIGNALS
    CData/*3:0*/ FSM_4ContinueInput__DOT__state_din;
    CData/*3:0*/ FSM_4ContinueInput__DOT__state_dout;
    CData/*0:0*/ FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out;
    CData/*0:0*/ FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit;
    CData/*3:0*/ FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out;
    CData/*0:0*/ FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit;
    VlUnpacked<CData/*4:0*/, 9> FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*3:0*/, 9> FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*0:0*/, 9> FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*7:0*/, 9> FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*3:0*/, 9> FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*3:0*/, 9> FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlWide<3>/*71:0*/ FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VFSM_4ContinueInput__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VFSM_4ContinueInput___024root);  ///< Copying not allowed
  public:
    VFSM_4ContinueInput___024root(const char* name);
    ~VFSM_4ContinueInput___024root();

    // INTERNAL METHODS
    void __Vconfigure(VFSM_4ContinueInput__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
