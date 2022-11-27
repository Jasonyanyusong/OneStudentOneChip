// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMUX_2TO1_BEHAVIOR__SYMS_H_
#define VERILATED_VMUX_2TO1_BEHAVIOR__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vmux_2to1_Behavior.h"

// INCLUDE MODULE CLASSES
#include "Vmux_2to1_Behavior___024root.h"

// SYMS CLASS (contains all model state)
class Vmux_2to1_Behavior__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmux_2to1_Behavior* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmux_2to1_Behavior___024root   TOP;

    // CONSTRUCTORS
    Vmux_2to1_Behavior__Syms(VerilatedContext* contextp, const char* namep, Vmux_2to1_Behavior* modelp);
    ~Vmux_2to1_Behavior__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
