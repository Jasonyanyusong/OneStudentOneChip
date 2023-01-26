// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvgactl_VGA_640x480.h for the primary calling header

#include "Vvgactl_VGA_640x480___024root.h"
#include "Vvgactl_VGA_640x480__Syms.h"

//==========

VL_INLINE_OPT void Vvgactl_VGA_640x480___024root___combo__TOP__1(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->vga_r = (0xffU & (vlSelf->vga_data >> 0x10U));
    vlSelf->vga_g = (0xffU & (vlSelf->vga_data >> 8U));
    vlSelf->vga_b = (0xffU & vlSelf->vga_data);
}

VL_INLINE_OPT void Vvgactl_VGA_640x480___024root___sequent__TOP__3(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___sequent__TOP__3\n"); );
    // Body
    vlSelf->__Vdly__vgactl_VGA_640x480__DOT__x_cnt 
        = vlSelf->vgactl_VGA_640x480__DOT__x_cnt;
    vlSelf->__Vdly__vgactl_VGA_640x480__DOT__x_cnt 
        = ((IData)(vlSelf->reset) ? 1U : ((0x320U == (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt))
                                           ? 1U : (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)))));
}

VL_INLINE_OPT void Vvgactl_VGA_640x480___024root___sequent__TOP__4(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___sequent__TOP__4\n"); );
    // Variables
    SData/*9:0*/ __Vdly__vgactl_VGA_640x480__DOT__y_cnt;
    // Body
    __Vdly__vgactl_VGA_640x480__DOT__y_cnt = vlSelf->vgactl_VGA_640x480__DOT__y_cnt;
    if (vlSelf->reset) {
        __Vdly__vgactl_VGA_640x480__DOT__y_cnt = 1U;
    } else if (((0x20dU == (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)) 
                & (0x320U == (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)))) {
        __Vdly__vgactl_VGA_640x480__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt))) {
        __Vdly__vgactl_VGA_640x480__DOT__y_cnt = (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)));
    }
    vlSelf->vgactl_VGA_640x480__DOT__y_cnt = __Vdly__vgactl_VGA_640x480__DOT__y_cnt;
    vlSelf->vsync = (2U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt));
    vlSelf->vgactl_VGA_640x480__DOT__v_valid = ((0x23U 
                                                 < (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)) 
                                                & (0x203U 
                                                   >= (IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt)));
    vlSelf->v_addr = ((IData)(vlSelf->vgactl_VGA_640x480__DOT__v_valid)
                       ? (0x3ffU & ((IData)(vlSelf->vgactl_VGA_640x480__DOT__y_cnt) 
                                    - (IData)(0x24U)))
                       : 0U);
}

VL_INLINE_OPT void Vvgactl_VGA_640x480___024root___sequent__TOP__5(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___sequent__TOP__5\n"); );
    // Variables
    CData/*0:0*/ vgactl_VGA_640x480__DOT__h_valid;
    // Body
    vlSelf->vgactl_VGA_640x480__DOT__x_cnt = vlSelf->__Vdly__vgactl_VGA_640x480__DOT__x_cnt;
    vlSelf->hsync = (0x60U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt));
    vgactl_VGA_640x480__DOT__h_valid = ((0x90U < (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)) 
                                        & (0x310U >= (IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt)));
    vlSelf->valid = ((IData)(vgactl_VGA_640x480__DOT__h_valid) 
                     & (IData)(vlSelf->vgactl_VGA_640x480__DOT__v_valid));
    vlSelf->h_addr = ((IData)(vgactl_VGA_640x480__DOT__h_valid)
                       ? (0x3ffU & ((IData)(vlSelf->vgactl_VGA_640x480__DOT__x_cnt) 
                                    - (IData)(0x91U)))
                       : 0U);
}

void Vvgactl_VGA_640x480___024root___eval(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___eval\n"); );
    // Body
    Vvgactl_VGA_640x480___024root___combo__TOP__1(vlSelf);
    if ((((IData)(vlSelf->pclk) & (~ (IData)(vlSelf->__Vclklast__TOP__pclk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        Vvgactl_VGA_640x480___024root___sequent__TOP__3(vlSelf);
    }
    if (((IData)(vlSelf->pclk) & (~ (IData)(vlSelf->__Vclklast__TOP__pclk)))) {
        Vvgactl_VGA_640x480___024root___sequent__TOP__4(vlSelf);
    }
    if ((((IData)(vlSelf->pclk) & (~ (IData)(vlSelf->__Vclklast__TOP__pclk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        Vvgactl_VGA_640x480___024root___sequent__TOP__5(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__pclk = vlSelf->pclk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

QData Vvgactl_VGA_640x480___024root___change_request_1(Vvgactl_VGA_640x480___024root* vlSelf);

VL_INLINE_OPT QData Vvgactl_VGA_640x480___024root___change_request(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___change_request\n"); );
    // Body
    return (Vvgactl_VGA_640x480___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vvgactl_VGA_640x480___024root___change_request_1(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vvgactl_VGA_640x480___024root___eval_debug_assertions(Vvgactl_VGA_640x480___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvgactl_VGA_640x480__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvgactl_VGA_640x480___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->pclk & 0xfeU))) {
        Verilated::overWidthError("pclk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->vga_data & 0xff000000U))) {
        Verilated::overWidthError("vga_data");}
}
#endif  // VL_DEBUG
