// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSubCounter8bit.h"
#include "VSubCounter8bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSubCounter8bit::VSubCounter8bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VSubCounter8bit__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
}

VSubCounter8bit::VSubCounter8bit(const char* _vcname__)
    : VSubCounter8bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VSubCounter8bit::~VSubCounter8bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VSubCounter8bit___024root___eval_initial(VSubCounter8bit___024root* vlSelf);
void VSubCounter8bit___024root___eval_settle(VSubCounter8bit___024root* vlSelf);
void VSubCounter8bit___024root___eval(VSubCounter8bit___024root* vlSelf);
QData VSubCounter8bit___024root___change_request(VSubCounter8bit___024root* vlSelf);
#ifdef VL_DEBUG
void VSubCounter8bit___024root___eval_debug_assertions(VSubCounter8bit___024root* vlSelf);
#endif  // VL_DEBUG
void VSubCounter8bit___024root___final(VSubCounter8bit___024root* vlSelf);

static void _eval_initial_loop(VSubCounter8bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VSubCounter8bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VSubCounter8bit___024root___eval_settle(&(vlSymsp->TOP));
        VSubCounter8bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VSubCounter8bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SubCounter8bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VSubCounter8bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSubCounter8bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSubCounter8bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSubCounter8bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VSubCounter8bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VSubCounter8bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SubCounter8bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VSubCounter8bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VSubCounter8bit::final() {
    VSubCounter8bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VSubCounter8bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VSubCounter8bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VSubCounter8bit___024root__traceInitTop(VSubCounter8bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSubCounter8bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSubCounter8bit___024root*>(voidSelf);
    VSubCounter8bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSubCounter8bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VSubCounter8bit___024root__traceRegister(VSubCounter8bit___024root* vlSelf, VerilatedVcd* tracep);

void VSubCounter8bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VSubCounter8bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
