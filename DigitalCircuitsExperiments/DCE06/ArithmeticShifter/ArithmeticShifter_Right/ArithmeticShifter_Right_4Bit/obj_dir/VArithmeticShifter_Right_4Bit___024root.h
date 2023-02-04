// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VArithmeticShifter_Right_4Bit.h for the primary calling header

#ifndef VERILATED_VARITHMETICSHIFTER_RIGHT_4BIT___024ROOT_H_
#define VERILATED_VARITHMETICSHIFTER_RIGHT_4BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VArithmeticShifter_Right_4Bit__Syms;
class VArithmeticShifter_Right_4Bit_VerilatedVcd;


//----------

VL_MODULE(VArithmeticShifter_Right_4Bit___024root) {
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
    VArithmeticShifter_Right_4Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VArithmeticShifter_Right_4Bit___024root);  ///< Copying not allowed
  public:
    VArithmeticShifter_Right_4Bit___024root(const char* name);
    ~VArithmeticShifter_Right_4Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VArithmeticShifter_Right_4Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
