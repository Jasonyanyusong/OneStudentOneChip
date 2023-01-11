// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBARRELSHIFTER8_STRUCTURE__SYMS_H_
#define VERILATED_VBARRELSHIFTER8_STRUCTURE__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VBarrelShifter8_Structure.h"

// INCLUDE MODULE CLASSES
#include "VBarrelShifter8_Structure___024root.h"

// SYMS CLASS (contains all model state)
class VBarrelShifter8_Structure__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VBarrelShifter8_Structure* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VBarrelShifter8_Structure___024root TOP;

    // CONSTRUCTORS
    VBarrelShifter8_Structure__Syms(VerilatedContext* contextp, const char* namep, VBarrelShifter8_Structure* modelp);
    ~VBarrelShifter8_Structure__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
