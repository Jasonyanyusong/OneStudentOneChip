// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTEST_OUR_SYSTEMC__SYMS_H_
#define VERILATED_VTEST_OUR_SYSTEMC__SYMS_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtest_our_systemC.h"

// INCLUDE MODULE CLASSES
#include "Vtest_our_systemC___024root.h"

// SYMS CLASS (contains all model state)
class Vtest_our_systemC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtest_our_systemC* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtest_our_systemC___024root    TOP;

    // CONSTRUCTORS
    Vtest_our_systemC__Syms(VerilatedContext* contextp, const char* namep, Vtest_our_systemC* modelp);
    ~Vtest_our_systemC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
