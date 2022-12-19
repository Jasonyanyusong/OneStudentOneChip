// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU8Functions_16bit.h for the primary calling header

#ifndef VERILATED_VALU8FUNCTIONS_16BIT___024ROOT_H_
#define VERILATED_VALU8FUNCTIONS_16BIT___024ROOT_H_  // guard

#include "verilated.h"

class VALU8Functions_16bit__Syms;

class VALU8Functions_16bit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(input_mode_select,2,0);
    CData/*0:0*/ __VactContinue;
    VL_IN16(input_a,15,0);
    VL_IN16(input_b,15,0);
    VL_OUT16(output_result,15,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VALU8Functions_16bit__Syms* const vlSymsp;

    // CONSTRUCTORS
    VALU8Functions_16bit___024root(VALU8Functions_16bit__Syms* symsp, const char* name);
    ~VALU8Functions_16bit___024root();
    VL_UNCOPYABLE(VALU8Functions_16bit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
