// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAddMinusALU_32.h for the primary calling header

#ifndef VERILATED_VADDMINUSALU_32___024ROOT_H_
#define VERILATED_VADDMINUSALU_32___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VAddMinusALU_32__Syms;
class VAddMinusALU_32_VerilatedVcd;


//----------

VL_MODULE(VAddMinusALU_32___024root) {
  public:

    // PORTS
    VL_IN8(sub_add,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(overflow,0,0);
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);

    // LOCAL SIGNALS
    IData/*31:0*/ AddMinusALU_32__DOT__t_no_Cin;

    // INTERNAL VARIABLES
    VAddMinusALU_32__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VAddMinusALU_32___024root);  ///< Copying not allowed
  public:
    VAddMinusALU_32___024root(const char* name);
    ~VAddMinusALU_32___024root();

    // INTERNAL METHODS
    void __Vconfigure(VAddMinusALU_32__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
