// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux_2to1_Datastream.h for the primary calling header

#include "Vmux_2to1_Datastream.h"
#include "Vmux_2to1_Datastream__Syms.h"

//==========

VL_CTOR_IMP(Vmux_2to1_Datastream) {
    Vmux_2to1_Datastream__Syms* __restrict vlSymsp = __VlSymsp = new Vmux_2to1_Datastream__Syms(this, name());
    Vmux_2to1_Datastream* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmux_2to1_Datastream::__Vconfigure(Vmux_2to1_Datastream__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmux_2to1_Datastream::~Vmux_2to1_Datastream() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vmux_2to1_Datastream::_eval_initial(Vmux_2to1_Datastream__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Datastream::_eval_initial\n"); );
    Vmux_2to1_Datastream* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmux_2to1_Datastream::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Datastream::final\n"); );
    // Variables
    Vmux_2to1_Datastream__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmux_2to1_Datastream* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmux_2to1_Datastream::_eval_settle(Vmux_2to1_Datastream__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Datastream::_eval_settle\n"); );
    Vmux_2to1_Datastream* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmux_2to1_Datastream::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux_2to1_Datastream::_ctor_var_reset\n"); );
    // Body
    a = VL_RAND_RESET_I(1);
    b = VL_RAND_RESET_I(1);
    s = VL_RAND_RESET_I(1);
    y = VL_RAND_RESET_I(1);
}
