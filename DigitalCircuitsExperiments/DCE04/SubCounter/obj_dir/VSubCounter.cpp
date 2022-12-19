// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSubCounter.h"
#include "VSubCounter__Syms.h"

//============================================================
// Constructors

VSubCounter::VSubCounter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSubCounter__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VSubCounter::VSubCounter(const char* _vcname__)
    : VSubCounter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSubCounter::~VSubCounter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSubCounter___024root___eval_debug_assertions(VSubCounter___024root* vlSelf);
#endif  // VL_DEBUG
void VSubCounter___024root___eval_static(VSubCounter___024root* vlSelf);
void VSubCounter___024root___eval_initial(VSubCounter___024root* vlSelf);
void VSubCounter___024root___eval_settle(VSubCounter___024root* vlSelf);
void VSubCounter___024root___eval(VSubCounter___024root* vlSelf);

void VSubCounter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSubCounter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSubCounter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSubCounter___024root___eval_static(&(vlSymsp->TOP));
        VSubCounter___024root___eval_initial(&(vlSymsp->TOP));
        VSubCounter___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSubCounter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSubCounter::eventsPending() { return false; }

uint64_t VSubCounter::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSubCounter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSubCounter___024root___eval_final(VSubCounter___024root* vlSelf);

VL_ATTR_COLD void VSubCounter::final() {
    VSubCounter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSubCounter::hierName() const { return vlSymsp->name(); }
const char* VSubCounter::modelName() const { return "VSubCounter"; }
unsigned VSubCounter::threads() const { return 1; }
