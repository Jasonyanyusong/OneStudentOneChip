// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMultiFunctionShiftRegister_NegEdge_8Bit.h for the primary calling header

#ifndef VERILATED_VMULTIFUNCTIONSHIFTREGISTER_NEGEDGE_8BIT___024ROOT_H_
#define VERILATED_VMULTIFUNCTIONSHIFTREGISTER_NEGEDGE_8BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VMultiFunctionShiftRegister_NegEdge_8Bit__Syms;
class VMultiFunctionShiftRegister_NegEdge_8Bit_VerilatedVcd;


//----------

VL_MODULE(VMultiFunctionShiftRegister_NegEdge_8Bit___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(inp,0,0);
    VL_IN8(sel,2,0);
    VL_IN8(D,7,0);
    VL_OUT8(Q,7,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMultiFunctionShiftRegister_NegEdge_8Bit___024root);  ///< Copying not allowed
  public:
    VMultiFunctionShiftRegister_NegEdge_8Bit___024root(const char* name);
    ~VMultiFunctionShiftRegister_NegEdge_8Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VMultiFunctionShiftRegister_NegEdge_8Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
