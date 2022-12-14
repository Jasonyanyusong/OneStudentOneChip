// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_TestCase_1.h for the primary calling header

#include "verilated.h"

#include "VALU32_TestCase_1__Syms.h"
#include "VALU32_TestCase_1___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_TestCase_1___024root___dump_triggers__act(VALU32_TestCase_1___024root* vlSelf);
#endif  // VL_DEBUG

void VALU32_TestCase_1___024root___eval_triggers__act(VALU32_TestCase_1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_TestCase_1___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->sub_add) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__sub_add));
    vlSelf->__Vtrigrprev__TOP__sub_add = vlSelf->sub_add;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(0U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU32_TestCase_1___024root___dump_triggers__act(vlSelf);
    }
#endif
}
