// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAddCounter1bit.h for the primary calling header

#ifndef VERILATED_VADDCOUNTER1BIT___024ROOT_H_
#define VERILATED_VADDCOUNTER1BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VAddCounter1bit__Syms;
class VAddCounter1bit_VerilatedVcd;


//----------

VL_MODULE(VAddCounter1bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(out_q,0,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VAddCounter1bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VAddCounter1bit___024root);  ///< Copying not allowed
  public:
    VAddCounter1bit___024root(const char* name);
    ~VAddCounter1bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VAddCounter1bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
