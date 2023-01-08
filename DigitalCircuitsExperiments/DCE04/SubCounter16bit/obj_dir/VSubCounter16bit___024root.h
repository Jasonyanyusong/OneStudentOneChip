// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSubCounter16bit.h for the primary calling header

#ifndef VERILATED_VSUBCOUNTER16BIT___024ROOT_H_
#define VERILATED_VSUBCOUNTER16BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VSubCounter16bit__Syms;
class VSubCounter16bit_VerilatedVcd;


//----------

VL_MODULE(VSubCounter16bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT16(out_q,15,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VSubCounter16bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSubCounter16bit___024root);  ///< Copying not allowed
  public:
    VSubCounter16bit___024root(const char* name);
    ~VSubCounter16bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VSubCounter16bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
