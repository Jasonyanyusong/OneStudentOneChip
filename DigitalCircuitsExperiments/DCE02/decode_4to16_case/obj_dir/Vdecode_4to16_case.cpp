// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecode_4to16_case.h"
#include "Vdecode_4to16_case__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdecode_4to16_case::Vdecode_4to16_case(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdecode_4to16_case__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , x{vlSymsp->TOP.x}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdecode_4to16_case::Vdecode_4to16_case(const char* _vcname__)
    : Vdecode_4to16_case(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdecode_4to16_case::~Vdecode_4to16_case() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdecode_4to16_case___024root___eval_debug_assertions(Vdecode_4to16_case___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecode_4to16_case___024root___eval_static(Vdecode_4to16_case___024root* vlSelf);
void Vdecode_4to16_case___024root___eval_initial(Vdecode_4to16_case___024root* vlSelf);
void Vdecode_4to16_case___024root___eval_settle(Vdecode_4to16_case___024root* vlSelf);
void Vdecode_4to16_case___024root___eval(Vdecode_4to16_case___024root* vlSelf);

void Vdecode_4to16_case::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecode_4to16_case::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdecode_4to16_case___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdecode_4to16_case___024root___eval_static(&(vlSymsp->TOP));
        Vdecode_4to16_case___024root___eval_initial(&(vlSymsp->TOP));
        Vdecode_4to16_case___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdecode_4to16_case___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdecode_4to16_case::eventsPending() { return false; }

uint64_t Vdecode_4to16_case::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdecode_4to16_case::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdecode_4to16_case___024root___eval_final(Vdecode_4to16_case___024root* vlSelf);

VL_ATTR_COLD void Vdecode_4to16_case::final() {
    Vdecode_4to16_case___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdecode_4to16_case::hierName() const { return vlSymsp->name(); }
const char* Vdecode_4to16_case::modelName() const { return "Vdecode_4to16_case"; }
unsigned Vdecode_4to16_case::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdecode_4to16_case::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdecode_4to16_case___024root__trace_init_top(Vdecode_4to16_case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecode_4to16_case___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode_4to16_case___024root*>(voidSelf);
    Vdecode_4to16_case__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdecode_4to16_case___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdecode_4to16_case___024root__trace_register(Vdecode_4to16_case___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdecode_4to16_case::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdecode_4to16_case::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdecode_4to16_case___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
