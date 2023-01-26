// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclkgen.h for the primary calling header

#include "Vclkgen___024root.h"
#include "Vclkgen__Syms.h"

//==========


void Vclkgen___024root___ctor_var_reset(Vclkgen___024root* vlSelf);

Vclkgen___024root::Vclkgen___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vclkgen___024root___ctor_var_reset(this);
}

void Vclkgen___024root::__Vconfigure(Vclkgen__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vclkgen___024root::~Vclkgen___024root() {
}

void Vclkgen___024root___eval_initial(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clkin = vlSelf->clkin;
}

void Vclkgen___024root___eval_settle(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___eval_settle\n"); );
}

void Vclkgen___024root___final(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___final\n"); );
}

void Vclkgen___024root___ctor_var_reset(Vclkgen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkgen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkgen___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clkin = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clken = VL_RAND_RESET_I(1);
    vlSelf->clkout = VL_RAND_RESET_I(1);
    vlSelf->clkgen__DOT__clkcount = VL_RAND_RESET_I(32);
}
