// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister2.h for the primary calling header

#ifndef VERILATED_VREGISTER2___024ROOT_H_
#define VERILATED_VREGISTER2___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister2__Syms;
class Vregister2_VerilatedVcd;


//----------

VL_MODULE(Vregister2___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN8(inp,1,0);
    VL_OUT8(q,1,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister2__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister2___024root);  ///< Copying not allowed
  public:
    Vregister2___024root(const char* name);
    ~Vregister2___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister2__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
