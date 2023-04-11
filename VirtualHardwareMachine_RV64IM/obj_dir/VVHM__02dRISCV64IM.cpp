// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VVHM__02dRISCV64IM.h"
#include "VVHM__02dRISCV64IM__Syms.h"

//============================================================
// Constructors

VVHM__02dRISCV64IM::VVHM__02dRISCV64IM(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VVHM__02dRISCV64IM__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , vhm_status{vlSymsp->TOP.vhm_status}
    , riscv_32bits_instruction{vlSymsp->TOP.riscv_32bits_instruction}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VVHM__02dRISCV64IM::VVHM__02dRISCV64IM(const char* _vcname__)
    : VVHM__02dRISCV64IM(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VVHM__02dRISCV64IM::~VVHM__02dRISCV64IM() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VVHM__02dRISCV64IM___024root___eval_debug_assertions(VVHM__02dRISCV64IM___024root* vlSelf);
#endif  // VL_DEBUG
void VVHM__02dRISCV64IM___024root___eval_static(VVHM__02dRISCV64IM___024root* vlSelf);
void VVHM__02dRISCV64IM___024root___eval_initial(VVHM__02dRISCV64IM___024root* vlSelf);
void VVHM__02dRISCV64IM___024root___eval_settle(VVHM__02dRISCV64IM___024root* vlSelf);
void VVHM__02dRISCV64IM___024root___eval(VVHM__02dRISCV64IM___024root* vlSelf);

void VVHM__02dRISCV64IM::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VVHM__02dRISCV64IM::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VVHM__02dRISCV64IM___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VVHM__02dRISCV64IM___024root___eval_static(&(vlSymsp->TOP));
        VVHM__02dRISCV64IM___024root___eval_initial(&(vlSymsp->TOP));
        VVHM__02dRISCV64IM___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VVHM__02dRISCV64IM___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VVHM__02dRISCV64IM::eventsPending() { return false; }

uint64_t VVHM__02dRISCV64IM::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VVHM__02dRISCV64IM::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VVHM__02dRISCV64IM___024root___eval_final(VVHM__02dRISCV64IM___024root* vlSelf);

VL_ATTR_COLD void VVHM__02dRISCV64IM::final() {
    VVHM__02dRISCV64IM___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VVHM__02dRISCV64IM::hierName() const { return vlSymsp->name(); }
const char* VVHM__02dRISCV64IM::modelName() const { return "VVHM__02dRISCV64IM"; }
unsigned VVHM__02dRISCV64IM::threads() const { return 1; }
