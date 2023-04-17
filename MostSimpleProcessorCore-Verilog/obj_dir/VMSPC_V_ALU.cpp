// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMSPC_V_ALU.h"
#include "VMSPC_V_ALU__Syms.h"

//============================================================
// Constructors

VMSPC_V_ALU::VMSPC_V_ALU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMSPC_V_ALU__Syms(contextp(), _vcname__, this)}
    , sel{vlSymsp->TOP.sel}
    , booloutp{vlSymsp->TOP.booloutp}
    , inpa{vlSymsp->TOP.inpa}
    , inpb{vlSymsp->TOP.inpb}
    , numoutp{vlSymsp->TOP.numoutp}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VMSPC_V_ALU::VMSPC_V_ALU(const char* _vcname__)
    : VMSPC_V_ALU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMSPC_V_ALU::~VMSPC_V_ALU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMSPC_V_ALU___024root___eval_debug_assertions(VMSPC_V_ALU___024root* vlSelf);
#endif  // VL_DEBUG
void VMSPC_V_ALU___024root___eval_static(VMSPC_V_ALU___024root* vlSelf);
void VMSPC_V_ALU___024root___eval_initial(VMSPC_V_ALU___024root* vlSelf);
void VMSPC_V_ALU___024root___eval_settle(VMSPC_V_ALU___024root* vlSelf);
void VMSPC_V_ALU___024root___eval(VMSPC_V_ALU___024root* vlSelf);

void VMSPC_V_ALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMSPC_V_ALU::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMSPC_V_ALU___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMSPC_V_ALU___024root___eval_static(&(vlSymsp->TOP));
        VMSPC_V_ALU___024root___eval_initial(&(vlSymsp->TOP));
        VMSPC_V_ALU___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMSPC_V_ALU___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMSPC_V_ALU::eventsPending() { return false; }

uint64_t VMSPC_V_ALU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMSPC_V_ALU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMSPC_V_ALU___024root___eval_final(VMSPC_V_ALU___024root* vlSelf);

VL_ATTR_COLD void VMSPC_V_ALU::final() {
    VMSPC_V_ALU___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMSPC_V_ALU::hierName() const { return vlSymsp->name(); }
const char* VMSPC_V_ALU::modelName() const { return "VMSPC_V_ALU"; }
unsigned VMSPC_V_ALU::threads() const { return 1; }
