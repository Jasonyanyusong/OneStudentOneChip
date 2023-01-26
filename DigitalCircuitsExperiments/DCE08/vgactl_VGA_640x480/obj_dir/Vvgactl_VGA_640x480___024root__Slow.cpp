// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvgactl_VGA_640x480.h for the primary calling header

#include "Vvgactl_VGA_640x480___024root.h"
#include "Vvgactl_VGA_640x480__Syms.h"

//==========


void Vvgactl_VGA_640x480___024root___ctor_var_reset(Vvgactl_VGA_640x480___024root* vlSelf);

Vvgactl_VGA_640x480___024root::Vvgactl_VGA_640x480___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vvgactl_VGA_640x480___024root___ctor_var_reset(this);
}

void Vvgactl_VGA_640x480___024root::__Vconfigure(Vvgactl_VGA_640x480__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vvgactl_VGA_640x480___024root::~Vvgactl_VGA_640x480___024root() {
}

void Vvgactl_VGA_640x480___024root___settle__TOP__2(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___settle__TOP__2\n"); );
    // Variables
    CData/*0:0*/ vgactl_VGA_640x480__DOT__h_valid;
    // Body
    vlSelf->vga_r = (0xffU & (vlSelf->vga_data >> 0x10U));
    vlSelf->vga_g = (0xffU & (vlSelf->vga_data >> 8U));
    vlSelf->vga_b = (0xffU & vlSelf->vga_data);
    vlSelf->hsync = (0x60U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt));
    vlSelf->vsync = (2U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt));
    vgactl_VGA_640x480__DOT__h_valid = ((0x90U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)) 
                                        & (0x310U >= (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)));
    vlSelf->vgactl_VGA_640x480__DOT__v_valid = ((0x23U 
                                                 < (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)) 
                                                & (0x203U 
                                                   >= (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)));
    if (vgactl_VGA_640x480__DOT__h_valid) {
        vlSelf->h_addr = (0x3ffU & ((IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt) 
                                    - (IData)(0x91U)));
        vlSelf->valid = ((IData)(vlSelf->vgactl_VGA_640x480__DOT__v_valid) 
                         & 1U);
    } else {
        vlSelf->h_addr = 0U;
        vlSelf->valid = 0U;
    }
    vlSelf->v_addr = ((IData)(vlSelf->vgactl_VGA_640x480__DOT__v_valid)
                       ? (0x3ffU & ((IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt) 
                                    - (IData)(0x24U)))
                       : 0U);
}

void Vvgactl_VGA_640x480___024root___eval_initial(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__pclk = vlSelf->pclk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

void Vvgactl_VGA_640x480___024root___eval_settle(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___eval_settle\n"); );
    // Body
    Vvgactl_VGA_640x480___024root___settle__TOP__2(vlSelf);
}

void Vvgactl_VGA_640x480___024root___final(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___final\n"); );
}

void Vvgactl_VGA_640x480___024root___ctor_var_reset(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->pclk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->vga_data = VL_RAND_RESET_I(24);
    vlSelf->h_addr = VL_RAND_RESET_I(10);
    vlSelf->v_addr = VL_RAND_RESET_I(10);
    vlSelf->hsync = VL_RAND_RESET_I(1);
    vlSelf->vsync = VL_RAND_RESET_I(1);
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->vga_r = VL_RAND_RESET_I(8);
    vlSelf->vga_g = VL_RAND_RESET_I(8);
    vlSelf->vga_b = VL_RAND_RESET_I(8);
    vlSelf->vgactl_VGA_640x480__DOT__x_cnt = VL_RAND_RESET_I(10);
    vlSelf->vgactl_VGA_640x480__DOT__y_cnt = VL_RAND_RESET_I(10);
    vlSelf->vgactl_VGA_640x480__DOT__v_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__vgactl_VGA_640x480__DOT__x_cnt = VL_RAND_RESET_I(10);
}
