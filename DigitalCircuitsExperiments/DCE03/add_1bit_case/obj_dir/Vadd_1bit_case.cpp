// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd_1bit_case.h"
#include "Vadd_1bit_case__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd_1bit_case::Vadd_1bit_case(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd_1bit_case__Syms(contextp(), _vcname__, this)}
    , c_i{vlSymsp->TOP.c_i}
    , a_i{vlSymsp->TOP.a_i}
    , b_i{vlSymsp->TOP.b_i}
    , s_i{vlSymsp->TOP.s_i}
    , c_iplus1{vlSymsp->TOP.c_iplus1}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd_1bit_case::Vadd_1bit_case(const char* _vcname__)
    : Vadd_1bit_case(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd_1bit_case::~Vadd_1bit_case() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd_1bit_case___024root___eval_debug_assertions(Vadd_1bit_case___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_1bit_case___024root___eval_static(Vadd_1bit_case___024root* vlSelf);
void Vadd_1bit_case___024root___eval_initial(Vadd_1bit_case___024root* vlSelf);
void Vadd_1bit_case___024root___eval_settle(Vadd_1bit_case___024root* vlSelf);
void Vadd_1bit_case___024root___eval(Vadd_1bit_case___024root* vlSelf);

void Vadd_1bit_case::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd_1bit_case::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd_1bit_case___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd_1bit_case___024root___eval_static(&(vlSymsp->TOP));
        Vadd_1bit_case___024root___eval_initial(&(vlSymsp->TOP));
        Vadd_1bit_case___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd_1bit_case___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd_1bit_case::eventsPending() { return false; }

uint64_t Vadd_1bit_case::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadd_1bit_case::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd_1bit_case___024root___eval_final(Vadd_1bit_case___024root* vlSelf);

VL_ATTR_COLD void Vadd_1bit_case::final() {
    Vadd_1bit_case___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd_1bit_case::hierName() const { return vlSymsp->name(); }
const char* Vadd_1bit_case::modelName() const { return "Vadd_1bit_case"; }
unsigned Vadd_1bit_case::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vadd_1bit_case::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd_1bit_case___024root__trace_init_top(Vadd_1bit_case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd_1bit_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_1bit_case___024root*>(voidSelf);
    Vadd_1bit_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vadd_1bit_case___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vadd_1bit_case___024root__trace_register(Vadd_1bit_case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd_1bit_case::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd_1bit_case::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd_1bit_case___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
