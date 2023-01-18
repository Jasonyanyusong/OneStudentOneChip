// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VARITHMETICLEFTSHIFTREGISTER_POSEDGE_32BIT__SYMS_H_
#define VERILATED_VARITHMETICLEFTSHIFTREGISTER_POSEDGE_32BIT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VArithmeticLeftShiftRegister_PosEdge_32Bit.h"

// INCLUDE MODULE CLASSES
#include "VArithmeticLeftShiftRegister_PosEdge_32Bit___024root.h"

// SYMS CLASS (contains all model state)
class VArithmeticLeftShiftRegister_PosEdge_32Bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VArithmeticLeftShiftRegister_PosEdge_32Bit* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VArithmeticLeftShiftRegister_PosEdge_32Bit___024root TOP;

    // CONSTRUCTORS
    VArithmeticLeftShiftRegister_PosEdge_32Bit__Syms(VerilatedContext* contextp, const char* namep, VArithmeticLeftShiftRegister_PosEdge_32Bit* modelp);
    ~VArithmeticLeftShiftRegister_PosEdge_32Bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
