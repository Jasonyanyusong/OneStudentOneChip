// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecode_3to8_for.h"
#include "Vdecode_3to8_for__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdecode_3to8_for::Vdecode_3to8_for(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdecode_3to8_for__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , x{vlSymsp->TOP.x}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdecode_3to8_for::Vdecode_3to8_for(const char* _vcname__)
    : Vdecode_3to8_for(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdecode_3to8_for::~Vdecode_3to8_for() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdecode_3to8_for___024root___eval_debug_assertions(Vdecode_3to8_for___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecode_3to8_for___024root___eval_static(Vdecode_3to8_for___024root* vlSelf);
void Vdecode_3to8_for___024root___eval_initial(Vdecode_3to8_for___024root* vlSelf);
void Vdecode_3to8_for___024root___eval_settle(Vdecode_3to8_for___024root* vlSelf);
void Vdecode_3to8_for___024root___eval(Vdecode_3to8_for___024root* vlSelf);

void Vdecode_3to8_for::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecode_3to8_for::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdecode_3to8_for___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdecode_3to8_for___024root___eval_static(&(vlSymsp->TOP));
        Vdecode_3to8_for___024root___eval_initial(&(vlSymsp->TOP));
        Vdecode_3to8_for___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdecode_3to8_for___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdecode_3to8_for::eventsPending() { return false; }

uint64_t Vdecode_3to8_for::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdecode_3to8_for::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdecode_3to8_for___024root___eval_final(Vdecode_3to8_for___024root* vlSelf);

VL_ATTR_COLD void Vdecode_3to8_for::final() {
    Vdecode_3to8_for___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdecode_3to8_for::hierName() const { return vlSymsp->name(); }
const char* Vdecode_3to8_for::modelName() const { return "Vdecode_3to8_for"; }
unsigned Vdecode_3to8_for::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdecode_3to8_for::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdecode_3to8_for___024root__trace_init_top(Vdecode_3to8_for___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecode_3to8_for___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode_3to8_for___024root*>(voidSelf);
    Vdecode_3to8_for__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdecode_3to8_for___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdecode_3to8_for___024root__trace_register(Vdecode_3to8_for___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdecode_3to8_for::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdecode_3to8_for::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdecode_3to8_for___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
