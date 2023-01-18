// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLOGICRIGHTSHIFTREGISTER_NEGEDGE_128BIT__SYMS_H_
#define VERILATED_VLOGICRIGHTSHIFTREGISTER_NEGEDGE_128BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VLogicRightShiftRegister_NegEdge_128Bit.h"

// INCLUDE MODULE CLASSES
#include "VLogicRightShiftRegister_NegEdge_128Bit___024root.h"

// SYMS CLASS (contains all model state)
class VLogicRightShiftRegister_NegEdge_128Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VLogicRightShiftRegister_NegEdge_128Bit* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VLogicRightShiftRegister_NegEdge_128Bit___024root TOP;

    // CONSTRUCTORS
    VLogicRightShiftRegister_NegEdge_128Bit__Syms(VerilatedContext* contextp, const char* namep, VLogicRightShiftRegister_NegEdge_128Bit* modelp);
    ~VLogicRightShiftRegister_NegEdge_128Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
