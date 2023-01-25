// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vps2_keyboard.h"
#include "Vps2_keyboard__Syms.h"

//============================================================
// Constructors

Vps2_keyboard::Vps2_keyboard(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vps2_keyboard__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , clrn{vlSymsp->TOP.clrn}
    , ps2_clk{vlSymsp->TOP.ps2_clk}
    , ps2_data{vlSymsp->TOP.ps2_data}
    , nextdata_n{vlSymsp->TOP.nextdata_n}
    , data{vlSymsp->TOP.data}
    , ready{vlSymsp->TOP.ready}
    , overflow{vlSymsp->TOP.overflow}
    , rootp{&(vlSymsp->TOP)}
{
}

Vps2_keyboard::Vps2_keyboard(const char* _vcname__)
    : Vps2_keyboard(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vps2_keyboard::~Vps2_keyboard() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vps2_keyboard___024root___eval_initial(Vps2_keyboard___024root* vlSelf);
void Vps2_keyboard___024root___eval_settle(Vps2_keyboard___024root* vlSelf);
void Vps2_keyboard___024root___eval(Vps2_keyboard___024root* vlSelf);
QData Vps2_keyboard___024root___change_request(Vps2_keyboard___024root* vlSelf);
#ifdef VL_DEBUG
void Vps2_keyboard___024root___eval_debug_assertions(Vps2_keyboard___024root* vlSelf);
#endif  // VL_DEBUG
void Vps2_keyboard___024root___final(Vps2_keyboard___024root* vlSelf);

static void _eval_initial_loop(Vps2_keyboard__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vps2_keyboard___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vps2_keyboard___024root___eval_settle(&(vlSymsp->TOP));
        Vps2_keyboard___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vps2_keyboard___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ps2_keyboard.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vps2_keyboard___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vps2_keyboard::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vps2_keyboard::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vps2_keyboard___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vps2_keyboard___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vps2_keyboard___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ps2_keyboard.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vps2_keyboard___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vps2_keyboard::final() {
    Vps2_keyboard___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vps2_keyboard::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vps2_keyboard::name() const {
    return vlSymsp->name();
}
