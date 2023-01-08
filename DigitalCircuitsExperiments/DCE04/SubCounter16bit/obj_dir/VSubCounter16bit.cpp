// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSubCounter16bit.h"
#include "VSubCounter16bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSubCounter16bit::VSubCounter16bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VSubCounter16bit__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , en{vlSymsp->TOP.en}
    , out_q{vlSymsp->TOP.out_q}
    , rootp{&(vlSymsp->TOP)}
{
}

VSubCounter16bit::VSubCounter16bit(const char* _vcname__)
    : VSubCounter16bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VSubCounter16bit::~VSubCounter16bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VSubCounter16bit___024root___eval_initial(VSubCounter16bit___024root* vlSelf);
void VSubCounter16bit___024root___eval_settle(VSubCounter16bit___024root* vlSelf);
void VSubCounter16bit___024root___eval(VSubCounter16bit___024root* vlSelf);
QData VSubCounter16bit___024root___change_request(VSubCounter16bit___024root* vlSelf);
#ifdef VL_DEBUG
void VSubCounter16bit___024root___eval_debug_assertions(VSubCounter16bit___024root* vlSelf);
#endif  // VL_DEBUG
void VSubCounter16bit___024root___final(VSubCounter16bit___024root* vlSelf);

static void _eval_initial_loop(VSubCounter16bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VSubCounter16bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VSubCounter16bit___024root___eval_settle(&(vlSymsp->TOP));
        VSubCounter16bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VSubCounter16bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SubCounter16bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VSubCounter16bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSubCounter16bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSubCounter16bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSubCounter16bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VSubCounter16bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VSubCounter16bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SubCounter16bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VSubCounter16bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VSubCounter16bit::final() {
    VSubCounter16bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VSubCounter16bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VSubCounter16bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VSubCounter16bit___024root__traceInitTop(VSubCounter16bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSubCounter16bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSubCounter16bit___024root*>(voidSelf);
    VSubCounter16bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSubCounter16bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VSubCounter16bit___024root__traceRegister(VSubCounter16bit___024root* vlSelf, VerilatedVcd* tracep);

void VSubCounter16bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VSubCounter16bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
