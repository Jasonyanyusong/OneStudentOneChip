// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux_2to1_Structure.h for the primary calling header

#include "Vmux_2to1_Structure___024root.h"
#include "Vmux_2to1_Structure__Syms.h"

//==========


void Vmux_2to1_Structure___024root___ctor_var_reset(Vmux_2to1_Structure___024root* vlSelf);

Vmux_2to1_Structure___024root::Vmux_2to1_Structure___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vmux_2to1_Structure___024root___ctor_var_reset(this);
}

void Vmux_2to1_Structure___024root::__Vconfigure(Vmux_2to1_Structure__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vmux_2to1_Structure___024root::~Vmux_2to1_Structure___024root() {
}

void Vmux_2to1_Structure___024root___eval_initial(Vmux_2to1_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Structure___024root___eval_initial\n"); );
}

void Vmux_2to1_Structure___024root___combo__TOP__1(Vmux_2to1_Structure___024root* vlSelf);

void Vmux_2to1_Structure___024root___eval_settle(Vmux_2to1_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Structure___024root___eval_settle\n"); );
    // Body
    Vmux_2to1_Structure___024root___combo__TOP__1(vlSelf);
}

void Vmux_2to1_Structure___024root___final(Vmux_2to1_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Structure___024root___final\n"); );
}

void Vmux_2to1_Structure___024root___ctor_var_reset(Vmux_2to1_Structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux_2to1_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Structure___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->s = VL_RAND_RESET_I(1);
    vlSelf->y = VL_RAND_RESET_I(1);
}
