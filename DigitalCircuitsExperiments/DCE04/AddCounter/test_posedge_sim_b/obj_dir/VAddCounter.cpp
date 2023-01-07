// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAddCounter.h"
#include "VAddCounter__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VAddCounter::VAddCounter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VAddCounter__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
}

VAddCounter::VAddCounter(const char* _vcname__)
    : VAddCounter(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VAddCounter::~VAddCounter() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VAddCounter___024root___eval_initial(VAddCounter___024root* vlSelf);
void VAddCounter___024root___eval_settle(VAddCounter___024root* vlSelf);
void VAddCounter___024root___eval(VAddCounter___024root* vlSelf);
QData VAddCounter___024root___change_request(VAddCounter___024root* vlSelf);
#ifdef VL_DEBUG
void VAddCounter___024root___eval_debug_assertions(VAddCounter___024root* vlSelf);
#endif  // VL_DEBUG
void VAddCounter___024root___final(VAddCounter___024root* vlSelf);

static void _eval_initial_loop(VAddCounter__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VAddCounter___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VAddCounter___024root___eval_settle(&(vlSymsp->TOP));
        VAddCounter___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VAddCounter___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AddCounter.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VAddCounter___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAddCounter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAddCounter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAddCounter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VAddCounter___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VAddCounter___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AddCounter.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VAddCounter___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VAddCounter::final() {
    VAddCounter___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VAddCounter::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VAddCounter::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VAddCounter___024root__traceInitTop(VAddCounter___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VAddCounter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAddCounter___024root*>(voidSelf);
    VAddCounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VAddCounter___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VAddCounter___024root__traceRegister(VAddCounter___024root* vlSelf, VerilatedVcd* tracep);

void VAddCounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VAddCounter___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
