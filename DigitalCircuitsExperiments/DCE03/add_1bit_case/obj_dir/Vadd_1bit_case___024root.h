// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_1bit_case.h for the primary calling header

#ifndef VERILATED_VADD_1BIT_CASE___024ROOT_H_
#define VERILATED_VADD_1BIT_CASE___024ROOT_H_  // guard

#include "verilated.h"

class Vadd_1bit_case__Syms;

class Vadd_1bit_case___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(c_i,0,0);
    VL_IN8(a_i,0,0);
    VL_IN8(b_i,0,0);
    VL_OUT8(s_i,0,0);
    VL_OUT8(c_iplus1,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_1bit_case__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_1bit_case___024root(Vadd_1bit_case__Syms* symsp, const char* name);
    ~Vadd_1bit_case___024root();
    VL_UNCOPYABLE(Vadd_1bit_case___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
