// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSubCounter64bit.h for the primary calling header

#ifndef VERILATED_VSUBCOUNTER64BIT___024ROOT_H_
#define VERILATED_VSUBCOUNTER64BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VSubCounter64bit__Syms;
class VSubCounter64bit_VerilatedVcd;


//----------

VL_MODULE(VSubCounter64bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT64(out_q,63,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VSubCounter64bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSubCounter64bit___024root);  ///< Copying not allowed
  public:
    VSubCounter64bit___024root(const char* name);
    ~VSubCounter64bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VSubCounter64bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
