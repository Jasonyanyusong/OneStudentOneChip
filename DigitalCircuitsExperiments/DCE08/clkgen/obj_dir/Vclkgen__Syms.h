// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCLKGEN__SYMS_H_
#define VERILATED_VCLKGEN__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vclkgen.h"

// INCLUDE MODULE CLASSES
#include "Vclkgen___024root.h"

// SYMS CLASS (contains all model state)
class Vclkgen__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vclkgen* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vclkgen___024root              TOP;

    // CONSTRUCTORS
    Vclkgen__Syms(VerilatedContext* contextp, const char* namep, Vclkgen* modelp);
    ~Vclkgen__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
