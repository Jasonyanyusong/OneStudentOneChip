// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBCD7SEG_CASE_COPOSITIVE__SYMS_H_
#define VERILATED_VBCD7SEG_CASE_COPOSITIVE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbcd7seg_case_coPositive.h"

// INCLUDE MODULE CLASSES
#include "Vbcd7seg_case_coPositive___024root.h"

// SYMS CLASS (contains all model state)
class Vbcd7seg_case_coPositive__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbcd7seg_case_coPositive* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbcd7seg_case_coPositive___024root TOP;

    // CONSTRUCTORS
    Vbcd7seg_case_coPositive__Syms(VerilatedContext* contextp, const char* namep, Vbcd7seg_case_coPositive* modelp);
    ~Vbcd7seg_case_coPositive__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
