// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU8Functions_16bit.h for the primary calling header

#include "verilated.h"

#include "VALU8Functions_16bit__Syms.h"
#include "VALU8Functions_16bit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU8Functions_16bit___024root___dump_triggers__ico(VALU8Functions_16bit___024root* vlSelf);
#endif  // VL_DEBUG

void VALU8Functions_16bit___024root___eval_triggers__ico(VALU8Functions_16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_16bit___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU8Functions_16bit___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU8Functions_16bit___024root___dump_triggers__act(VALU8Functions_16bit___024root* vlSelf);
#endif  // VL_DEBUG

void VALU8Functions_16bit___024root___eval_triggers__act(VALU8Functions_16bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_16bit___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU8Functions_16bit___024root___dump_triggers__act(vlSelf);
    }
#endif
}
