// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtest_our_cpp.h for the primary calling header

#ifndef VERILATED_VTEST_OUR_CPP___024ROOT_H_
#define VERILATED_VTEST_OUR_CPP___024ROOT_H_  // guard

#include "verilated.h"

class Vtest_our_cpp__Syms;

class Vtest_our_cpp___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtest_our_cpp__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtest_our_cpp___024root(Vtest_our_cpp__Syms* symsp, const char* name);
    ~Vtest_our_cpp___024root();
    VL_UNCOPYABLE(Vtest_our_cpp___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
