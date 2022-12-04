// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtest_our_systemC.h"
#include "Vtest_our_systemC__Syms.h"

//============================================================
// Constructors

Vtest_our_systemC::Vtest_our_systemC(sc_module_name /* unused */)
    : VerilatedModel{*Verilated::threadContextp()}
    , vlSymsp{new Vtest_our_systemC__Syms(contextp(), name(), this)}
    , clk{vlSymsp->TOP.clk}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    // Sensitivities on all clocks and combinational inputs
    SC_METHOD(eval);
    sensitive << clk;

}

//============================================================
// Destructor

Vtest_our_systemC::~Vtest_our_systemC() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtest_our_systemC___024root___eval_debug_assertions(Vtest_our_systemC___024root* vlSelf);
#endif  // VL_DEBUG
void Vtest_our_systemC___024root___eval_static(Vtest_our_systemC___024root* vlSelf);
void Vtest_our_systemC___024root___eval_initial(Vtest_our_systemC___024root* vlSelf);
void Vtest_our_systemC___024root___eval_settle(Vtest_our_systemC___024root* vlSelf);
void Vtest_our_systemC___024root___eval(Vtest_our_systemC___024root* vlSelf);

void Vtest_our_systemC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest_our_systemC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtest_our_systemC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtest_our_systemC___024root___eval_static(&(vlSymsp->TOP));
        Vtest_our_systemC___024root___eval_initial(&(vlSymsp->TOP));
        Vtest_our_systemC___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtest_our_systemC___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtest_our_systemC::eventsPending() { return false; }

uint64_t Vtest_our_systemC::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

//============================================================
// Invoke final blocks

void Vtest_our_systemC___024root___eval_final(Vtest_our_systemC___024root* vlSelf);

VL_ATTR_COLD void Vtest_our_systemC::final() {
    Vtest_our_systemC___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtest_our_systemC::hierName() const { return vlSymsp->name(); }
const char* Vtest_our_systemC::modelName() const { return "Vtest_our_systemC"; }
unsigned Vtest_our_systemC::threads() const { return 1; }
