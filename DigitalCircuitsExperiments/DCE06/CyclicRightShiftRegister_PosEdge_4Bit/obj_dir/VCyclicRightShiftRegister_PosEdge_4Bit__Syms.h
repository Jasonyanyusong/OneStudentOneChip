// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCYCLICRIGHTSHIFTREGISTER_POSEDGE_4BIT__SYMS_H_
#define VERILATED_VCYCLICRIGHTSHIFTREGISTER_POSEDGE_4BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VCyclicRightShiftRegister_PosEdge_4Bit.h"

// INCLUDE MODULE CLASSES
#include "VCyclicRightShiftRegister_PosEdge_4Bit___024root.h"

// SYMS CLASS (contains all model state)
class VCyclicRightShiftRegister_PosEdge_4Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCyclicRightShiftRegister_PosEdge_4Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCyclicRightShiftRegister_PosEdge_4Bit___024root TOP;

    // CONSTRUCTORS
    VCyclicRightShiftRegister_PosEdge_4Bit__Syms(VerilatedContext* contextp, const char* namep, VCyclicRightShiftRegister_PosEdge_4Bit* modelp);
    ~VCyclicRightShiftRegister_PosEdge_4Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
