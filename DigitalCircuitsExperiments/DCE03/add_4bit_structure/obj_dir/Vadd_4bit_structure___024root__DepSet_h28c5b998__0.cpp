// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_4bit_structure.h for the primary calling header

#include "verilated.h"

#include "Vadd_4bit_structure__Syms.h"
#include "Vadd_4bit_structure___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__ico(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_4bit_structure___024root___eval_triggers__ico(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd_4bit_structure___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_4bit_structure___024root___dump_triggers__act(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_4bit_structure___024root___eval_triggers__act(Vadd_4bit_structure___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_4bit_structure___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd_4bit_structure___024root___dump_triggers__act(vlSelf);
    }
#endif
}
