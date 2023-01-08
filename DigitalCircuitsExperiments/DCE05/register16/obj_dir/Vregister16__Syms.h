// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREGISTER16__SYMS_H_
#define VERILATED_VREGISTER16__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vregister16.h"

// INCLUDE MODULE CLASSES
#include "Vregister16___024root.h"

// SYMS CLASS (contains all model state)
class Vregister16__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vregister16* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vregister16___024root          TOP;

    // CONSTRUCTORS
    Vregister16__Syms(VerilatedContext* contextp, const char* namep, Vregister16* modelp);
    ~Vregister16__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
