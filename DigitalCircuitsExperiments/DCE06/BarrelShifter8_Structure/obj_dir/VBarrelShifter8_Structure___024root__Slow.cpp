// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBarrelShifter8_Structure.h for the primary calling header

#include "VBarrelShifter8_Structure___024root.h"
#include "VBarrelShifter8_Structure__Syms.h"

//==========


void VBarrelShifter8_Structure___024root___ctor_var_reset(VBarrelShifter8_Structure___024root* vlSelf);

VBarrelShifter8_Structure___024root::VBarrelShifter8_Structure___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VBarrelShifter8_Structure___024root___ctor_var_reset(this);
}

void VBarrelShifter8_Structure___024root::__Vconfigure(VBarrelShifter8_Structure__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VBarrelShifter8_Structure___024root::~VBarrelShifter8_Structure___024root() {
}

void VBarrelShifter8_Structure___024root___eval_initial(VBarrelShifter8_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter8_Structure___024root___eval_initial\n"); );
}

void VBarrelShifter8_Structure___024root___combo__TOP__1(VBarrelShifter8_Structure___024root* vlSelf);

void VBarrelShifter8_Structure___024root___eval_settle(VBarrelShifter8_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter8_Structure___024root___eval_settle\n"); );
    // Body
    VBarrelShifter8_Structure___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VBarrelShifter8_Structure___024root___final(VBarrelShifter8_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter8_Structure___024root___final\n"); );
}

void VBarrelShifter8_Structure___024root___ctor_var_reset(VBarrelShifter8_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter8_Structure___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->din = VL_RAND_RESET_I(8);
    vlSelf->shamt = VL_RAND_RESET_I(3);
    vlSelf->lr = VL_RAND_RESET_I(1);
    vlSelf->al = VL_RAND_RESET_I(1);
    vlSelf->dout = VL_RAND_RESET_I(8);
    vlSelf->BarrelShifter8_Structure__DOT__mc_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m7a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m6a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m5a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m4a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m3a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m2a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m1a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m0a_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m7b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m6b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m5b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m4b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m3b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m2b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m1b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT__m0b_out = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m7c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m6c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m5c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m4c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m3c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m2c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m1c__dataout = VL_RAND_RESET_I(1);
    vlSelf->BarrelShifter8_Structure__DOT____Vcellout__m0c__dataout = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
