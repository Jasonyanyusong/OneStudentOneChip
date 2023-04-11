// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VVHM__02dRISCV64IM.h for the primary calling header

#ifndef VERILATED_VVHM__02DRISCV64IM___024ROOT_H_
#define VERILATED_VVHM__02DRISCV64IM___024ROOT_H_  // guard

#include "verilated.h"

class VVHM__02dRISCV64IM__Syms;

class VVHM__02dRISCV64IM___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(vhm_status,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(riscv_32bits_instruction,31,0);
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ RV64IM_VHM__DOT__vhm_pc;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VVHM__02dRISCV64IM__Syms* const vlSymsp;

    // CONSTRUCTORS
    VVHM__02dRISCV64IM___024root(VVHM__02dRISCV64IM__Syms* symsp, const char* name);
    ~VVHM__02dRISCV64IM___024root();
    VL_UNCOPYABLE(VVHM__02dRISCV64IM___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
