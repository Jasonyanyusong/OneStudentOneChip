// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTEST_OUR__SYMS_H_
#define VERILATED_VTEST_OUR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtest_our.h"

// INCLUDE MODULE CLASSES
#include "Vtest_our___024root.h"

// SYMS CLASS (contains all model state)
class Vtest_our__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtest_our* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtest_our___024root            TOP;

    // CONSTRUCTORS
    Vtest_our__Syms(VerilatedContext* contextp, const char* namep, Vtest_our* modelp);
    ~Vtest_our__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
