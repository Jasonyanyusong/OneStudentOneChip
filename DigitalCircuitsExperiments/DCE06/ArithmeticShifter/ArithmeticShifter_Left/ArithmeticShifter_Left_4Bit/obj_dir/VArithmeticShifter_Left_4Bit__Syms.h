// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VARITHMETICSHIFTER_LEFT_4BIT__SYMS_H_
#define VERILATED_VARITHMETICSHIFTER_LEFT_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VArithmeticShifter_Left_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VArithmeticShifter_Left_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VArithmeticShifter_Left_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VArithmeticShifter_Left_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VArithmeticShifter_Left_4Bit___024root TOP;

    // CONSTRUCTORS
    VArithmeticShifter_Left_4Bit__Syms(VerilatedContext* contextp, const char* namep, VArithmeticShifter_Left_4Bit* modelp);
    ~VArithmeticShifter_Left_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
