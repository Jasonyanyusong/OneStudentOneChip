// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux_4to1_Case.h for the primary calling header

#ifndef VERILATED_VMUX_4TO1_CASE___024ROOT_H_
#define VERILATED_VMUX_4TO1_CASE___024ROOT_H_  // guard

#include "verilated.h"

class Vmux_4to1_Case__Syms;

class Vmux_4to1_Case___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,3,0);
    VL_IN8(s,1,0);
    VL_OUT8(y,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmux_4to1_Case__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmux_4to1_Case___024root(Vmux_4to1_Case__Syms* symsp, const char* name);
    ~Vmux_4to1_Case___024root();
    VL_UNCOPYABLE(Vmux_4to1_Case___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
