// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VLogicRightShiftRegister_PosEdge_8Bit.h for the primary calling header

#ifndef VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_8BIT___024ROOT_H_
#define VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_8BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VLogicRightShiftRegister_PosEdge_8Bit__Syms;
class VLogicRightShiftRegister_PosEdge_8Bit_VerilatedVcd;


//----------

VL_MODULE(VLogicRightShiftRegister_PosEdge_8Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(D,7,0);
    VL_OUT8(Q,7,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VLogicRightShiftRegister_PosEdge_8Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VLogicRightShiftRegister_PosEdge_8Bit___024root);  ///< Copying not allowed
  public:
    VLogicRightShiftRegister_PosEdge_8Bit___024root(const char* name);
    ~VLogicRightShiftRegister_PosEdge_8Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VLogicRightShiftRegister_PosEdge_8Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
