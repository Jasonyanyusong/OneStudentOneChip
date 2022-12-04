// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_our_systemC.h for the primary calling header

#include "verilated.h"

#include "Vtest_our_systemC__Syms.h"
#include "Vtest_our_systemC___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_our_systemC___024root___dump_triggers__ico(Vtest_our_systemC___024root* vlSelf);
#endif  // VL_DEBUG

void Vtest_our_systemC___024root___eval_triggers__ico(Vtest_our_systemC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our_systemC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our_systemC___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtest_our_systemC___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_our_systemC___024root___dump_triggers__act(Vtest_our_systemC___024root* vlSelf);
#endif  // VL_DEBUG

void Vtest_our_systemC___024root___eval_triggers__act(Vtest_our_systemC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our_systemC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our_systemC___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->__Vcellinp__test_our_systemC__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP____Vcellinp__test_our_systemC__clk)));
    vlSelf->__Vtrigrprev__TOP____Vcellinp__test_our_systemC__clk 
        = vlSelf->__Vcellinp__test_our_systemC__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtest_our_systemC___024root___dump_triggers__act(vlSelf);
    }
#endif
}
