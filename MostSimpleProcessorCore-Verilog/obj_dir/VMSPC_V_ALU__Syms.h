// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMSPC_V_ALU__SYMS_H_
#define VERILATED_VMSPC_V_ALU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VMSPC_V_ALU.h"

// INCLUDE MODULE CLASSES
#include "VMSPC_V_ALU___024root.h"

// SYMS CLASS (contains all model state)
class VMSPC_V_ALU__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VMSPC_V_ALU* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VMSPC_V_ALU___024root          TOP;

    // CONSTRUCTORS
    VMSPC_V_ALU__Syms(VerilatedContext* contextp, const char* namep, VMSPC_V_ALU* modelp);
    ~VMSPC_V_ALU__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
