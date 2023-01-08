// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister8.h for the primary calling header

#ifndef VERILATED_VREGISTER8___024ROOT_H_
#define VERILATED_VREGISTER8___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister8__Syms;
class Vregister8_VerilatedVcd;


//----------

VL_MODULE(Vregister8___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN8(inp,7,0);
    VL_OUT8(q,7,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister8__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister8___024root);  ///< Copying not allowed
  public:
    Vregister8___024root(const char* name);
    ~Vregister8___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister8__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
