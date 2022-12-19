// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSubCounter.h for the primary calling header

#ifndef VERILATED_VSUBCOUNTER___024ROOT_H_
#define VERILATED_VSUBCOUNTER___024ROOT_H_  // guard

#include "verilated.h"

class VSubCounter__Syms;

class VSubCounter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(out_q,2,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSubCounter__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSubCounter___024root(VSubCounter__Syms* symsp, const char* name);
    ~VSubCounter___024root();
    VL_UNCOPYABLE(VSubCounter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
