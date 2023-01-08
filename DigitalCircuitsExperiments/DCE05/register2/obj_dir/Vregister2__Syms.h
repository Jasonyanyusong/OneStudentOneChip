// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREGISTER2__SYMS_H_
#define VERILATED_VREGISTER2__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vregister2.h"

// INCLUDE MODULE CLASSES
#include "Vregister2___024root.h"

// SYMS CLASS (contains all model state)
class Vregister2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vregister2* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vregister2___024root           TOP;

    // CONSTRUCTORS
    Vregister2__Syms(VerilatedContext* contextp, const char* namep, Vregister2* modelp);
    ~Vregister2__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
