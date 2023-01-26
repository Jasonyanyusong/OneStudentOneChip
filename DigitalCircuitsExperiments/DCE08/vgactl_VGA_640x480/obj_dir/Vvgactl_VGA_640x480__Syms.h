// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVGACTL_VGA_640X480__SYMS_H_
#define VERILATED_VVGACTL_VGA_640X480__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vvgactl_VGA_640x480.h"

// INCLUDE MODULE CLASSES
#include "Vvgactl_VGA_640x480___024root.h"

// SYMS CLASS (contains all model state)
class Vvgactl_VGA_640x480__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vvgactl_VGA_640x480* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vvgactl_VGA_640x480___024root  TOP;

    // CONSTRUCTORS
    Vvgactl_VGA_640x480__Syms(VerilatedContext* contextp, const char* namep, Vvgactl_VGA_640x480* modelp);
    ~Vvgactl_VGA_640x480__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
