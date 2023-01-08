// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSUBCOUNTER32BIT__SYMS_H_
#define VERILATED_VSUBCOUNTER32BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VSubCounter32bit.h"

// INCLUDE MODULE CLASSES
#include "VSubCounter32bit___024root.h"

// SYMS CLASS (contains all model state)
class VSubCounter32bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSubCounter32bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VSubCounter32bit___024root     TOP;

    // CONSTRUCTORS
    VSubCounter32bit__Syms(VerilatedContext* contextp, const char* namep, VSubCounter32bit* modelp);
    ~VSubCounter32bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
