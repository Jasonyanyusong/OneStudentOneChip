// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU32_TestCase_1.h"
#include "VALU32_TestCase_1__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VALU32_TestCase_1::VALU32_TestCase_1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VALU32_TestCase_1__Syms(contextp(), _vcname__, this)}
    , sub_add{vlSymsp->TOP.sub_add}
    , carry{vlSymsp->TOP.carry}
    , zero{vlSymsp->TOP.zero}
    , overflow{vlSymsp->TOP.overflow}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VALU32_TestCase_1::VALU32_TestCase_1(const char* _vcname__)
    : VALU32_TestCase_1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VALU32_TestCase_1::~VALU32_TestCase_1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VALU32_TestCase_1___024root___eval_debug_assertions(VALU32_TestCase_1___024root* vlSelf);
#endif  // VL_DEBUG
void VALU32_TestCase_1___024root___eval_static(VALU32_TestCase_1___024root* vlSelf);
void VALU32_TestCase_1___024root___eval_initial(VALU32_TestCase_1___024root* vlSelf);
void VALU32_TestCase_1___024root___eval_settle(VALU32_TestCase_1___024root* vlSelf);
void VALU32_TestCase_1___024root___eval(VALU32_TestCase_1___024root* vlSelf);

void VALU32_TestCase_1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU32_TestCase_1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VALU32_TestCase_1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VALU32_TestCase_1___024root___eval_static(&(vlSymsp->TOP));
        VALU32_TestCase_1___024root___eval_initial(&(vlSymsp->TOP));
        VALU32_TestCase_1___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VALU32_TestCase_1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VALU32_TestCase_1::eventsPending() { return false; }

uint64_t VALU32_TestCase_1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VALU32_TestCase_1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VALU32_TestCase_1___024root___eval_final(VALU32_TestCase_1___024root* vlSelf);

VL_ATTR_COLD void VALU32_TestCase_1::final() {
    VALU32_TestCase_1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VALU32_TestCase_1::hierName() const { return vlSymsp->name(); }
const char* VALU32_TestCase_1::modelName() const { return "VALU32_TestCase_1"; }
unsigned VALU32_TestCase_1::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VALU32_TestCase_1::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VALU32_TestCase_1___024root__trace_init_top(VALU32_TestCase_1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU32_TestCase_1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32_TestCase_1___024root*>(voidSelf);
    VALU32_TestCase_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VALU32_TestCase_1___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VALU32_TestCase_1___024root__trace_register(VALU32_TestCase_1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VALU32_TestCase_1::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VALU32_TestCase_1::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VALU32_TestCase_1___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
