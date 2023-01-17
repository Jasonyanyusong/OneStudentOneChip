// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICLEFTSHIFTREGISTER_POSEDGE_8BIT__SYMS_H_
#define VERILATED_VCYCLICLEFTSHIFTREGISTER_POSEDGE_8BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicLeftShiftRegister_PosEdge_8Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicLeftShiftRegister_PosEdge_8Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicLeftShiftRegister_PosEdge_8Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicLeftShiftRegister_PosEdge_8Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicLeftShiftRegister_PosEdge_8Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicLeftShiftRegister_PosEdge_8Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicLeftShiftRegister_PosEdge_8Bit* modelp);
    ~VCyclicLeftShiftRegister_PosEdge_8Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
