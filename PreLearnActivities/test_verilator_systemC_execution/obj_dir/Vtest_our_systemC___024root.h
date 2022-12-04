// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtest_our_systemC.h for the primary calling header

#ifndef VERILATED_VTEST_OUR_SYSTEMC___024ROOT_H_
#define VERILATED_VTEST_OUR_SYSTEMC___024ROOT_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

class Vtest_our_systemC__Syms;

class Vtest_our_systemC___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vcellinp__test_our_systemC__clk;
    CData/*0:0*/ __Vtrigrprev__TOP____Vcellinp__test_our_systemC__clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    sc_in<bool> clk;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtest_our_systemC__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtest_our_systemC___024root(Vtest_our_systemC__Syms* symsp, const char* name);
    ~Vtest_our_systemC___024root();
    VL_UNCOPYABLE(Vtest_our_systemC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
