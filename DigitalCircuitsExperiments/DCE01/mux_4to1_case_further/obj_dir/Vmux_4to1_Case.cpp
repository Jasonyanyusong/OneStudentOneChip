// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux_4to1_Case.h"
#include "Vmux_4to1_Case__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux_4to1_Case::Vmux_4to1_Case(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmux_4to1_Case__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmux_4to1_Case::Vmux_4to1_Case(const char* _vcname__)
    : Vmux_4to1_Case(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmux_4to1_Case::~Vmux_4to1_Case() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmux_4to1_Case___024root___eval_debug_assertions(Vmux_4to1_Case___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux_4to1_Case___024root___eval_static(Vmux_4to1_Case___024root* vlSelf);
void Vmux_4to1_Case___024root___eval_initial(Vmux_4to1_Case___024root* vlSelf);
void Vmux_4to1_Case___024root___eval_settle(Vmux_4to1_Case___024root* vlSelf);
void Vmux_4to1_Case___024root___eval(Vmux_4to1_Case___024root* vlSelf);

void Vmux_4to1_Case::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux_4to1_Case::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux_4to1_Case___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmux_4to1_Case___024root___eval_static(&(vlSymsp->TOP));
        Vmux_4to1_Case___024root___eval_initial(&(vlSymsp->TOP));
        Vmux_4to1_Case___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmux_4to1_Case___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmux_4to1_Case::eventsPending() { return false; }

uint64_t Vmux_4to1_Case::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmux_4to1_Case::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmux_4to1_Case___024root___eval_final(Vmux_4to1_Case___024root* vlSelf);

VL_ATTR_COLD void Vmux_4to1_Case::final() {
    Vmux_4to1_Case___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmux_4to1_Case::hierName() const { return vlSymsp->name(); }
const char* Vmux_4to1_Case::modelName() const { return "Vmux_4to1_Case"; }
unsigned Vmux_4to1_Case::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmux_4to1_Case::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmux_4to1_Case___024root__trace_init_top(Vmux_4to1_Case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux_4to1_Case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux_4to1_Case___024root*>(voidSelf);
    Vmux_4to1_Case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmux_4to1_Case___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmux_4to1_Case___024root__trace_register(Vmux_4to1_Case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux_4to1_Case::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmux_4to1_Case::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmux_4to1_Case___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
