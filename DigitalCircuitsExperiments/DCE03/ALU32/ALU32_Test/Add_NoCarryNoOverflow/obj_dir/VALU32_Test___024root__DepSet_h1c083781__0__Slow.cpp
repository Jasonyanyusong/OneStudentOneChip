// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32_Test.h for the primary calling header

#include "verilated.h"

#include "VALU32_Test__Syms.h"
#include "VALU32_Test___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU32_Test___024root___dump_triggers__stl(VALU32_Test___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU32_Test___024root___eval_triggers__stl(VALU32_Test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU32_Test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32_Test___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU32_Test___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
