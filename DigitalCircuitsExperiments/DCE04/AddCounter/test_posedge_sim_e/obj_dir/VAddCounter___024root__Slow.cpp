// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAddCounter.h for the primary calling header

#include "VAddCounter___024root.h"
#include "VAddCounter__Syms.h"

//==========


void VAddCounter___024root___ctor_var_reset(VAddCounter___024root* vlSelf);

VAddCounter___024root::VAddCounter___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VAddCounter___024root___ctor_var_reset(this);
}

void VAddCounter___024root::__Vconfigure(VAddCounter__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VAddCounter___024root::~VAddCounter___024root() {
}

void VAddCounter___024root___eval_initial(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VAddCounter___024root___eval_settle(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___eval_settle\n"); );
}

void VAddCounter___024root___final(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___final\n"); );
}

void VAddCounter___024root___ctor_var_reset(VAddCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAddCounter___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out_q = VL_RAND_RESET_I(3);
}
