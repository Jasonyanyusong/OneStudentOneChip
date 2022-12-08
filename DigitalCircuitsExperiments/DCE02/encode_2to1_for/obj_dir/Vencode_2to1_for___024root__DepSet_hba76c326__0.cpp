// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode_2to1_for.h for the primary calling header

#include "verilated.h"

#include "Vencode_2to1_for__Syms.h"
#include "Vencode_2to1_for___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode_2to1_for___024root___dump_triggers__ico(Vencode_2to1_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode_2to1_for___024root___eval_triggers__ico(Vencode_2to1_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_2to1_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_2to1_for___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode_2to1_for___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode_2to1_for___024root___dump_triggers__act(Vencode_2to1_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode_2to1_for___024root___eval_triggers__act(Vencode_2to1_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode_2to1_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode_2to1_for___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode_2to1_for___024root___dump_triggers__act(vlSelf);
    }
#endif
}
