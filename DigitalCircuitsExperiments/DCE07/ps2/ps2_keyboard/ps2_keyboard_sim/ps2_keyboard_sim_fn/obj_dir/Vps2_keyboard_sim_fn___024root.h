// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vps2_keyboard_sim_fn.h for the primary calling header

#ifndef VERILATED_VPS2_KEYBOARD_SIM_FN___024ROOT_H_
#define VERILATED_VPS2_KEYBOARD_SIM_FN___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vps2_keyboard_sim_fn__Syms;
class Vps2_keyboard_sim_fn_VerilatedVcd;


//----------

VL_MODULE(Vps2_keyboard_sim_fn___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(clrn,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_IN8(nextdata_n,0,0);
    VL_OUT8(data,7,0);
    VL_OUT8(ready,0,0);
    VL_OUT8(overflow,0,0);

    // LOCAL SIGNALS
    CData/*2:0*/ ps2_keyboard_sim_fn__DOT__w_ptr;
    CData/*2:0*/ ps2_keyboard_sim_fn__DOT__r_ptr;
    CData/*3:0*/ ps2_keyboard_sim_fn__DOT__count;
    CData/*2:0*/ ps2_keyboard_sim_fn__DOT__ps2_clk_sync;
    SData/*9:0*/ ps2_keyboard_sim_fn__DOT__buffer;
    VlUnpacked<CData/*7:0*/, 8> ps2_keyboard_sim_fn__DOT__fifo;

    // LOCAL VARIABLES
    CData/*0:0*/ ps2_keyboard_sim_fn__DOT____Vlvbound1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vps2_keyboard_sim_fn__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vps2_keyboard_sim_fn___024root);  ///< Copying not allowed
  public:
    Vps2_keyboard_sim_fn___024root(const char* name);
    ~Vps2_keyboard_sim_fn___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vps2_keyboard_sim_fn__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
