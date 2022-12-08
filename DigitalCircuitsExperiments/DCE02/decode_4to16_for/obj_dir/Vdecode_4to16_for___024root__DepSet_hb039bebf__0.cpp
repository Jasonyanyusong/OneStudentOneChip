// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode_4to16_for.h for the primary calling header

#include "verilated.h"

#include "Vdecode_4to16_for__Syms.h"
#include "Vdecode_4to16_for___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_4to16_for___024root___dump_triggers__ico(Vdecode_4to16_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vdecode_4to16_for___024root___eval_triggers__ico(Vdecode_4to16_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_4to16_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_4to16_for___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdecode_4to16_for___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_4to16_for___024root___dump_triggers__act(Vdecode_4to16_for___024root* vlSelf);
#endif  // VL_DEBUG

void Vdecode_4to16_for___024root___eval_triggers__act(Vdecode_4to16_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_4to16_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_4to16_for___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdecode_4to16_for___024root___dump_triggers__act(vlSelf);
    }
#endif
}
