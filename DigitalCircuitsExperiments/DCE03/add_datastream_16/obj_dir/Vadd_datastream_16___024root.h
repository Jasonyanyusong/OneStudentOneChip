// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_datastream_16.h for the primary calling header

#ifndef VERILATED_VADD_DATASTREAM_16___024ROOT_H_
#define VERILATED_VADD_DATASTREAM_16___024ROOT_H_  // guard

#include "verilated.h"

class Vadd_datastream_16__Syms;

class Vadd_datastream_16___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VactContinue;
    VL_IN16(in_x,15,0);
    VL_IN16(in_y,15,0);
    VL_OUT16(out_s,15,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_datastream_16__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_datastream_16___024root(Vadd_datastream_16__Syms* symsp, const char* name);
    ~Vadd_datastream_16___024root();
    VL_UNCOPYABLE(Vadd_datastream_16___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
