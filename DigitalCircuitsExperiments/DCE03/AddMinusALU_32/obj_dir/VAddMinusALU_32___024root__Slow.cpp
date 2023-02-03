// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddMinusALU_32.h for the primary calling header

#include "VAddMinusALU_32___024root.h"
#include "VAddMinusALU_32__Syms.h"

//==========


void VAddMinusALU_32___024root___ctor_var_reset(VAddMinusALU_32___024root* vlSelf);

VAddMinusALU_32___024root::VAddMinusALU_32___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddMinusALU_32___024root___ctor_var_reset(this);
}

void VAddMinusALU_32___024root::__Vconfigure(VAddMinusALU_32__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddMinusALU_32___024root::~VAddMinusALU_32___024root() {
}

void VAddMinusALU_32___024root___eval_initial(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___eval_initial\n"); );
}

void VAddMinusALU_32___024root___combo__TOP__1(VAddMinusALU_32___024root* vlSelf);

void VAddMinusALU_32___024root___eval_settle(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___eval_settle\n"); );
    // Body
    VAddMinusALU_32___024root___combo__TOP__1(vlSelf);
}

void VAddMinusALU_32___024root___final(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___final\n"); );
}

void VAddMinusALU_32___024root___ctor_var_reset(VAddMinusALU_32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddMinusALU_32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddMinusALU_32___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sub_add = VL_RAND_RESET_I(1);
    vlSelf->a = VL_RAND_RESET_I(32);
    vlSelf->b = VL_RAND_RESET_I(32);
    vlSelf->carry = VL_RAND_RESET_I(1);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->AddMinusALU_32__DOT__t_no_Cin = VL_RAND_RESET_I(32);
}
