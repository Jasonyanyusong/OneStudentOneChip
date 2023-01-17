// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICRIGHTSHIFTREGISTER_POSEDGE_64BIT__SYMS_H_
#define VERILATED_VCYCLICRIGHTSHIFTREGISTER_POSEDGE_64BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicRightShiftRegister_PosEdge_64Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicRightShiftRegister_PosEdge_64Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicRightShiftRegister_PosEdge_64Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicRightShiftRegister_PosEdge_64Bit* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicRightShiftRegister_PosEdge_64Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicRightShiftRegister_PosEdge_64Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicRightShiftRegister_PosEdge_64Bit* modelp);
    ~VCyclicRightShiftRegister_PosEdge_64Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
