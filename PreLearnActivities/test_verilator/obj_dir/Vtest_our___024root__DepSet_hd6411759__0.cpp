// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_our.h for the primary calling header

#include "verilated.h"

#include "Vtest_our__Syms.h"
#include "Vtest_our___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_our___024root___dump_triggers__act(Vtest_our___024root* vlSelf);
#endif  // VL_DEBUG

void Vtest_our___024root___eval_triggers__act(Vtest_our___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtest_our__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_our___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtest_our___024root___dump_triggers__act(vlSelf);
    }
#endif
}
