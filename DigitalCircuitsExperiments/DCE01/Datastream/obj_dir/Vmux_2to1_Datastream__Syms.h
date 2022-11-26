// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMUX_2TO1_DATASTREAM__SYMS_H_
#define _VMUX_2TO1_DATASTREAM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmux_2to1_Datastream.h"

// SYMS CLASS
class Vmux_2to1_Datastream__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmux_2to1_Datastream*          TOPp;
    
    // CREATORS
    Vmux_2to1_Datastream__Syms(Vmux_2to1_Datastream* topp, const char* namep);
    ~Vmux_2to1_Datastream__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
