// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecode_4to16_for.h for the primary calling header

#ifndef VERILATED_VDECODE_4TO16_FOR___024ROOT_H_
#define VERILATED_VDECODE_4TO16_FOR___024ROOT_H_  // guard

#include "verilated.h"

class Vdecode_4to16_for__Syms;

class Vdecode_4to16_for___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(x,3,0);
    CData/*0:0*/ __VactContinue;
    VL_OUT16(y,15,0);
    IData/*31:0*/ decode_4to16_for__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdecode_4to16_for__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdecode_4to16_for___024root(Vdecode_4to16_for__Syms* symsp, const char* name);
    ~Vdecode_4to16_for___024root();
    VL_UNCOPYABLE(Vdecode_4to16_for___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
