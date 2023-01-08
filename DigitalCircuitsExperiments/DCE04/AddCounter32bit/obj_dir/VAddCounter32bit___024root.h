// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAddCounter32bit.h for the primary calling header

#ifndef VERILATED_VADDCOUNTER32BIT___024ROOT_H_
#define VERILATED_VADDCOUNTER32BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VAddCounter32bit__Syms;
class VAddCounter32bit_VerilatedVcd;


//----------

VL_MODULE(VAddCounter32bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT(out_q,31,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VAddCounter32bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VAddCounter32bit___024root);  ///< Copying not allowed
  public:
    VAddCounter32bit___024root(const char* name);
    ~VAddCounter32bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VAddCounter32bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
