// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBarrelShifter_8Bit.h for the primary calling header

#include "VBarrelShifter_8Bit___024root.h"
#include "VBarrelShifter_8Bit__Syms.h"

//==========

VL_INLINE_OPT void VBarrelShifter_8Bit___024root___combo__TOP__1(VBarrelShifter_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter_8Bit___024root___combo__TOP__1\n"); );
    // Body
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m1a_out 
                        = (1U & (IData)(vlSelf->din));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m1a_out 
                    = (1U & ((IData)(vlSelf->din) >> 1U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m1a_out 
                = (1U & ((IData)(vlSelf->din) >> 2U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m1a_out = 
            (1U & ((IData)(vlSelf->din) >> 1U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m0a_out = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m0a_out 
                    = (1U & (IData)(vlSelf->din));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m0a_out 
                = (1U & ((IData)(vlSelf->din) >> 1U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m0a_out = 
            (1U & (IData)(vlSelf->din));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m6a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 5U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m6a_out 
                    = (1U & ((IData)(vlSelf->din) >> 6U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m6a_out 
                = (1U & ((IData)(vlSelf->din) >> 7U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m6a_out = 
            (1U & ((IData)(vlSelf->din) >> 6U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m5a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 4U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m5a_out 
                    = (1U & ((IData)(vlSelf->din) >> 5U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m5a_out 
                = (1U & ((IData)(vlSelf->din) >> 6U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m5a_out = 
            (1U & ((IData)(vlSelf->din) >> 5U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m4a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 3U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m4a_out 
                    = (1U & ((IData)(vlSelf->din) >> 4U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m4a_out 
                = (1U & ((IData)(vlSelf->din) >> 5U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m4a_out = 
            (1U & ((IData)(vlSelf->din) >> 4U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m3a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 2U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m3a_out 
                    = (1U & ((IData)(vlSelf->din) >> 3U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m3a_out 
                = (1U & ((IData)(vlSelf->din) >> 4U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m3a_out = 
            (1U & ((IData)(vlSelf->din) >> 3U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m2a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 1U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m2a_out 
                    = (1U & ((IData)(vlSelf->din) >> 2U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m2a_out 
                = (1U & ((IData)(vlSelf->din) >> 3U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m2a_out = 
            (1U & ((IData)(vlSelf->din) >> 2U));
    }
    if (vlSelf->al) {
        if (vlSelf->al) {
            vlSelf->BarrelShifter_8Bit__DOT__mc_out 
                = (1U & ((IData)(vlSelf->din) >> 7U));
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__mc_out = 0U;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m3b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m1a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m3b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m3a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m3b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m5a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m3b_out = vlSelf->BarrelShifter_8Bit__DOT__m3a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m1b_out = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m1b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m1a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m1b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m3a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m1b_out = vlSelf->BarrelShifter_8Bit__DOT__m1a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m2b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m0a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m2b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m2a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m2b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m4a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m2b_out = vlSelf->BarrelShifter_8Bit__DOT__m2a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m0b_out = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m0b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m0a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m0b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m2a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m0b_out = vlSelf->BarrelShifter_8Bit__DOT__m0a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m4b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m2a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m4b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m4a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m4b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m6a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m4b_out = vlSelf->BarrelShifter_8Bit__DOT__m4a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m6b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m4a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m6b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m6a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m6b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m6b_out = vlSelf->BarrelShifter_8Bit__DOT__m6a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((1U & (IData)(vlSelf->shamt))) {
                if ((1U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m7a_out 
                        = (1U & ((IData)(vlSelf->din) 
                                 >> 6U));
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m7a_out 
                    = (1U & ((IData)(vlSelf->din) >> 7U));
            }
        }
    } else if ((1U & (IData)(vlSelf->shamt))) {
        if ((1U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m7a_out 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m7a_out = 
            (1U & ((IData)(vlSelf->din) >> 7U));
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m0b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__m4b_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m0b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout 
                        = vlSelf->BarrelShifter_8Bit__DOT__m0b_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m4b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m4b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m6b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m6b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m2b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__m6b_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m2b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m7b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m5a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m7b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m7a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m7b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m7b_out = vlSelf->BarrelShifter_8Bit__DOT__m7a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((2U & (IData)(vlSelf->shamt))) {
                if ((2U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT__m5b_out 
                        = vlSelf->BarrelShifter_8Bit__DOT__m3a_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT__m5b_out 
                    = vlSelf->BarrelShifter_8Bit__DOT__m5a_out;
            }
        }
    } else if ((2U & (IData)(vlSelf->shamt))) {
        if ((2U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT__m5b_out 
                = vlSelf->BarrelShifter_8Bit__DOT__m7a_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT__m5b_out = vlSelf->BarrelShifter_8Bit__DOT__m5a_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout 
                        = vlSelf->BarrelShifter_8Bit__DOT__m7b_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m7b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m7b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m3b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__m7b_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m3b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout = 0U;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m1b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__m5b_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m1b_out;
    }
    if (vlSelf->lr) {
        if (vlSelf->lr) {
            if ((4U & (IData)(vlSelf->shamt))) {
                if ((4U & (IData)(vlSelf->shamt))) {
                    vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout 
                        = vlSelf->BarrelShifter_8Bit__DOT__m1b_out;
                }
            } else {
                vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout 
                    = vlSelf->BarrelShifter_8Bit__DOT__m5b_out;
            }
        }
    } else if ((4U & (IData)(vlSelf->shamt))) {
        if ((4U & (IData)(vlSelf->shamt))) {
            vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout 
                = vlSelf->BarrelShifter_8Bit__DOT__mc_out;
        }
    } else {
        vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout 
            = vlSelf->BarrelShifter_8Bit__DOT__m5b_out;
    }
    vlSelf->dout = (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m7c__dataout) 
                     << 7U) | (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m6c__dataout) 
                                << 6U) | (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m5c__dataout) 
                                           << 5U) | 
                                          (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m4c__dataout) 
                                            << 4U) 
                                           | (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m3c__dataout) 
                                               << 3U) 
                                              | (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m2c__dataout) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m1c__dataout) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->BarrelShifter_8Bit__DOT____Vcellout__m0c__dataout))))))));
}

void VBarrelShifter_8Bit___024root___eval(VBarrelShifter_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter_8Bit___024root___eval\n"); );
    // Body
    VBarrelShifter_8Bit___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
}

QData VBarrelShifter_8Bit___024root___change_request_1(VBarrelShifter_8Bit___024root* vlSelf);

VL_INLINE_OPT QData VBarrelShifter_8Bit___024root___change_request(VBarrelShifter_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter_8Bit___024root___change_request\n"); );
    // Body
    return (VBarrelShifter_8Bit___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VBarrelShifter_8Bit___024root___change_request_1(VBarrelShifter_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter_8Bit___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VBarrelShifter_8Bit___024root___eval_debug_assertions(VBarrelShifter_8Bit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBarrelShifter_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBarrelShifter_8Bit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->shamt & 0xf8U))) {
        Verilated::overWidthError("shamt");}
    if (VL_UNLIKELY((vlSelf->lr & 0xfeU))) {
        Verilated::overWidthError("lr");}
    if (VL_UNLIKELY((vlSelf->al & 0xfeU))) {
        Verilated::overWidthError("al");}
}
#endif  // VL_DEBUG
