// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VENCODE_8TO3_FOR__SYMS_H_
#define VERILATED_VENCODE_8TO3_FOR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vencode_8to3_for.h"

// INCLUDE MODULE CLASSES
#include "Vencode_8to3_for___024root.h"

// SYMS CLASS (contains all model state)
class Vencode_8to3_for__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vencode_8to3_for* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vencode_8to3_for___024root     TOP;

    // CONSTRUCTORS
    Vencode_8to3_for__Syms(VerilatedContext* contextp, const char* namep, Vencode_8to3_for* modelp);
    ~Vencode_8to3_for__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
