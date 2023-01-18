// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLOGICLEFTSHIFTREGISTER_NEGEDGE_4BIT__SYMS_H_
#define VERILATED_VLOGICLEFTSHIFTREGISTER_NEGEDGE_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VLogicLeftShiftRegister_NegEdge_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VLogicLeftShiftRegister_NegEdge_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VLogicLeftShiftRegister_NegEdge_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VLogicLeftShiftRegister_NegEdge_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VLogicLeftShiftRegister_NegEdge_4Bit___024root TOP;

    // CONSTRUCTORS
    VLogicLeftShiftRegister_NegEdge_4Bit__Syms(VerilatedContext* contextp, const char* namep, VLogicLeftShiftRegister_NegEdge_4Bit* modelp);
    ~VLogicLeftShiftRegister_NegEdge_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
