// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode_5to32_for.h for the primary calling header

#include "verilated.h"

#include "Vdecode_5to32_for__Syms.h"
#include "Vdecode_5to32_for___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecode_5to32_for___024root___dump_triggers__stl(Vdecode_5to32_for___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdecode_5to32_for___024root___eval_triggers__stl(Vdecode_5to32_for___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecode_5to32_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_5to32_for___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdecode_5to32_for___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
