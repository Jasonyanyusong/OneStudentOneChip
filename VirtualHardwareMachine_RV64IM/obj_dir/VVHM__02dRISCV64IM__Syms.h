// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVHM__02DRISCV64IM__SYMS_H_
#define VERILATED_VVHM__02DRISCV64IM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VVHM__02dRISCV64IM.h"

// INCLUDE MODULE CLASSES
#include "VVHM__02dRISCV64IM___024root.h"

// SYMS CLASS (contains all model state)
class VVHM__02dRISCV64IM__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VVHM__02dRISCV64IM* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VVHM__02dRISCV64IM___024root   TOP;

    // CONSTRUCTORS
    VVHM__02dRISCV64IM__Syms(VerilatedContext* contextp, const char* namep, VVHM__02dRISCV64IM* modelp);
    ~VVHM__02dRISCV64IM__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
