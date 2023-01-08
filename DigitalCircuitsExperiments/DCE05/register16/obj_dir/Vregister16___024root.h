// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister16.h for the primary calling header

#ifndef VERILATED_VREGISTER16___024ROOT_H_
#define VERILATED_VREGISTER16___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister16__Syms;
class Vregister16_VerilatedVcd;


//----------

VL_MODULE(Vregister16___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN16(inp,15,0);
    VL_OUT16(q,15,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister16__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister16___024root);  ///< Copying not allowed
  public:
    Vregister16___024root(const char* name);
    ~Vregister16___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister16__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
