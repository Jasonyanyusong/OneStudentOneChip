// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMUX_2TO1_DATASTREAM_H_
#define _VMUX_2TO1_DATASTREAM_H_  // guard

#include "verilated.h"

//==========

class Vmux_2to1_Datastream__Syms;

//----------

VL_MODULE(Vmux_2to1_Datastream) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_IN8(s,0,0);
    VL_OUT8(y,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmux_2to1_Datastream__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmux_2to1_Datastream);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmux_2to1_Datastream(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmux_2to1_Datastream();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmux_2to1_Datastream__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmux_2to1_Datastream__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmux_2to1_Datastream__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmux_2to1_Datastream__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vmux_2to1_Datastream__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmux_2to1_Datastream__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmux_2to1_Datastream__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmux_2to1_Datastream__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
