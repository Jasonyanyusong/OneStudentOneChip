// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDCOUNTER64BIT__SYMS_H_
#define VERILATED_VADDCOUNTER64BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VAddCounter64bit.h"

// INCLUDE MODULE CLASSES
#include "VAddCounter64bit___024root.h"

// SYMS CLASS (contains all model state)
class VAddCounter64bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VAddCounter64bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VAddCounter64bit___024root     TOP;

    // CONSTRUCTORS
    VAddCounter64bit__Syms(VerilatedContext* contextp, const char* namep, VAddCounter64bit* modelp);
    ~VAddCounter64bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
