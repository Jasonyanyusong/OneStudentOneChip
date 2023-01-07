// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSubCounter.h for the primary calling header

#ifndef VERILATED_VSUBCOUNTER___024ROOT_H_
#define VERILATED_VSUBCOUNTER___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VSubCounter__Syms;
class VSubCounter_VerilatedVcd;


//----------

VL_MODULE(VSubCounter___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(out_q,2,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VSubCounter__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSubCounter___024root);  ///< Copying not allowed
  public:
    VSubCounter___024root(const char* name);
    ~VSubCounter___024root();

    // INTERNAL METHODS
    void __Vconfigure(VSubCounter__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
