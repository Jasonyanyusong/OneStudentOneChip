// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_datastream_4.h for the primary calling header

#include "verilated.h"

#include "Vadd_datastream_4__Syms.h"
#include "Vadd_datastream_4___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_datastream_4___024root___dump_triggers__stl(Vadd_datastream_4___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd_datastream_4___024root___eval_triggers__stl(Vadd_datastream_4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd_datastream_4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_datastream_4___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd_datastream_4___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
