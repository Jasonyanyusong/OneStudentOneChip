// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTEST_OUR_SYSTEMC_H_
#define VERILATED_VTEST_OUR_SYSTEMC_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

class Vtest_our_systemC__Syms;
class Vtest_our_systemC___024root;

// This class is the main interface to the Verilated model
class Vtest_our_systemC VL_NOT_FINAL : public ::sc_core::sc_module, public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtest_our_systemC__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool> &clk;

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtest_our_systemC___024root* const rootp;

    // CONSTRUCTORS
    SC_CTOR(Vtest_our_systemC);
    virtual ~Vtest_our_systemC();
  private:
    VL_UNCOPYABLE(Vtest_our_systemC);  ///< Copying not allowed

  public:
    // API METHODS
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
