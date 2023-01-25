// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFSM_4ContinueInput.h for the primary calling header

#include "VFSM_4ContinueInput___024root.h"
#include "VFSM_4ContinueInput__Syms.h"

//==========


void VFSM_4ContinueInput___024root___ctor_var_reset(VFSM_4ContinueInput___024root* vlSelf);

VFSM_4ContinueInput___024root::VFSM_4ContinueInput___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VFSM_4ContinueInput___024root___ctor_var_reset(this);
}

void VFSM_4ContinueInput___024root::__Vconfigure(VFSM_4ContinueInput__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VFSM_4ContinueInput___024root::~VFSM_4ContinueInput___024root() {
}

void VFSM_4ContinueInput___024root___settle__TOP__1(VFSM_4ContinueInput___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM_4ContinueInput___024root___settle__TOP__1\n"); );
    // Variables
    VlWide<3>/*95:0*/ __Vtemp1;
    // Body
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[0U] = 0x11U;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[1U] = 0xeU;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[2U] = 0xcU;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[3U] = 0xaU;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[4U] = 9U;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[5U] = 6U;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[6U] = 4U;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[7U] = 2U;
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[8U] = 0U;
    __Vtemp1[0U] = (0x80U | (((IData)((((QData)((IData)(
                                                        (0x102030U 
                                                         | ((((IData)(vlSelf->in)
                                                               ? 5U
                                                               : 1U) 
                                                             << 0x18U) 
                                                            | ((((IData)(vlSelf->in)
                                                                  ? 5U
                                                                  : 2U) 
                                                                << 0x10U) 
                                                               | ((((IData)(vlSelf->in)
                                                                     ? 5U
                                                                     : 3U) 
                                                                   << 8U) 
                                                                  | ((IData)(vlSelf->in)
                                                                      ? 5U
                                                                      : 4U))))))) 
                                        << 0x20U) | (QData)((IData)(
                                                                    (0x40506070U 
                                                                     | ((((IData)(vlSelf->in)
                                                                           ? 5U
                                                                           : 4U) 
                                                                         << 0x18U) 
                                                                        | ((((IData)(vlSelf->in)
                                                                              ? 6U
                                                                              : 1U) 
                                                                            << 0x10U) 
                                                                           | ((((IData)(vlSelf->in)
                                                                                 ? 7U
                                                                                 : 1U) 
                                                                               << 8U) 
                                                                              | ((IData)(vlSelf->in)
                                                                                 ? 8U
                                                                                 : 1U))))))))) 
                              << 8U) | ((IData)(vlSelf->in)
                                         ? 8U : 1U)));
    __Vtemp1[1U] = (((IData)((((QData)((IData)((0x102030U 
                                                | ((((IData)(vlSelf->in)
                                                      ? 5U
                                                      : 1U) 
                                                    << 0x18U) 
                                                   | ((((IData)(vlSelf->in)
                                                         ? 5U
                                                         : 2U) 
                                                       << 0x10U) 
                                                      | ((((IData)(vlSelf->in)
                                                            ? 5U
                                                            : 3U) 
                                                          << 8U) 
                                                         | ((IData)(vlSelf->in)
                                                             ? 5U
                                                             : 4U))))))) 
                               << 0x20U) | (QData)((IData)(
                                                           (0x40506070U 
                                                            | ((((IData)(vlSelf->in)
                                                                  ? 5U
                                                                  : 4U) 
                                                                << 0x18U) 
                                                               | ((((IData)(vlSelf->in)
                                                                     ? 6U
                                                                     : 1U) 
                                                                   << 0x10U) 
                                                                  | ((((IData)(vlSelf->in)
                                                                        ? 7U
                                                                        : 1U) 
                                                                      << 8U) 
                                                                     | ((IData)(vlSelf->in)
                                                                         ? 8U
                                                                         : 1U))))))))) 
                     >> 0x18U) | ((IData)(((((QData)((IData)(
                                                             (0x102030U 
                                                              | ((((IData)(vlSelf->in)
                                                                    ? 5U
                                                                    : 1U) 
                                                                  << 0x18U) 
                                                                 | ((((IData)(vlSelf->in)
                                                                       ? 5U
                                                                       : 2U) 
                                                                     << 0x10U) 
                                                                    | ((((IData)(vlSelf->in)
                                                                          ? 5U
                                                                          : 3U) 
                                                                        << 8U) 
                                                                       | ((IData)(vlSelf->in)
                                                                           ? 5U
                                                                           : 4U))))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (0x40506070U 
                                                               | ((((IData)(vlSelf->in)
                                                                     ? 5U
                                                                     : 4U) 
                                                                   << 0x18U) 
                                                                  | ((((IData)(vlSelf->in)
                                                                        ? 6U
                                                                        : 1U) 
                                                                      << 0x10U) 
                                                                     | ((((IData)(vlSelf->in)
                                                                           ? 7U
                                                                           : 1U) 
                                                                         << 8U) 
                                                                        | ((IData)(vlSelf->in)
                                                                            ? 8U
                                                                            : 1U)))))))) 
                                           >> 0x20U)) 
                                  << 8U));
    vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[0U] 
        = __Vtemp1[0U];
    vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[1U] 
        = __Vtemp1[1U];
    vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[2U] 
        = ((IData)(((((QData)((IData)((0x102030U | 
                                       ((((IData)(vlSelf->in)
                                           ? 5U : 1U) 
                                         << 0x18U) 
                                        | ((((IData)(vlSelf->in)
                                              ? 5U : 2U) 
                                            << 0x10U) 
                                           | ((((IData)(vlSelf->in)
                                                 ? 5U
                                                 : 3U) 
                                               << 8U) 
                                              | ((IData)(vlSelf->in)
                                                  ? 5U
                                                  : 4U))))))) 
                      << 0x20U) | (QData)((IData)((0x40506070U 
                                                   | ((((IData)(vlSelf->in)
                                                         ? 5U
                                                         : 4U) 
                                                       << 0x18U) 
                                                      | ((((IData)(vlSelf->in)
                                                            ? 6U
                                                            : 1U) 
                                                          << 0x10U) 
                                                         | ((((IData)(vlSelf->in)
                                                               ? 7U
                                                               : 1U) 
                                                             << 8U) 
                                                            | ((IData)(vlSelf->in)
                                                                ? 8U
                                                                : 1U)))))))) 
                    >> 0x20U)) >> 0x18U);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[0U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[0U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [0U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[1U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [1U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[1U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [1U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[2U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [2U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[2U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [2U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[3U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [3U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[3U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [3U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[4U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [4U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[4U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [4U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[5U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [5U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[5U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [5U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[6U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [6U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[6U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [6U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[7U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [7U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[7U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [7U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[8U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [8U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[8U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [8U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[0U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[0U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [0U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[1U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [1U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[1U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [1U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[2U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [2U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[2U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [2U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[3U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [3U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[3U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [3U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[4U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [4U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[4U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [4U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[5U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [5U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[5U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [5U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[6U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [6U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[6U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [6U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[7U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [7U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[7U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [7U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[8U] 
        = (1U & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
           [8U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[8U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list
                   [8U] >> 1U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[0U] 
        = (0xffU & vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[0U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[1U] 
        = (0xffU & (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[0U] 
                    >> 8U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[2U] 
        = (0xffU & (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[0U] 
                    >> 0x10U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[3U] 
        = (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[0U] 
           >> 0x18U);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[4U] 
        = (0xffU & vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[1U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[5U] 
        = (0xffU & (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[1U] 
                    >> 8U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[6U] 
        = (0xffU & (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[1U] 
                    >> 0x10U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[7U] 
        = (vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[1U] 
           >> 0x18U);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[8U] 
        = (0xffU & vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut[2U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
            == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
            [0U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
           == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [1U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [2U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [3U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [4U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [5U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [6U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [7U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [7U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [7U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
               == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
               [8U]) & vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list
              [8U]));
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list
              [8U]));
    vlSelf->out = ((IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit) 
                   & (IData)(vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[0U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[0U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [0U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[1U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [1U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[1U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [1U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[2U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [2U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[2U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [2U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[3U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [3U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[3U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [3U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[4U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [4U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[4U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [4U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[5U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [5U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[5U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [5U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[6U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [6U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[6U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [6U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[7U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [7U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[7U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [7U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[8U] 
        = (0xfU & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
           [8U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[8U] 
        = (0xfU & (vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list
                   [8U] >> 4U));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                       == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
           == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [7U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [7U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [7U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
                          == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
                          [8U]))) & vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list
              [8U]));
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->FSM_4ContinueInput__DOT__state_dout) 
              == vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list
              [8U]));
    vlSelf->FSM_4ContinueInput__DOT__state_din = ((IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit)
                                                   ? (IData)(vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out)
                                                   : 0U);
}

void VFSM_4ContinueInput___024root___eval_initial(VFSM_4ContinueInput___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM_4ContinueInput___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VFSM_4ContinueInput___024root___eval_settle(VFSM_4ContinueInput___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM_4ContinueInput___024root___eval_settle\n"); );
    // Body
    VFSM_4ContinueInput___024root___settle__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VFSM_4ContinueInput___024root___final(VFSM_4ContinueInput___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM_4ContinueInput___024root___final\n"); );
}

void VFSM_4ContinueInput___024root___ctor_var_reset(VFSM_4ContinueInput___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM_4ContinueInput___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->in = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->out = VL_RAND_RESET_I(1);
    vlSelf->FSM_4ContinueInput__DOT__state_din = VL_RAND_RESET_I(4);
    vlSelf->FSM_4ContinueInput__DOT__state_dout = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(72, vlSelf->FSM_4ContinueInput__DOT____Vcellinp__stateMux__lut);
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->FSM_4ContinueInput__DOT__outMux__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(4);
    vlSelf->FSM_4ContinueInput__DOT__stateMux__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
