// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMUX_4TO1_CASE__SYMS_H_
#define VERILATED_VMUX_4TO1_CASE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmux_4to1_Case.h"

// INCLUDE MODULE CLASSES
#include "Vmux_4to1_Case___024root.h"

// SYMS CLASS (contains all model state)
class Vmux_4to1_Case__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmux_4to1_Case* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmux_4to1_Case___024root       TOP;

    // CONSTRUCTORS
    Vmux_4to1_Case__Syms(VerilatedContext* contextp, const char* namep, Vmux_4to1_Case* modelp);
    ~Vmux_4to1_Case__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
