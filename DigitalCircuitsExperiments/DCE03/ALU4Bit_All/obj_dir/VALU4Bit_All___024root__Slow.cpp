// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU4Bit_All.h for the primary calling header

#include "VALU4Bit_All___024root.h"
#include "VALU4Bit_All__Syms.h"

//==========


void VALU4Bit_All___024root___ctor_var_reset(VALU4Bit_All___024root* vlSelf);

VALU4Bit_All___024root::VALU4Bit_All___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VALU4Bit_All___024root___ctor_var_reset(this);
}

void VALU4Bit_All___024root::__Vconfigure(VALU4Bit_All__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VALU4Bit_All___024root::~VALU4Bit_All___024root() {
}

void VALU4Bit_All___024root___eval_initial(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___eval_initial\n"); );
}

void VALU4Bit_All___024root___combo__TOP__1(VALU4Bit_All___024root* vlSelf);

void VALU4Bit_All___024root___eval_settle(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___eval_settle\n"); );
    // Body
    VALU4Bit_All___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VALU4Bit_All___024root___final(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___final\n"); );
}

void VALU4Bit_All___024root___ctor_var_reset(VALU4Bit_All___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4Bit_All___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sel = VL_RAND_RESET_I(3);
    vlSelf->a = VL_RAND_RESET_I(4);
    vlSelf->b = VL_RAND_RESET_I(4);
    vlSelf->result = VL_RAND_RESET_I(4);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->carry = VL_RAND_RESET_I(1);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->ALU4Bit_All__DOT__Cin = VL_RAND_RESET_I(1);
    vlSelf->ALU4Bit_All__DOT__t_no_Cin = VL_RAND_RESET_I(4);
    vlSelf->ALU4Bit_All__DOT__carry_and_result = VL_RAND_RESET_I(5);
    vlSelf->ALU4Bit_All__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
