// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd_4bit_structure.h"
#include "Vadd_4bit_structure__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd_4bit_structure::Vadd_4bit_structure(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd_4bit_structure__Syms(contextp(), _vcname__, this)}
    , a_0{vlSymsp->TOP.a_0}
    , b_0{vlSymsp->TOP.b_0}
    , c_in{vlSymsp->TOP.c_in}
    , a_1{vlSymsp->TOP.a_1}
    , b_1{vlSymsp->TOP.b_1}
    , a_2{vlSymsp->TOP.a_2}
    , b_2{vlSymsp->TOP.b_2}
    , a_3{vlSymsp->TOP.a_3}
    , b_3{vlSymsp->TOP.b_3}
    , s_0{vlSymsp->TOP.s_0}
    , c_1{vlSymsp->TOP.c_1}
    , s_1{vlSymsp->TOP.s_1}
    , c_2{vlSymsp->TOP.c_2}
    , s_2{vlSymsp->TOP.s_2}
    , c_3{vlSymsp->TOP.c_3}
    , s_3{vlSymsp->TOP.s_3}
    , c_out{vlSymsp->TOP.c_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd_4bit_structure::Vadd_4bit_structure(const char* _vcname__)
    : Vadd_4bit_structure(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd_4bit_structure::~Vadd_4bit_structure() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd_4bit_structure___024root___eval_debug_assertions(Vadd_4bit_structure___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_4bit_structure___024root___eval_static(Vadd_4bit_structure___024root* vlSelf);
void Vadd_4bit_structure___024root___eval_initial(Vadd_4bit_structure___024root* vlSelf);
void Vadd_4bit_structure___024root___eval_settle(Vadd_4bit_structure___024root* vlSelf);
void Vadd_4bit_structure___024root___eval(Vadd_4bit_structure___024root* vlSelf);

void Vadd_4bit_structure::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd_4bit_structure::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd_4bit_structure___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd_4bit_structure___024root___eval_static(&(vlSymsp->TOP));
        Vadd_4bit_structure___024root___eval_initial(&(vlSymsp->TOP));
        Vadd_4bit_structure___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd_4bit_structure___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd_4bit_structure::eventsPending() { return false; }

uint64_t Vadd_4bit_structure::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadd_4bit_structure::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd_4bit_structure___024root___eval_final(Vadd_4bit_structure___024root* vlSelf);

VL_ATTR_COLD void Vadd_4bit_structure::final() {
    Vadd_4bit_structure___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd_4bit_structure::hierName() const { return vlSymsp->name(); }
const char* Vadd_4bit_structure::modelName() const { return "Vadd_4bit_structure"; }
unsigned Vadd_4bit_structure::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vadd_4bit_structure::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd_4bit_structure___024root__trace_init_top(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd_4bit_structure___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_4bit_structure___024root*>(voidSelf);
    Vadd_4bit_structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vadd_4bit_structure___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vadd_4bit_structure___024root__trace_register(Vadd_4bit_structure___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd_4bit_structure::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd_4bit_structure::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd_4bit_structure___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
