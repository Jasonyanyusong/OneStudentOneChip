// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_4bit_structure.h for the primary calling header

#ifndef VERILATED_VADD_4BIT_STRUCTURE___024ROOT_H_
#define VERILATED_VADD_4BIT_STRUCTURE___024ROOT_H_  // guard

#include "verilated.h"

class Vadd_4bit_structure__Syms;

class Vadd_4bit_structure___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a_0,0,0);
    VL_IN8(b_0,0,0);
    VL_IN8(c_in,0,0);
    VL_IN8(a_1,0,0);
    VL_IN8(b_1,0,0);
    VL_IN8(a_2,0,0);
    VL_IN8(b_2,0,0);
    VL_IN8(a_3,0,0);
    VL_IN8(b_3,0,0);
    CData/*0:0*/ add_4bit_structure__DOT__add0_1;
    CData/*0:0*/ add_4bit_structure__DOT__add1_2;
    CData/*0:0*/ add_4bit_structure__DOT__add2_3;
    CData/*0:0*/ add_4bit_structure__DOT__add0__DOT__a_iEXORb_i_A;
    CData/*0:0*/ add_4bit_structure__DOT__add0__DOT__a_iANDb_i_B;
    CData/*0:0*/ add_4bit_structure__DOT__add0__DOT__c_iANDA_D;
    CData/*0:0*/ add_4bit_structure__DOT__add1__DOT__a_iEXORb_i_A;
    CData/*0:0*/ add_4bit_structure__DOT__add1__DOT__a_iANDb_i_B;
    CData/*0:0*/ add_4bit_structure__DOT__add1__DOT__c_iANDA_D;
    CData/*0:0*/ add_4bit_structure__DOT__add2__DOT__a_iEXORb_i_A;
    CData/*0:0*/ add_4bit_structure__DOT__add2__DOT__a_iANDb_i_B;
    CData/*0:0*/ add_4bit_structure__DOT__add2__DOT__c_iANDA_D;
    CData/*0:0*/ add_4bit_structure__DOT__add3__DOT__a_iEXORb_i_A;
    CData/*0:0*/ add_4bit_structure__DOT__add3__DOT__a_iANDb_i_B;
    CData/*0:0*/ add_4bit_structure__DOT__add3__DOT__c_iANDA_D;
    VL_OUT8(s_0,0,0);
    VL_IN8(c_1,0,0);
    VL_OUT8(s_1,0,0);
    VL_IN8(c_2,0,0);
    VL_OUT8(s_2,0,0);
    VL_IN8(c_3,0,0);
    VL_OUT8(s_3,0,0);
    VL_OUT8(c_out,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_4bit_structure__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_4bit_structure___024root(Vadd_4bit_structure__Syms* symsp, const char* name);
    ~Vadd_4bit_structure___024root();
    VL_UNCOPYABLE(Vadd_4bit_structure___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
