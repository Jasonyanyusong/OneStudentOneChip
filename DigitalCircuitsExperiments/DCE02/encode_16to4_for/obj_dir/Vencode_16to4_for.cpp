// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vencode_16to4_for.h"
#include "Vencode_16to4_for__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vencode_16to4_for::Vencode_16to4_for(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vencode_16to4_for__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , y{vlSymsp->TOP.y}
    , x{vlSymsp->TOP.x}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vencode_16to4_for::Vencode_16to4_for(const char* _vcname__)
    : Vencode_16to4_for(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vencode_16to4_for::~Vencode_16to4_for() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vencode_16to4_for___024root___eval_debug_assertions(Vencode_16to4_for___024root* vlSelf);
#endif  // VL_DEBUG
void Vencode_16to4_for___024root___eval_static(Vencode_16to4_for___024root* vlSelf);
void Vencode_16to4_for___024root___eval_initial(Vencode_16to4_for___024root* vlSelf);
void Vencode_16to4_for___024root___eval_settle(Vencode_16to4_for___024root* vlSelf);
void Vencode_16to4_for___024root___eval(Vencode_16to4_for___024root* vlSelf);

void Vencode_16to4_for::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vencode_16to4_for::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vencode_16to4_for___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vencode_16to4_for___024root___eval_static(&(vlSymsp->TOP));
        Vencode_16to4_for___024root___eval_initial(&(vlSymsp->TOP));
        Vencode_16to4_for___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vencode_16to4_for___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vencode_16to4_for::eventsPending() { return false; }

uint64_t Vencode_16to4_for::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vencode_16to4_for::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vencode_16to4_for___024root___eval_final(Vencode_16to4_for___024root* vlSelf);

VL_ATTR_COLD void Vencode_16to4_for::final() {
    Vencode_16to4_for___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vencode_16to4_for::hierName() const { return vlSymsp->name(); }
const char* Vencode_16to4_for::modelName() const { return "Vencode_16to4_for"; }
unsigned Vencode_16to4_for::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vencode_16to4_for::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vencode_16to4_for___024root__trace_init_top(Vencode_16to4_for___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vencode_16to4_for___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode_16to4_for___024root*>(voidSelf);
    Vencode_16to4_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vencode_16to4_for___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vencode_16to4_for___024root__trace_register(Vencode_16to4_for___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vencode_16to4_for::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vencode_16to4_for::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vencode_16to4_for___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
