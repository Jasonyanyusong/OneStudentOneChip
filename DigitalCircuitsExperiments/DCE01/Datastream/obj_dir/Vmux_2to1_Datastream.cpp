// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux_2to1_Datastream.h"
#include "Vmux_2to1_Datastream__Syms.h"

//============================================================
// Constructors

Vmux_2to1_Datastream::Vmux_2to1_Datastream(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vmux_2to1_Datastream__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vmux_2to1_Datastream::Vmux_2to1_Datastream(const char* _vcname__)
    : Vmux_2to1_Datastream(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vmux_2to1_Datastream::~Vmux_2to1_Datastream() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmux_2to1_Datastream___024root___eval_initial(Vmux_2to1_Datastream___024root* vlSelf);
void Vmux_2to1_Datastream___024root___eval_settle(Vmux_2to1_Datastream___024root* vlSelf);
void Vmux_2to1_Datastream___024root___eval(Vmux_2to1_Datastream___024root* vlSelf);
QData Vmux_2to1_Datastream___024root___change_request(Vmux_2to1_Datastream___024root* vlSelf);
#ifdef VL_DEBUG
void Vmux_2to1_Datastream___024root___eval_debug_assertions(Vmux_2to1_Datastream___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux_2to1_Datastream___024root___final(Vmux_2to1_Datastream___024root* vlSelf);

static void _eval_initial_loop(Vmux_2to1_Datastream__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmux_2to1_Datastream___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmux_2to1_Datastream___024root___eval_settle(&(vlSymsp->TOP));
        Vmux_2to1_Datastream___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux_2to1_Datastream___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mux_2to1_Datastream.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux_2to1_Datastream___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmux_2to1_Datastream::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux_2to1_Datastream::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux_2to1_Datastream___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmux_2to1_Datastream___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux_2to1_Datastream___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mux_2to1_Datastream.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux_2to1_Datastream___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vmux_2to1_Datastream::final() {
    Vmux_2to1_Datastream___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vmux_2to1_Datastream::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vmux_2to1_Datastream::name() const {
    return vlSymsp->name();
}
