// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VArithmeticLeftShiftRegister_NegEdge_32Bit.h for the primary calling header

#ifndef VERILATED_VARITHMETICLEFTSHIFTREGISTER_NEGEDGE_32BIT___024ROOT_H_
#define VERILATED_VARITHMETICLEFTSHIFTREGISTER_NEGEDGE_32BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VArithmeticLeftShiftRegister_NegEdge_32Bit__Syms;

//----------

VL_MODULE(VArithmeticLeftShiftRegister_NegEdge_32Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN(D,31,0);
    VL_OUT(Q,31,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VArithmeticLeftShiftRegister_NegEdge_32Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VArithmeticLeftShiftRegister_NegEdge_32Bit___024root);  ///< Copying not allowed
  public:
    VArithmeticLeftShiftRegister_NegEdge_32Bit___024root(const char* name);
    ~VArithmeticLeftShiftRegister_NegEdge_32Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VArithmeticLeftShiftRegister_NegEdge_32Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
