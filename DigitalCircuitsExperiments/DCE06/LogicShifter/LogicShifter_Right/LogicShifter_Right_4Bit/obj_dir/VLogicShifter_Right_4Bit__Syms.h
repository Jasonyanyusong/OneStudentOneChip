// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLOGICSHIFTER_RIGHT_4BIT__SYMS_H_
#define VERILATED_VLOGICSHIFTER_RIGHT_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VLogicShifter_Right_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VLogicShifter_Right_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VLogicShifter_Right_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VLogicShifter_Right_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VLogicShifter_Right_4Bit___024root TOP;

    // CONSTRUCTORS
    VLogicShifter_Right_4Bit__Syms(VerilatedContext* contextp, const char* namep, VLogicShifter_Right_4Bit* modelp);
    ~VLogicShifter_Right_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
