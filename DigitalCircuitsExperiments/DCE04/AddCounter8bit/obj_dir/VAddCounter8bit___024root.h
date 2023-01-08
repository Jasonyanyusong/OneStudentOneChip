// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAddCounter8bit.h for the primary calling header

#ifndef VERILATED_VADDCOUNTER8BIT___024ROOT_H_
#define VERILATED_VADDCOUNTER8BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VAddCounter8bit__Syms;
class VAddCounter8bit_VerilatedVcd;


//----------

VL_MODULE(VAddCounter8bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(out_q,7,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VAddCounter8bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VAddCounter8bit___024root);  ///< Copying not allowed
  public:
    VAddCounter8bit___024root(const char* name);
    ~VAddCounter8bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VAddCounter8bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
