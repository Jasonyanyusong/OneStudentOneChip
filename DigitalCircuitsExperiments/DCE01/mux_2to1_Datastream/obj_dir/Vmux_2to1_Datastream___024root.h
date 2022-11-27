// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux_2to1_Datastream.h for the primary calling header

#ifndef VERILATED_VMUX_2TO1_DATASTREAM___024ROOT_H_
#define VERILATED_VMUX_2TO1_DATASTREAM___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmux_2to1_Datastream__Syms;
class Vmux_2to1_Datastream_VerilatedVcd;


//----------

VL_MODULE(Vmux_2to1_Datastream___024root) {
  public:

    // PORTS
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_IN8(s,0,0);
    VL_OUT8(y,0,0);

    // INTERNAL VARIABLES
    Vmux_2to1_Datastream__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmux_2to1_Datastream___024root);  ///< Copying not allowed
  public:
    Vmux_2to1_Datastream___024root(const char* name);
    ~Vmux_2to1_Datastream___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vmux_2to1_Datastream__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
