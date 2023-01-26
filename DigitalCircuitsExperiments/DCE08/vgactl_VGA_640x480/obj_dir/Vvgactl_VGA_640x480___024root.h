// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvgactl_VGA_640x480.h for the primary calling header

#ifndef VERILATED_VVGACTL_VGA_640X480___024ROOT_H_
#define VERILATED_VVGACTL_VGA_640X480___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vvgactl_VGA_640x480__Syms;

//----------

VL_MODULE(Vvgactl_VGA_640x480___024root) {
  public:

    // PORTS
    VL_IN8(pclk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT8(valid,0,0);
    VL_OUT8(vga_r,7,0);
    VL_OUT8(vga_g,7,0);
    VL_OUT8(vga_b,7,0);
    VL_OUT16(h_addr,9,0);
    VL_OUT16(v_addr,9,0);
    VL_IN(vga_data,23,0);

    // LOCAL SIGNALS
    CData/*0:0*/ vgactl_VGA_640x480__DOT__v_valid;
    SData/*9:0*/ vgactl_VGA_640x480__DOT__x_cnt;
    SData/*9:0*/ vgactl_VGA_640x480__DOT__y_cnt;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__pclk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    SData/*9:0*/ __Vdly__vgactl_VGA_640x480__DOT__x_cnt;

    // INTERNAL VARIABLES
    Vvgactl_VGA_640x480__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vvgactl_VGA_640x480___024root);  ///< Copying not allowed
  public:
    Vvgactl_VGA_640x480___024root(const char* name);
    ~Vvgactl_VGA_640x480___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vvgactl_VGA_640x480__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
