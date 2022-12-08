// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbcd7seg_case_coPositive.h for the primary calling header

#ifndef VERILATED_VBCD7SEG_CASE_COPOSITIVE___024ROOT_H_
#define VERILATED_VBCD7SEG_CASE_COPOSITIVE___024ROOT_H_  // guard

#include "verilated.h"

class Vbcd7seg_case_coPositive__Syms;

class Vbcd7seg_case_coPositive___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(b,3,0);
    VL_OUT8(h,6,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbcd7seg_case_coPositive__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbcd7seg_case_coPositive___024root(Vbcd7seg_case_coPositive__Syms* symsp, const char* name);
    ~Vbcd7seg_case_coPositive___024root();
    VL_UNCOPYABLE(Vbcd7seg_case_coPositive___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
