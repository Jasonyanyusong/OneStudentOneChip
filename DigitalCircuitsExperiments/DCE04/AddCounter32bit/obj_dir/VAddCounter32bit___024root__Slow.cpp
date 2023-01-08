// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter32bit.h for the primary calling header

#include "VAddCounter32bit___024root.h"
#include "VAddCounter32bit__Syms.h"

//==========


void VAddCounter32bit___024root___ctor_var_reset(VAddCounter32bit___024root* vlSelf);

VAddCounter32bit___024root::VAddCounter32bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddCounter32bit___024root___ctor_var_reset(this);
}

void VAddCounter32bit___024root::__Vconfigure(VAddCounter32bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddCounter32bit___024root::~VAddCounter32bit___024root() {
}

void VAddCounter32bit___024root___eval_initial(VAddCounter32bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter32bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter32bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VAddCounter32bit___024root___eval_settle(VAddCounter32bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter32bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter32bit___024root___eval_settle\n"); );
}

void VAddCounter32bit___024root___final(VAddCounter32bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter32bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter32bit___024root___final\n"); );
}

void VAddCounter32bit___024root___ctor_var_reset(VAddCounter32bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter32bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter32bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(32);
}
