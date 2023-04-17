// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMSPC_V_ALU.h for the primary calling header

#ifndef VERILATED_VMSPC_V_ALU___024ROOT_H_
#define VERILATED_VMSPC_V_ALU___024ROOT_H_  // guard

#include "verilated.h"

class VMSPC_V_ALU__Syms;

class VMSPC_V_ALU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sel,3,0);
    VL_OUT8(booloutp,0,0);
    CData/*3:0*/ __Vtrigrprev__TOP__sel;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(inpa,63,0);
    VL_IN64(inpb,63,0);
    VL_OUT64(numoutp,63,0);
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VMSPC_V_ALU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMSPC_V_ALU___024root(VMSPC_V_ALU__Syms* symsp, const char* name);
    ~VMSPC_V_ALU___024root();
    VL_UNCOPYABLE(VMSPC_V_ALU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
