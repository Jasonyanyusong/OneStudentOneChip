// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU8Functions_8bit.h for the primary calling header

#include "verilated.h"

#include "VALU8Functions_8bit__Syms.h"
#include "VALU8Functions_8bit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU8Functions_8bit___024root___dump_triggers__stl(VALU8Functions_8bit___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU8Functions_8bit___024root___eval_triggers__stl(VALU8Functions_8bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU8Functions_8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU8Functions_8bit___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU8Functions_8bit___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
