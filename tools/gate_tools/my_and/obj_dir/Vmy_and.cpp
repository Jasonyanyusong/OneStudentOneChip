// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmy_and.h"
#include "Vmy_and__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmy_and::Vmy_and(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmy_and__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmy_and::Vmy_and(const char* _vcname__)
    : Vmy_and(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmy_and::~Vmy_and() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmy_and___024root___eval_debug_assertions(Vmy_and___024root* vlSelf);
#endif  // VL_DEBUG
void Vmy_and___024root___eval_static(Vmy_and___024root* vlSelf);
void Vmy_and___024root___eval_initial(Vmy_and___024root* vlSelf);
void Vmy_and___024root___eval_settle(Vmy_and___024root* vlSelf);
void Vmy_and___024root___eval(Vmy_and___024root* vlSelf);

void Vmy_and::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmy_and::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmy_and___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmy_and___024root___eval_static(&(vlSymsp->TOP));
        Vmy_and___024root___eval_initial(&(vlSymsp->TOP));
        Vmy_and___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmy_and___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmy_and::eventsPending() { return false; }

uint64_t Vmy_and::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmy_and::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmy_and___024root___eval_final(Vmy_and___024root* vlSelf);

VL_ATTR_COLD void Vmy_and::final() {
    Vmy_and___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmy_and::hierName() const { return vlSymsp->name(); }
const char* Vmy_and::modelName() const { return "Vmy_and"; }
unsigned Vmy_and::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmy_and::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmy_and___024root__trace_init_top(Vmy_and___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmy_and___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_and___024root*>(voidSelf);
    Vmy_and__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmy_and___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmy_and___024root__trace_register(Vmy_and___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmy_and::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmy_and::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmy_and___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
