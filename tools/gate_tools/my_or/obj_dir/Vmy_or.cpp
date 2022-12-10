// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmy_or.h"
#include "Vmy_or__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmy_or::Vmy_or(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmy_or__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmy_or::Vmy_or(const char* _vcname__)
    : Vmy_or(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmy_or::~Vmy_or() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmy_or___024root___eval_debug_assertions(Vmy_or___024root* vlSelf);
#endif  // VL_DEBUG
void Vmy_or___024root___eval_static(Vmy_or___024root* vlSelf);
void Vmy_or___024root___eval_initial(Vmy_or___024root* vlSelf);
void Vmy_or___024root___eval_settle(Vmy_or___024root* vlSelf);
void Vmy_or___024root___eval(Vmy_or___024root* vlSelf);

void Vmy_or::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmy_or::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmy_or___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmy_or___024root___eval_static(&(vlSymsp->TOP));
        Vmy_or___024root___eval_initial(&(vlSymsp->TOP));
        Vmy_or___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmy_or___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmy_or::eventsPending() { return false; }

uint64_t Vmy_or::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmy_or::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmy_or___024root___eval_final(Vmy_or___024root* vlSelf);

VL_ATTR_COLD void Vmy_or::final() {
    Vmy_or___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmy_or::hierName() const { return vlSymsp->name(); }
const char* Vmy_or::modelName() const { return "Vmy_or"; }
unsigned Vmy_or::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmy_or::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmy_or___024root__trace_init_top(Vmy_or___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmy_or___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_or___024root*>(voidSelf);
    Vmy_or__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmy_or___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmy_or___024root__trace_register(Vmy_or___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmy_or::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmy_or::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmy_or___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
