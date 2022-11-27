// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux_2to1_Behavior.h"
#include "Vmux_2to1_Behavior__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux_2to1_Behavior::Vmux_2to1_Behavior(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vmux_2to1_Behavior__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vmux_2to1_Behavior::Vmux_2to1_Behavior(const char* _vcname__)
    : Vmux_2to1_Behavior(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vmux_2to1_Behavior::~Vmux_2to1_Behavior() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmux_2to1_Behavior___024root___eval_initial(Vmux_2to1_Behavior___024root* vlSelf);
void Vmux_2to1_Behavior___024root___eval_settle(Vmux_2to1_Behavior___024root* vlSelf);
void Vmux_2to1_Behavior___024root___eval(Vmux_2to1_Behavior___024root* vlSelf);
QData Vmux_2to1_Behavior___024root___change_request(Vmux_2to1_Behavior___024root* vlSelf);
#ifdef VL_DEBUG
void Vmux_2to1_Behavior___024root___eval_debug_assertions(Vmux_2to1_Behavior___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux_2to1_Behavior___024root___final(Vmux_2to1_Behavior___024root* vlSelf);

static void _eval_initial_loop(Vmux_2to1_Behavior__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmux_2to1_Behavior___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmux_2to1_Behavior___024root___eval_settle(&(vlSymsp->TOP));
        Vmux_2to1_Behavior___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux_2to1_Behavior___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mux_2to1_Behavior.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux_2to1_Behavior___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmux_2to1_Behavior::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux_2to1_Behavior::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux_2to1_Behavior___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmux_2to1_Behavior___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux_2to1_Behavior___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mux_2to1_Behavior.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux_2to1_Behavior___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vmux_2to1_Behavior::final() {
    Vmux_2to1_Behavior___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vmux_2to1_Behavior::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vmux_2to1_Behavior::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vmux_2to1_Behavior___024root__traceInitTop(Vmux_2to1_Behavior___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux_2to1_Behavior___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux_2to1_Behavior___024root*>(voidSelf);
    Vmux_2to1_Behavior__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmux_2to1_Behavior___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vmux_2to1_Behavior___024root__traceRegister(Vmux_2to1_Behavior___024root* vlSelf, VerilatedVcd* tracep);

void Vmux_2to1_Behavior::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vmux_2to1_Behavior___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
