// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_keyboard.h for the primary calling header

#include "Vps2_keyboard___024root.h"
#include "Vps2_keyboard__Syms.h"

//==========


void Vps2_keyboard___024root___ctor_var_reset(Vps2_keyboard___024root* vlSelf);

Vps2_keyboard___024root::Vps2_keyboard___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vps2_keyboard___024root___ctor_var_reset(this);
}

void Vps2_keyboard___024root::__Vconfigure(Vps2_keyboard__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vps2_keyboard___024root::~Vps2_keyboard___024root() {
}

void Vps2_keyboard___024root___settle__TOP__2(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->data = vlSelf->ps2_keyboard__DOT__fifo[vlSelf->ps2_keyboard__DOT__r_ptr];
}

void Vps2_keyboard___024root___eval_initial(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vps2_keyboard___024root___eval_settle(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_settle\n"); );
    // Body
    Vps2_keyboard___024root___settle__TOP__2(vlSelf);
}

void Vps2_keyboard___024root___final(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___final\n"); );
}

void Vps2_keyboard___024root___ctor_var_reset(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->clrn = VL_RAND_RESET_I(1);
    vlSelf->ps2_clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_data = VL_RAND_RESET_I(1);
    vlSelf->nextdata_n = VL_RAND_RESET_I(1);
    vlSelf->data = VL_RAND_RESET_I(8);
    vlSelf->ready = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->ps2_keyboard__DOT__buffer = VL_RAND_RESET_I(10);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->ps2_keyboard__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->ps2_keyboard__DOT__w_ptr = VL_RAND_RESET_I(3);
    vlSelf->ps2_keyboard__DOT__r_ptr = VL_RAND_RESET_I(3);
    vlSelf->ps2_keyboard__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->ps2_keyboard__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    vlSelf->ps2_keyboard__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
}
