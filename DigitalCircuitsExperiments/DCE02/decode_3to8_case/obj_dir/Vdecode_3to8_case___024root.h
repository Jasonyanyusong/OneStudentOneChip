// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecode_3to8_case.h for the primary calling header

#ifndef VERILATED_VDECODE_3TO8_CASE___024ROOT_H_
#define VERILATED_VDECODE_3TO8_CASE___024ROOT_H_  // guard

#include "verilated.h"

class Vdecode_3to8_case__Syms;

class Vdecode_3to8_case___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(x,2,0);
    VL_OUT8(y,7,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdecode_3to8_case__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdecode_3to8_case___024root(Vdecode_3to8_case__Syms* symsp, const char* name);
    ~Vdecode_3to8_case___024root();
    VL_UNCOPYABLE(Vdecode_3to8_case___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
