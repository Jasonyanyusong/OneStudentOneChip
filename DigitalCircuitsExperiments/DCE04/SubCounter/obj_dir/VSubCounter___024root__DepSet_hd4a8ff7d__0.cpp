// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSubCounter.h for the primary calling header

#include "verilated.h"

#include "VSubCounter__Syms.h"
#include "VSubCounter___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSubCounter___024root___dump_triggers__act(VSubCounter___024root* vlSelf);
#endif  // VL_DEBUG

void VSubCounter___024root___eval_triggers__act(VSubCounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSubCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSubCounter___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSubCounter___024root___dump_triggers__act(vlSelf);
    }
#endif
}
