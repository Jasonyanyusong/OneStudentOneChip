// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbarrelshifter8.h for the primary calling header

#ifndef VERILATED_VBARRELSHIFTER8___024ROOT_H_
#define VERILATED_VBARRELSHIFTER8___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vbarrelshifter8__Syms;
class Vbarrelshifter8_VerilatedVcd;


//----------

VL_MODULE(Vbarrelshifter8___024root) {
  public:

    // PORTS
    VL_IN8(din,7,0);
    VL_IN8(shamt,2,0);
    VL_IN8(lr,0,0);
    VL_IN8(al,0,0);
    VL_OUT8(dout,7,0);

    // LOCAL SIGNALS
    CData/*0:0*/ barrelshifter8__DOT__mc_out;
    CData/*0:0*/ barrelshifter8__DOT__m7a_out;
    CData/*0:0*/ barrelshifter8__DOT__m6a_out;
    CData/*0:0*/ barrelshifter8__DOT__m5a_out;
    CData/*0:0*/ barrelshifter8__DOT__m4a_out;
    CData/*0:0*/ barrelshifter8__DOT__m3a_out;
    CData/*0:0*/ barrelshifter8__DOT__m2a_out;
    CData/*0:0*/ barrelshifter8__DOT__m1a_out;
    CData/*0:0*/ barrelshifter8__DOT__m0a_out;
    CData/*0:0*/ barrelshifter8__DOT__m7b_out;
    CData/*0:0*/ barrelshifter8__DOT__m6b_out;
    CData/*0:0*/ barrelshifter8__DOT__m5b_out;
    CData/*0:0*/ barrelshifter8__DOT__m4b_out;
    CData/*0:0*/ barrelshifter8__DOT__m3b_out;
    CData/*0:0*/ barrelshifter8__DOT__m2b_out;
    CData/*0:0*/ barrelshifter8__DOT__m1b_out;
    CData/*0:0*/ barrelshifter8__DOT__m0b_out;

    // LOCAL VARIABLES
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m7c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m6c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m5c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m4c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m3c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m2c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m1c__dataout;
    CData/*0:0*/ barrelshifter8__DOT____Vcellout__m0c__dataout;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vbarrelshifter8__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbarrelshifter8___024root);  ///< Copying not allowed
  public:
    Vbarrelshifter8___024root(const char* name);
    ~Vbarrelshifter8___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vbarrelshifter8__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
