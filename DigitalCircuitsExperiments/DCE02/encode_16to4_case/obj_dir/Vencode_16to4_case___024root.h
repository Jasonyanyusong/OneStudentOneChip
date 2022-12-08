// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode_16to4_case.h for the primary calling header

#ifndef VERILATED_VENCODE_16TO4_CASE___024ROOT_H_
#define VERILATED_VENCODE_16TO4_CASE___024ROOT_H_  // guard

#include "verilated.h"

class Vencode_16to4_case__Syms;

class Vencode_16to4_case___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_OUT8(y,3,0);
    CData/*0:0*/ __VactContinue;
    VL_IN16(x,15,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vencode_16to4_case__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vencode_16to4_case___024root(Vencode_16to4_case__Syms* symsp, const char* name);
    ~Vencode_16to4_case___024root();
    VL_UNCOPYABLE(Vencode_16to4_case___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
