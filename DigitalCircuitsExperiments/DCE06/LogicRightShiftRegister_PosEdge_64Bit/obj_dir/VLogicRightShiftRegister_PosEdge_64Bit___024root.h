// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VLogicRightShiftRegister_PosEdge_64Bit.h for the primary calling header

#ifndef VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_64BIT___024ROOT_H_
#define VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_64BIT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VLogicRightShiftRegister_PosEdge_64Bit__Syms;

//----------

VL_MODULE(VLogicRightShiftRegister_PosEdge_64Bit___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN64(D,63,0);
    VL_OUT64(Q,63,0);

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;

    // INTERNAL VARIABLES
    VLogicRightShiftRegister_PosEdge_64Bit__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VLogicRightShiftRegister_PosEdge_64Bit___024root);  ///< Copying not allowed
  public:
    VLogicRightShiftRegister_PosEdge_64Bit___024root(const char* name);
    ~VLogicRightShiftRegister_PosEdge_64Bit___024root();

    // INTERNAL METHODS
    void __Vconfigure(VLogicRightShiftRegister_PosEdge_64Bit__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
