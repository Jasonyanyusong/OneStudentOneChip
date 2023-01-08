// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister4.h for the primary calling header

#ifndef VERILATED_VREGISTER4___024ROOT_H_
#define VERILATED_VREGISTER4___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister4__Syms;
class Vregister4_VerilatedVcd;


//----------

VL_MODULE(Vregister4___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN8(inp,3,0);
    VL_OUT8(q,3,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister4__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister4___024root);  ///< Copying not allowed
  public:
    Vregister4___024root(const char* name);
    ~Vregister4___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister4__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
