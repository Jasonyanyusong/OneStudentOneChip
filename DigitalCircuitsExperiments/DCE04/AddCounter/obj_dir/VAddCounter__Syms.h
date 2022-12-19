// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDCOUNTER__SYMS_H_
#define VERILATED_VADDCOUNTER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VAddCounter.h"

// INCLUDE MODULE CLASSES
#include "VAddCounter___024root.h"

// SYMS CLASS (contains all model state)
class VAddCounter__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VAddCounter* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VAddCounter___024root          TOP;

    // CONSTRUCTORS
    VAddCounter__Syms(VerilatedContext* contextp, const char* namep, VAddCounter* modelp);
    ~VAddCounter__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
