// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbcd7seg_case_coPositive.h for the primary calling header

#include "verilated.h"

#include "Vbcd7seg_case_coPositive__Syms.h"
#include "Vbcd7seg_case_coPositive___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root___dump_triggers__stl(Vbcd7seg_case_coPositive___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbcd7seg_case_coPositive___024root___eval_triggers__stl(Vbcd7seg_case_coPositive___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbcd7seg_case_coPositive__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcd7seg_case_coPositive___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbcd7seg_case_coPositive___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
