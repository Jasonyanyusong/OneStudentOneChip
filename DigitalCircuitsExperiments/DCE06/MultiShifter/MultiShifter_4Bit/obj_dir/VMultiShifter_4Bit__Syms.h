// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMULTISHIFTER_4BIT__SYMS_H_
#define VERILATED_VMULTISHIFTER_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VMultiShifter_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VMultiShifter_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VMultiShifter_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VMultiShifter_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VMultiShifter_4Bit___024root   TOP;

    // CONSTRUCTORS
    VMultiShifter_4Bit__Syms(VerilatedContext* contextp, const char* namep, VMultiShifter_4Bit* modelp);
    ~VMultiShifter_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
