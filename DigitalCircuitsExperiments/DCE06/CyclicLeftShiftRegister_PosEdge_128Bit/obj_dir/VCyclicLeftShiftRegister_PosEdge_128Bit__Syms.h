// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICLEFTSHIFTREGISTER_POSEDGE_128BIT__SYMS_H_
#define VERILATED_VCYCLICLEFTSHIFTREGISTER_POSEDGE_128BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicLeftShiftRegister_PosEdge_128Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicLeftShiftRegister_PosEdge_128Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicLeftShiftRegister_PosEdge_128Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicLeftShiftRegister_PosEdge_128Bit* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicLeftShiftRegister_PosEdge_128Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicLeftShiftRegister_PosEdge_128Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicLeftShiftRegister_PosEdge_128Bit* modelp);
    ~VCyclicLeftShiftRegister_PosEdge_128Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
