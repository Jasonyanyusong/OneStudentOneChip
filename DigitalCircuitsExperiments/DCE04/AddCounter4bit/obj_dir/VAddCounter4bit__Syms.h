// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDCOUNTER4BIT__SYMS_H_
#define VERILATED_VADDCOUNTER4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VAddCounter4bit.h"

// INCLUDE MODULE CLASSES
#include "VAddCounter4bit___024root.h"

// SYMS CLASS (contains all model state)
class VAddCounter4bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VAddCounter4bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VAddCounter4bit___024root      TOP;

    // CONSTRUCTORS
    VAddCounter4bit__Syms(VerilatedContext* contextp, const char* namep, VAddCounter4bit* modelp);
    ~VAddCounter4bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
