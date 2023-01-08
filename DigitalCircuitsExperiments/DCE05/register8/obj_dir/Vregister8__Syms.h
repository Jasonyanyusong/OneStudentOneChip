// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREGISTER8__SYMS_H_
#define VERILATED_VREGISTER8__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vregister8.h"

// INCLUDE MODULE CLASSES
#include "Vregister8___024root.h"

// SYMS CLASS (contains all model state)
class Vregister8__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vregister8* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vregister8___024root           TOP;

    // CONSTRUCTORS
    Vregister8__Syms(VerilatedContext* contextp, const char* namep, Vregister8* modelp);
    ~Vregister8__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
