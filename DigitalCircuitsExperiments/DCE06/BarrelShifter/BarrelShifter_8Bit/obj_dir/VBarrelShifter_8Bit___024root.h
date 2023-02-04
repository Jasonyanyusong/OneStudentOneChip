// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VBarrelShifter_8Bit.h for the primary calling header

#ifndef VERILATED_VBARRELSHIFTER_8BIT___024ROOT_H_
#define VERILATED_VBARRELSHIFTER_8BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VBarrelShifter_8Bit__Syms;
class VBarrelShifter_8Bit_VerilatedVcd;


//----------

VL_MODULE(VBarrelShifter_8Bit___024root) {
  public:

    // PORTS
    VL_IN8(din,7,0);
    VL_IN8(shamt,2,0);
    VL_IN8(lr,0,0);
    VL_IN8(al,0,0);
    VL_OUT8(dout,7,0);

    // LOCAL SIGNALS
    CData/*0:0*/ BarrelShifter_8Bit__DOT__mc_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m7a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m6a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m5a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m4a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m3a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m2a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m1a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m0a_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m7b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m6b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m5b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m4b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m3b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m2b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m1b_out;
    CData/*0:0*/ BarrelShifter_8Bit__DOT__m0b_out;

    // LOCAL VARIABLES
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout;
    CData/*0:0*/ BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VBarrelShifter_8Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VBarrelShifter_8Bit___024root);  ///< Copying not allowed
  public:
    VBarrelShifter_8Bit___024root(const char* name);
    ~VBarrelShifter_8Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VBarrelShifter_8Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
