// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCyclicRightShiftRegister_NegEdge_32Bit.h for the primary calling header

#ifndef VERILATED_VCYCLICRIGHTSHIFTREGISTER_NEGEDGE_32BIT___024ROOT_H_
#define VERILATED_VCYCLICRIGHTSHIFTREGISTER_NEGEDGE_32BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VCyclicRightShiftRegister_NegEdge_32Bit__Syms;

//----------

VL_MODULE(VCyclicRightShiftRegister_NegEdge_32Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN(D,31,0);
    VL_OUT(Q,31,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VCyclicRightShiftRegister_NegEdge_32Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCyclicRightShiftRegister_NegEdge_32Bit___024root);  ///< Copying not allowed
  public:
    VCyclicRightShiftRegister_NegEdge_32Bit___024root(const char* name);
    ~VCyclicRightShiftRegister_NegEdge_32Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VCyclicRightShiftRegister_NegEdge_32Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
