// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU32.h for the primary calling header

#ifndef VERILATED_VALU32___024ROOT_H_
#define VERILATED_VALU32___024ROOT_H_  // guard

#include "verilated.h"

class VALU32__Syms;

class VALU32___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sub_add,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(overflow,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__sub_add;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ ALU32__DOT__b_withCin;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VALU32__Syms* const vlSymsp;

    // CONSTRUCTORS
    VALU32___024root(VALU32__Syms* symsp, const char* name);
    ~VALU32___024root();
    VL_UNCOPYABLE(VALU32___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
