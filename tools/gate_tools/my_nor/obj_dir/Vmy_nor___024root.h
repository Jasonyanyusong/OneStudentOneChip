// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_nor.h for the primary calling header

#ifndef VERILATED_VMY_NOR___024ROOT_H_
#define VERILATED_VMY_NOR___024ROOT_H_  // guard

#include "verilated.h"

class Vmy_nor__Syms;

class Vmy_nor___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
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
    Vmy_nor__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmy_nor___024root(Vmy_nor__Syms* symsp, const char* name);
    ~Vmy_nor___024root();
    VL_UNCOPYABLE(Vmy_nor___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
