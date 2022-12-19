// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAddCounter.h"
#include "VAddCounter__Syms.h"

//============================================================
// Constructors

VAddCounter::VAddCounter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VAddCounter__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VAddCounter::VAddCounter(const char* _vcname__)
    : VAddCounter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VAddCounter::~VAddCounter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VAddCounter___024root___eval_debug_assertions(VAddCounter___024root* vlSelf);
#endif  // VL_DEBUG
void VAddCounter___024root___eval_static(VAddCounter___024root* vlSelf);
void VAddCounter___024root___eval_initial(VAddCounter___024root* vlSelf);
void VAddCounter___024root___eval_settle(VAddCounter___024root* vlSelf);
void VAddCounter___024root___eval(VAddCounter___024root* vlSelf);

void VAddCounter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAddCounter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAddCounter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VAddCounter___024root___eval_static(&(vlSymsp->TOP));
        VAddCounter___024root___eval_initial(&(vlSymsp->TOP));
        VAddCounter___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VAddCounter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VAddCounter::eventsPending() { return false; }

uint64_t VAddCounter::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VAddCounter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VAddCounter___024root___eval_final(VAddCounter___024root* vlSelf);

VL_ATTR_COLD void VAddCounter::final() {
    VAddCounter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VAddCounter::hierName() const { return vlSymsp->name(); }
const char* VAddCounter::modelName() const { return "VAddCounter"; }
unsigned VAddCounter::threads() const { return 1; }
