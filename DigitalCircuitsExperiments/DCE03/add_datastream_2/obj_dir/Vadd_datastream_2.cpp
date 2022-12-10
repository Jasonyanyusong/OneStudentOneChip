// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd_datastream_2.h"
#include "Vadd_datastream_2__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd_datastream_2::Vadd_datastream_2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd_datastream_2__Syms(contextp(), _vcname__, this)}
    , in_x{vlSymsp->TOP.in_x}
    , in_y{vlSymsp->TOP.in_y}
    , out_s{vlSymsp->TOP.out_s}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd_datastream_2::Vadd_datastream_2(const char* _vcname__)
    : Vadd_datastream_2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd_datastream_2::~Vadd_datastream_2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd_datastream_2___024root___eval_debug_assertions(Vadd_datastream_2___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_datastream_2___024root___eval_static(Vadd_datastream_2___024root* vlSelf);
void Vadd_datastream_2___024root___eval_initial(Vadd_datastream_2___024root* vlSelf);
void Vadd_datastream_2___024root___eval_settle(Vadd_datastream_2___024root* vlSelf);
void Vadd_datastream_2___024root___eval(Vadd_datastream_2___024root* vlSelf);

void Vadd_datastream_2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd_datastream_2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd_datastream_2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd_datastream_2___024root___eval_static(&(vlSymsp->TOP));
        Vadd_datastream_2___024root___eval_initial(&(vlSymsp->TOP));
        Vadd_datastream_2___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd_datastream_2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd_datastream_2::eventsPending() { return false; }

uint64_t Vadd_datastream_2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadd_datastream_2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd_datastream_2___024root___eval_final(Vadd_datastream_2___024root* vlSelf);

VL_ATTR_COLD void Vadd_datastream_2::final() {
    Vadd_datastream_2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd_datastream_2::hierName() const { return vlSymsp->name(); }
const char* Vadd_datastream_2::modelName() const { return "Vadd_datastream_2"; }
unsigned Vadd_datastream_2::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vadd_datastream_2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd_datastream_2___024root__trace_init_top(Vadd_datastream_2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd_datastream_2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_datastream_2___024root*>(voidSelf);
    Vadd_datastream_2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vadd_datastream_2___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vadd_datastream_2___024root__trace_register(Vadd_datastream_2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd_datastream_2::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd_datastream_2::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd_datastream_2___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
