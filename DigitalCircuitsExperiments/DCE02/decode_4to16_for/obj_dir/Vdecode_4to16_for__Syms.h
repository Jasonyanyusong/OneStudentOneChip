// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDECODE_4TO16_FOR__SYMS_H_
#define VERILATED_VDECODE_4TO16_FOR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdecode_4to16_for.h"

// INCLUDE MODULE CLASSES
#include "Vdecode_4to16_for___024root.h"

// SYMS CLASS (contains all model state)
class Vdecode_4to16_for__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdecode_4to16_for* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdecode_4to16_for___024root    TOP;

    // CONSTRUCTORS
    Vdecode_4to16_for__Syms(VerilatedContext* contextp, const char* namep, Vdecode_4to16_for* modelp);
    ~Vdecode_4to16_for__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
