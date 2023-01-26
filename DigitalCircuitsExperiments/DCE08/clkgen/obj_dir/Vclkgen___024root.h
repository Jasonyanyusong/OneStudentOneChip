// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vclkgen.h for the primary calling header

#ifndef VERILATED_VCLKGEN___024ROOT_H_
#define VERILATED_VCLKGEN___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vclkgen__Syms;

//----------

VL_MODULE(Vclkgen___024root) {
  public:

    // PORTS
    VL_IN8(clkin,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(clken,0,0);
    VL_OUT8(clkout,0,0);

    // LOCAL SIGNALS
    IData/*31:0*/ clkgen__DOT__clkcount;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clkin;

    // INTERNAL VARIABLES
    Vclkgen__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vclkgen___024root);  ///< Copying not allowed
  public:
    Vclkgen___024root(const char* name);
    ~Vclkgen___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vclkgen__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
