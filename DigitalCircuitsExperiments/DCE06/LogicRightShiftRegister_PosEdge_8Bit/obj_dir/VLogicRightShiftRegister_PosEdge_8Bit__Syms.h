// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_8BIT__SYMS_H_
#define VERILATED_VLOGICRIGHTSHIFTREGISTER_POSEDGE_8BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VLogicRightShiftRegister_PosEdge_8Bit.h"

// INCLUDE MODULE CLASSES
#include "VLogicRightShiftRegister_PosEdge_8Bit___024root.h"

// SYMS CLASS (contains all model state)
class VLogicRightShiftRegister_PosEdge_8Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VLogicRightShiftRegister_PosEdge_8Bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VLogicRightShiftRegister_PosEdge_8Bit___024root TOP;

    // CONSTRUCTORS
    VLogicRightShiftRegister_PosEdge_8Bit__Syms(VerilatedContext* contextp, const char* namep, VLogicRightShiftRegister_PosEdge_8Bit* modelp);
    ~VLogicRightShiftRegister_PosEdge_8Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
