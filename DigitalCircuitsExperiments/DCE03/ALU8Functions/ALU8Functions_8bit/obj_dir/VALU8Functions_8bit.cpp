// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU8Functions_8bit.h"
#include "VALU8Functions_8bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VALU8Functions_8bit::VALU8Functions_8bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VALU8Functions_8bit__Syms(contextp(), _vcname__, this)}
    , input_mode_select{vlSymsp->TOP.input_mode_select}
    , input_a{vlSymsp->TOP.input_a}
    , input_b{vlSymsp->TOP.input_b}
    , output_result{vlSymsp->TOP.output_result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VALU8Functions_8bit::VALU8Functions_8bit(const char* _vcname__)
    : VALU8Functions_8bit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VALU8Functions_8bit::~VALU8Functions_8bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VALU8Functions_8bit___024root___eval_debug_assertions(VALU8Functions_8bit___024root* vlSelf);
#endif  // VL_DEBUG
void VALU8Functions_8bit___024root___eval_static(VALU8Functions_8bit___024root* vlSelf);
void VALU8Functions_8bit___024root___eval_initial(VALU8Functions_8bit___024root* vlSelf);
void VALU8Functions_8bit___024root___eval_settle(VALU8Functions_8bit___024root* vlSelf);
void VALU8Functions_8bit___024root___eval(VALU8Functions_8bit___024root* vlSelf);

void VALU8Functions_8bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU8Functions_8bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VALU8Functions_8bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VALU8Functions_8bit___024root___eval_static(&(vlSymsp->TOP));
        VALU8Functions_8bit___024root___eval_initial(&(vlSymsp->TOP));
        VALU8Functions_8bit___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VALU8Functions_8bit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VALU8Functions_8bit::eventsPending() { return false; }

uint64_t VALU8Functions_8bit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VALU8Functions_8bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VALU8Functions_8bit___024root___eval_final(VALU8Functions_8bit___024root* vlSelf);

VL_ATTR_COLD void VALU8Functions_8bit::final() {
    VALU8Functions_8bit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VALU8Functions_8bit::hierName() const { return vlSymsp->name(); }
const char* VALU8Functions_8bit::modelName() const { return "VALU8Functions_8bit"; }
unsigned VALU8Functions_8bit::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VALU8Functions_8bit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VALU8Functions_8bit___024root__trace_init_top(VALU8Functions_8bit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU8Functions_8bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU8Functions_8bit___024root*>(voidSelf);
    VALU8Functions_8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VALU8Functions_8bit___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VALU8Functions_8bit___024root__trace_register(VALU8Functions_8bit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VALU8Functions_8bit::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VALU8Functions_8bit::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VALU8Functions_8bit___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
