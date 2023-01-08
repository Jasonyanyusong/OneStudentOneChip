// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister1.h for the primary calling header

#ifndef VERILATED_VREGISTER1___024ROOT_H_
#define VERILATED_VREGISTER1___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister1__Syms;
class Vregister1_VerilatedVcd;


//----------

VL_MODULE(Vregister1___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN8(inp,0,0);
    VL_OUT8(q,0,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister1__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister1___024root);  ///< Copying not allowed
  public:
    Vregister1___024root(const char* name);
    ~Vregister1___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister1__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
