// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister64.h for the primary calling header

#ifndef VERILATED_VREGISTER64___024ROOT_H_
#define VERILATED_VREGISTER64___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister64__Syms;
class Vregister64_VerilatedVcd;


//----------

VL_MODULE(Vregister64___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(load,0,0);
    VL_IN8(clr,0,0);
    VL_IN64(inp,63,0);
    VL_OUT64(q,63,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vregister64__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister64___024root);  ///< Copying not allowed
  public:
    Vregister64___024root(const char* name);
    ~Vregister64___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vregister64__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
