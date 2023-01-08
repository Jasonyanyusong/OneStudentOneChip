// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vregister32.h"
#include "Vregister32__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vregister32::Vregister32(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vregister32__Syms(_vcontextp__, _vcname__, this)}
    , load{vlSymsp->TOP.load}
    , clr{vlSymsp->TOP.clr}
    , clk{vlSymsp->TOP.clk}
    , inp{vlSymsp->TOP.inp}
    , q{vlSymsp->TOP.q}
    , rootp{&(vlSymsp->TOP)}
{
}

Vregister32::Vregister32(const char* _vcname__)
    : Vregister32(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vregister32::~Vregister32() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vregister32___024root___eval_initial(Vregister32___024root* vlSelf);
void Vregister32___024root___eval_settle(Vregister32___024root* vlSelf);
void Vregister32___024root___eval(Vregister32___024root* vlSelf);
QData Vregister32___024root___change_request(Vregister32___024root* vlSelf);
#ifdef VL_DEBUG
void Vregister32___024root___eval_debug_assertions(Vregister32___024root* vlSelf);
#endif  // VL_DEBUG
void Vregister32___024root___final(Vregister32___024root* vlSelf);

static void _eval_initial_loop(Vregister32__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vregister32___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vregister32___024root___eval_settle(&(vlSymsp->TOP));
        Vregister32___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vregister32___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("register32.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vregister32___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vregister32::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister32::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vregister32___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vregister32___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vregister32___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("register32.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vregister32___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vregister32::final() {
    Vregister32___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vregister32::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vregister32::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vregister32___024root__traceInitTop(Vregister32___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vregister32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister32___024root*>(voidSelf);
    Vregister32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vregister32___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vregister32___024root__traceRegister(Vregister32___024root* vlSelf, VerilatedVcd* tracep);

void Vregister32::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vregister32___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
