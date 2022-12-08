// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecode_5to32_case.h for the primary calling header

#ifndef VERILATED_VDECODE_5TO32_CASE___024ROOT_H_
#define VERILATED_VDECODE_5TO32_CASE___024ROOT_H_  // guard

#include "verilated.h"

class Vdecode_5to32_case__Syms;

class Vdecode_5to32_case___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(x,4,0);
    CData/*0:0*/ __VactContinue;
    VL_OUT(y,31,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdecode_5to32_case__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdecode_5to32_case___024root(Vdecode_5to32_case__Syms* symsp, const char* name);
    ~Vdecode_5to32_case___024root();
    VL_UNCOPYABLE(Vdecode_5to32_case___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
