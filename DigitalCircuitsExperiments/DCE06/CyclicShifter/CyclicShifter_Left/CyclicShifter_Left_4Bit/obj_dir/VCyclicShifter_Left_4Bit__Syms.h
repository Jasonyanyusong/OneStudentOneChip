// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICSHIFTER_LEFT_4BIT__SYMS_H_
#define VERILATED_VCYCLICSHIFTER_LEFT_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicShifter_Left_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicShifter_Left_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicShifter_Left_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicShifter_Left_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicShifter_Left_4Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicShifter_Left_4Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicShifter_Left_4Bit* modelp);
    ~VCyclicShifter_Left_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
