// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICRIGHTSHIFTREGISTER_NEGEDGE_16BIT__SYMS_H_
#define VERILATED_VCYCLICRIGHTSHIFTREGISTER_NEGEDGE_16BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicRightShiftRegister_NegEdge_16Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicRightShiftRegister_NegEdge_16Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicRightShiftRegister_NegEdge_16Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicRightShiftRegister_NegEdge_16Bit* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicRightShiftRegister_NegEdge_16Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicRightShiftRegister_NegEdge_16Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicRightShiftRegister_NegEdge_16Bit* modelp);
    ~VCyclicRightShiftRegister_NegEdge_16Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
