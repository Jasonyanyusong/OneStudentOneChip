// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU32.h"
#include "VALU32__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VALU32::VALU32(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VALU32__Syms(contextp(), _vcname__, this)}
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

VALU32::VALU32(const char* _vcname__)
    : VALU32(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VALU32::~VALU32() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VALU32___024root___eval_debug_assertions(VALU32___024root* vlSelf);
#endif  // VL_DEBUG
void VALU32___024root___eval_static(VALU32___024root* vlSelf);
void VALU32___024root___eval_initial(VALU32___024root* vlSelf);
void VALU32___024root___eval_settle(VALU32___024root* vlSelf);
void VALU32___024root___eval(VALU32___024root* vlSelf);

void VALU32::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU32::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VALU32___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VALU32___024root___eval_static(&(vlSymsp->TOP));
        VALU32___024root___eval_initial(&(vlSymsp->TOP));
        VALU32___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VALU32___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VALU32::eventsPending() { return false; }

uint64_t VALU32::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VALU32::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VALU32___024root___eval_final(VALU32___024root* vlSelf);

VL_ATTR_COLD void VALU32::final() {
    VALU32___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VALU32::hierName() const { return vlSymsp->name(); }
const char* VALU32::modelName() const { return "VALU32"; }
unsigned VALU32::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VALU32::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VALU32___024root__trace_init_top(VALU32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU32___024root*>(voidSelf);
    VALU32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VALU32___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VALU32___024root__trace_register(VALU32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VALU32::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VALU32::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VALU32___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
