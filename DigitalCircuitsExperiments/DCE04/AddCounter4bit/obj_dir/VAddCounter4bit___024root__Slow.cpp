// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter4bit.h for the primary calling header

#include "VAddCounter4bit___024root.h"
#include "VAddCounter4bit__Syms.h"

//==========


void VAddCounter4bit___024root___ctor_var_reset(VAddCounter4bit___024root* vlSelf);

VAddCounter4bit___024root::VAddCounter4bit___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddCounter4bit___024root___ctor_var_reset(this);
}

void VAddCounter4bit___024root::__Vconfigure(VAddCounter4bit__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddCounter4bit___024root::~VAddCounter4bit___024root() {
}

void VAddCounter4bit___024root___eval_initial(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VAddCounter4bit___024root___eval_settle(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___eval_settle\n"); );
}

void VAddCounter4bit___024root___final(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___final\n"); );
}

void VAddCounter4bit___024root___ctor_var_reset(VAddCounter4bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter4bit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(4);
}
