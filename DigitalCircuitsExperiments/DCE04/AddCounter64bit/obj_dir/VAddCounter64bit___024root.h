// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAddCounter64bit.h for the primary calling header

#ifndef VERILATED_VADDCOUNTER64BIT___024ROOT_H_
#define VERILATED_VADDCOUNTER64BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VAddCounter64bit__Syms;
class VAddCounter64bit_VerilatedVcd;


//----------

VL_MODULE(VAddCounter64bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT64(out_q,63,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VAddCounter64bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VAddCounter64bit___024root);  ///< Copying not allowed
  public:
    VAddCounter64bit___024root(const char* name);
    ~VAddCounter64bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VAddCounter64bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
