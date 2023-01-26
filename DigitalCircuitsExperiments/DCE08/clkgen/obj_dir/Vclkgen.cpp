// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vclkgen.h"
#include "Vclkgen__Syms.h"

//============================================================
// Constructors

Vclkgen::Vclkgen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vclkgen__Syms(_vcontextp__, _vcname__, this)}
    , clkin{vlSymsp->TOP.clkin}
    , rst{vlSymsp->TOP.rst}
    , clken{vlSymsp->TOP.clken}
    , clkout{vlSymsp->TOP.clkout}
    , rootp{&(vlSymsp->TOP)}
{
}

Vclkgen::Vclkgen(const char* _vcname__)
    : Vclkgen(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vclkgen::~Vclkgen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vclkgen___024root___eval_initial(Vclkgen___024root* vlSelf);
void Vclkgen___024root___eval_settle(Vclkgen___024root* vlSelf);
void Vclkgen___024root___eval(Vclkgen___024root* vlSelf);
QData Vclkgen___024root___change_request(Vclkgen___024root* vlSelf);
#ifdef VL_DEBUG
void Vclkgen___024root___eval_debug_assertions(Vclkgen___024root* vlSelf);
#endif  // VL_DEBUG
void Vclkgen___024root___final(Vclkgen___024root* vlSelf);

static void _eval_initial_loop(Vclkgen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vclkgen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vclkgen___024root___eval_settle(&(vlSymsp->TOP));
        Vclkgen___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vclkgen___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("clkgen.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vclkgen___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vclkgen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vclkgen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vclkgen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vclkgen___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vclkgen___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("clkgen.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vclkgen___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vclkgen::final() {
    Vclkgen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vclkgen::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vclkgen::name() const {
    return vlSymsp->name();
}
