// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCyclicShifter_Right_4Bit.h for the primary calling header

#ifndef VERILATED_VCYCLICSHIFTER_RIGHT_4BIT___024ROOT_H_
#define VERILATED_VCYCLICSHIFTER_RIGHT_4BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VCyclicShifter_Right_4Bit__Syms;
class VCyclicShifter_Right_4Bit_VerilatedVcd;


//----------

VL_MODULE(VCyclicShifter_Right_4Bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(clr,0,0);
    VL_IN8(load,0,0);
    VL_IN8(inp,3,0);
    VL_OUT8(outp,3,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VCyclicShifter_Right_4Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCyclicShifter_Right_4Bit___024root);  ///< Copying not allowed
  public:
    VCyclicShifter_Right_4Bit___024root(const char* name);
    ~VCyclicShifter_Right_4Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VCyclicShifter_Right_4Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
