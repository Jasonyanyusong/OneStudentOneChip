// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_datastream_1.h for the primary calling header

#ifndef VERILATED_VADD_DATASTREAM_1___024ROOT_H_
#define VERILATED_VADD_DATASTREAM_1___024ROOT_H_  // guard

#include "verilated.h"

class Vadd_datastream_1__Syms;

class Vadd_datastream_1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(in_x,0,0);
    VL_IN8(in_y,0,0);
    VL_OUT8(out_s,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_datastream_1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_datastream_1___024root(Vadd_datastream_1__Syms* symsp, const char* name);
    ~Vadd_datastream_1___024root();
    VL_UNCOPYABLE(Vadd_datastream_1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
