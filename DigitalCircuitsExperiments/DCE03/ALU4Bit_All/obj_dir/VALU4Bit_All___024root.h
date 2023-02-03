// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU4Bit_All.h for the primary calling header

#ifndef VERILATED_VALU4BIT_ALL___024ROOT_H_
#define VERILATED_VALU4BIT_ALL___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VALU4Bit_All__Syms;
class VALU4Bit_All_VerilatedVcd;


//----------

VL_MODULE(VALU4Bit_All___024root) {
  public:

    // PORTS
    VL_IN8(sel,2,0);
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_OUT8(result,3,0);
    VL_OUT8(overflow,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(zero,0,0);

    // LOCAL SIGNALS
    CData/*0:0*/ ALU4Bit_All__DOT__Cin;
    CData/*3:0*/ ALU4Bit_All__DOT__t_no_Cin;
    CData/*4:0*/ ALU4Bit_All__DOT__carry_and_result;
    IData/*31:0*/ ALU4Bit_All__DOT__i;

    // LOCAL VARIABLES
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VALU4Bit_All__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VALU4Bit_All___024root);  ///< Copying not allowed
  public:
    VALU4Bit_All___024root(const char* name);
    ~VALU4Bit_All___024root();

    // INTERNAL METHODS
    void __Vconfigure(VALU4Bit_All__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
