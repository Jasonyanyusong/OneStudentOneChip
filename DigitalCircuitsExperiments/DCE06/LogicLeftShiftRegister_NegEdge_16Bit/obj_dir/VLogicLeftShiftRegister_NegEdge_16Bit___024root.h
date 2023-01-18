// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VLogicLeftShiftRegister_NegEdge_16Bit.h for the primary calling header

#ifndef VERILATED_VLOGICLEFTSHIFTREGISTER_NEGEDGE_16BIT___024ROOT_H_
#define VERILATED_VLOGICLEFTSHIFTREGISTER_NEGEDGE_16BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VLogicLeftShiftRegister_NegEdge_16Bit__Syms;

//----------

VL_MODULE(VLogicLeftShiftRegister_NegEdge_16Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN16(D,15,0);
    VL_OUT16(Q,15,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VLogicLeftShiftRegister_NegEdge_16Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VLogicLeftShiftRegister_NegEdge_16Bit___024root);  ///< Copying not allowed
  public:
    VLogicLeftShiftRegister_NegEdge_16Bit___024root(const char* name);
    ~VLogicLeftShiftRegister_NegEdge_16Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VLogicLeftShiftRegister_NegEdge_16Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
