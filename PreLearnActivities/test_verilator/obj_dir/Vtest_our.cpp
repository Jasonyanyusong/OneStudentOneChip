// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtest_our.h"
#include "Vtest_our__Syms.h"

//============================================================
// Constructors

Vtest_our::Vtest_our(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtest_our__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtest_our::Vtest_our(const char* _vcname__)
    : Vtest_our(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtest_our::~Vtest_our() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtest_our___024root___eval_debug_assertions(Vtest_our___024root* vlSelf);
#endif  // VL_DEBUG
void Vtest_our___024root___eval_static(Vtest_our___024root* vlSelf);
void Vtest_our___024root___eval_initial(Vtest_our___024root* vlSelf);
void Vtest_our___024root___eval_settle(Vtest_our___024root* vlSelf);
void Vtest_our___024root___eval(Vtest_our___024root* vlSelf);

void Vtest_our::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest_our::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtest_our___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtest_our___024root___eval_static(&(vlSymsp->TOP));
        Vtest_our___024root___eval_initial(&(vlSymsp->TOP));
        Vtest_our___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtest_our___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtest_our::eventsPending() { return false; }

uint64_t Vtest_our::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtest_our::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtest_our___024root___eval_final(Vtest_our___024root* vlSelf);

VL_ATTR_COLD void Vtest_our::final() {
    Vtest_our___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtest_our::hierName() const { return vlSymsp->name(); }
const char* Vtest_our::modelName() const { return "Vtest_our"; }
unsigned Vtest_our::threads() const { return 1; }
