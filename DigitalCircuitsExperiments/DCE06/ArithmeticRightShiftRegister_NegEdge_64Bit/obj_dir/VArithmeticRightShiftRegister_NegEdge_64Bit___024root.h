// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VArithmeticRightShiftRegister_NegEdge_64Bit.h for the primary calling header

#ifndef VERILATED_VARITHMETICRIGHTSHIFTREGISTER_NEGEDGE_64BIT___024ROOT_H_
#define VERILATED_VARITHMETICRIGHTSHIFTREGISTER_NEGEDGE_64BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VArithmeticRightShiftRegister_NegEdge_64Bit__Syms;

//----------

VL_MODULE(VArithmeticRightShiftRegister_NegEdge_64Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN64(D,63,0);
    VL_OUT64(Q,63,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VArithmeticRightShiftRegister_NegEdge_64Bit___024root);  ///< Copying not allowed
  public:
    VArithmeticRightShiftRegister_NegEdge_64Bit___024root(const char* name);
    ~VArithmeticRightShiftRegister_NegEdge_64Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VArithmeticRightShiftRegister_NegEdge_64Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
