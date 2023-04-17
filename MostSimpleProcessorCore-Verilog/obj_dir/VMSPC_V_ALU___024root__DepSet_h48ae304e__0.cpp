// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMSPC_V_ALU.h for the primary calling header

#include "verilated.h"

#include "VMSPC_V_ALU__Syms.h"
#include "VMSPC_V_ALU___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VMSPC_V_ALU___024root___dump_triggers__act(VMSPC_V_ALU___024root* vlSelf);
#endif  // VL_DEBUG

void VMSPC_V_ALU___024root___eval_triggers__act(VMSPC_V_ALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMSPC_V_ALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMSPC_V_ALU___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->sel) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__sel));
    vlSelf->__Vtrigrprev__TOP__sel = vlSelf->sel;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(0U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VMSPC_V_ALU___024root___dump_triggers__act(vlSelf);
    }
#endif
}
