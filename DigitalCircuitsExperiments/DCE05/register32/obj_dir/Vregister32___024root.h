// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister32.h for the primary calling header

#ifndef VERILATED_VREGISTER32___024ROOT_H_
#define VERILATED_VREGISTER32___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister32__Syms;
class Vregister32_VerilatedVcd;


//----------

VL_MODULE(Vregister32___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN(inp,31,0);
    VL_OUT(q,31,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister32__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister32___024root);  ///< Copying not allowed
  public:
    Vregister32___024root(const char* name);
    ~Vregister32___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister32__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
