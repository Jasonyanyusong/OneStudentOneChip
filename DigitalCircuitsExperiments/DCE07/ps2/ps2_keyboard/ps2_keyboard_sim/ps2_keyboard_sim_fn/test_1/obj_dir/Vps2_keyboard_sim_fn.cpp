// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vps2_keyboard_sim_fn.h"
#include "Vps2_keyboard_sim_fn__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vps2_keyboard_sim_fn::Vps2_keyboard_sim_fn(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vps2_keyboard_sim_fn__Syms(_vcontextp__, _vcname__, this)}
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

Vps2_keyboard_sim_fn::Vps2_keyboard_sim_fn(const char* _vcname__)
    : Vps2_keyboard_sim_fn(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vps2_keyboard_sim_fn::~Vps2_keyboard_sim_fn() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vps2_keyboard_sim_fn___024root___eval_initial(Vps2_keyboard_sim_fn___024root* vlSelf);
void Vps2_keyboard_sim_fn___024root___eval_settle(Vps2_keyboard_sim_fn___024root* vlSelf);
void Vps2_keyboard_sim_fn___024root___eval(Vps2_keyboard_sim_fn___024root* vlSelf);
QData Vps2_keyboard_sim_fn___024root___change_request(Vps2_keyboard_sim_fn___024root* vlSelf);
#ifdef VL_DEBUG
void Vps2_keyboard_sim_fn___024root___eval_debug_assertions(Vps2_keyboard_sim_fn___024root* vlSelf);
#endif  // VL_DEBUG
void Vps2_keyboard_sim_fn___024root___final(Vps2_keyboard_sim_fn___024root* vlSelf);

static void _eval_initial_loop(Vps2_keyboard_sim_fn__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vps2_keyboard_sim_fn___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vps2_keyboard_sim_fn___024root___eval_settle(&(vlSymsp->TOP));
        Vps2_keyboard_sim_fn___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vps2_keyboard_sim_fn___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ps2_keyboard_sim_fn.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vps2_keyboard_sim_fn___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vps2_keyboard_sim_fn::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vps2_keyboard_sim_fn::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vps2_keyboard_sim_fn___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vps2_keyboard_sim_fn___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vps2_keyboard_sim_fn___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ps2_keyboard_sim_fn.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vps2_keyboard_sim_fn___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vps2_keyboard_sim_fn::final() {
    Vps2_keyboard_sim_fn___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vps2_keyboard_sim_fn::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vps2_keyboard_sim_fn::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vps2_keyboard_sim_fn___024root__traceInitTop(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vps2_keyboard_sim_fn___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2_keyboard_sim_fn___024root*>(voidSelf);
    Vps2_keyboard_sim_fn__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vps2_keyboard_sim_fn___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vps2_keyboard_sim_fn___024root__traceRegister(Vps2_keyboard_sim_fn___024root* vlSelf, VerilatedVcd* tracep);

void Vps2_keyboard_sim_fn::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vps2_keyboard_sim_fn___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
