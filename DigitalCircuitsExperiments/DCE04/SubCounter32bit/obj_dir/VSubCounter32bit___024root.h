// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSubCounter32bit.h for the primary calling header

#ifndef VERILATED_VSUBCOUNTER32BIT___024ROOT_H_
#define VERILATED_VSUBCOUNTER32BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VSubCounter32bit__Syms;
class VSubCounter32bit_VerilatedVcd;


//----------

VL_MODULE(VSubCounter32bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT(out_q,31,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VSubCounter32bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSubCounter32bit___024root);  ///< Copying not allowed
  public:
    VSubCounter32bit___024root(const char* name);
    ~VSubCounter32bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VSubCounter32bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
