// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU32_Test.h for the primary calling header

#ifndef VERILATED_VALU32_TEST___024ROOT_H_
#define VERILATED_VALU32_TEST___024ROOT_H_  // guard

#include "verilated.h"

class VALU32_Test__Syms;

class VALU32_Test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sub_add,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(overflow,0,0);
    CData/*0:0*/ ALU32_Test__DOT__testF2S1B1T2_expected_zero;
    CData/*0:0*/ ALU32_Test__DOT__testF2S1B1T2_expected_overflow;
    CData/*0:0*/ ALU32_Test__DOT__testF2S1B1T3_expected_zero;
    CData/*0:0*/ ALU32_Test__DOT__testF2S1B1T3_expected_overflow;
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ ALU32_Test__DOT__b_withCin;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VALU32_Test__Syms* const vlSymsp;

    // CONSTRUCTORS
    VALU32_Test___024root(VALU32_Test__Syms* symsp, const char* name);
    ~VALU32_Test___024root();
    VL_UNCOPYABLE(VALU32_Test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
