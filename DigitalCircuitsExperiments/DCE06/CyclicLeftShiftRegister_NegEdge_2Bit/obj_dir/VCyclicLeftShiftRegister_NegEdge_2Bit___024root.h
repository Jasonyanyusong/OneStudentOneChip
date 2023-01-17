// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCyclicLeftShiftRegister_NegEdge_2Bit.h for the primary calling header

#ifndef VERILATED_VCYCLICLEFTSHIFTREGISTER_NEGEDGE_2BIT___024ROOT_H_
#define VERILATED_VCYCLICLEFTSHIFTREGISTER_NEGEDGE_2BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VCyclicLeftShiftRegister_NegEdge_2Bit__Syms;
class VCyclicLeftShiftRegister_NegEdge_2Bit_VerilatedVcd;


//----------

VL_MODULE(VCyclicLeftShiftRegister_NegEdge_2Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(D,1,0);
    VL_OUT8(Q,1,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VCyclicLeftShiftRegister_NegEdge_2Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCyclicLeftShiftRegister_NegEdge_2Bit___024root);  ///< Copying not allowed
  public:
    VCyclicLeftShiftRegister_NegEdge_2Bit___024root(const char* name);
    ~VCyclicLeftShiftRegister_NegEdge_2Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VCyclicLeftShiftRegister_NegEdge_2Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
