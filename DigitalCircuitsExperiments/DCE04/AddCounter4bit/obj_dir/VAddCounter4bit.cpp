// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAddCounter4bit.h"
#include "VAddCounter4bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VAddCounter4bit::VAddCounter4bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VAddCounter4bit__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
}

VAddCounter4bit::VAddCounter4bit(const char* _vcname__)
    : VAddCounter4bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VAddCounter4bit::~VAddCounter4bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VAddCounter4bit___024root___eval_initial(VAddCounter4bit___024root* vlSelf);
void VAddCounter4bit___024root___eval_settle(VAddCounter4bit___024root* vlSelf);
void VAddCounter4bit___024root___eval(VAddCounter4bit___024root* vlSelf);
QData VAddCounter4bit___024root___change_request(VAddCounter4bit___024root* vlSelf);
#ifdef VL_DEBUG
void VAddCounter4bit___024root___eval_debug_assertions(VAddCounter4bit___024root* vlSelf);
#endif  // VL_DEBUG
void VAddCounter4bit___024root___final(VAddCounter4bit___024root* vlSelf);

static void _eval_initial_loop(VAddCounter4bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VAddCounter4bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VAddCounter4bit___024root___eval_settle(&(vlSymsp->TOP));
        VAddCounter4bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VAddCounter4bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AddCounter4bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VAddCounter4bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAddCounter4bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAddCounter4bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAddCounter4bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VAddCounter4bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VAddCounter4bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AddCounter4bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VAddCounter4bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VAddCounter4bit::final() {
    VAddCounter4bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VAddCounter4bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VAddCounter4bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VAddCounter4bit___024root__traceInitTop(VAddCounter4bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VAddCounter4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VAddCounter4bit___024root*>(voidSelf);
    VAddCounter4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VAddCounter4bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VAddCounter4bit___024root__traceRegister(VAddCounter4bit___024root* vlSelf, VerilatedVcd* tracep);

void VAddCounter4bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VAddCounter4bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
