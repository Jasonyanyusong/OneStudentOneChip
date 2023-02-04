// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBARRELSHIFTER_8BIT__SYMS_H_
#define VERILATED_VBARRELSHIFTER_8BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VBarrelShifter_8Bit.h"

// INCLUDE MODULE CLASSES
#include "VBarrelShifter_8Bit___024root.h"

// SYMS CLASS (contains all model state)
class VBarrelShifter_8Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VBarrelShifter_8Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VBarrelShifter_8Bit___024root  TOP;

    // CONSTRUCTORS
    VBarrelShifter_8Bit__Syms(VerilatedContext* contextp, const char* namep, VBarrelShifter_8Bit* modelp);
    ~VBarrelShifter_8Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
