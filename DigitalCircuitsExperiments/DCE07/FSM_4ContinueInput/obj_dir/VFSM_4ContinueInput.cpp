// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFSM_4ContinueInput.h"
#include "VFSM_4ContinueInput__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VFSM_4ContinueInput::VFSM_4ContinueInput(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VFSM_4ContinueInput__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , in{vlSymsp->TOP.in}
    , reset{vlSymsp->TOP.reset}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
}

VFSM_4ContinueInput::VFSM_4ContinueInput(const char* _vcname__)
    : VFSM_4ContinueInput(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VFSM_4ContinueInput::~VFSM_4ContinueInput() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VFSM_4ContinueInput___024root___eval_initial(VFSM_4ContinueInput___024root* vlSelf);
void VFSM_4ContinueInput___024root___eval_settle(VFSM_4ContinueInput___024root* vlSelf);
void VFSM_4ContinueInput___024root___eval(VFSM_4ContinueInput___024root* vlSelf);
QData VFSM_4ContinueInput___024root___change_request(VFSM_4ContinueInput___024root* vlSelf);
#ifdef VL_DEBUG
void VFSM_4ContinueInput___024root___eval_debug_assertions(VFSM_4ContinueInput___024root* vlSelf);
#endif  // VL_DEBUG
void VFSM_4ContinueInput___024root___final(VFSM_4ContinueInput___024root* vlSelf);

static void _eval_initial_loop(VFSM_4ContinueInput__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VFSM_4ContinueInput___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VFSM_4ContinueInput___024root___eval_settle(&(vlSymsp->TOP));
        VFSM_4ContinueInput___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VFSM_4ContinueInput___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("FSM_4ContinueInput.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VFSM_4ContinueInput___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VFSM_4ContinueInput::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFSM_4ContinueInput::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFSM_4ContinueInput___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VFSM_4ContinueInput___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VFSM_4ContinueInput___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("FSM_4ContinueInput.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VFSM_4ContinueInput___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VFSM_4ContinueInput::final() {
    VFSM_4ContinueInput___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VFSM_4ContinueInput::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VFSM_4ContinueInput::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VFSM_4ContinueInput___024root__traceInitTop(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFSM_4ContinueInput___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFSM_4ContinueInput___024root*>(voidSelf);
    VFSM_4ContinueInput__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VFSM_4ContinueInput___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VFSM_4ContinueInput___024root__traceRegister(VFSM_4ContinueInput___024root* vlSelf, VerilatedVcd* tracep);

void VFSM_4ContinueInput::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VFSM_4ContinueInput___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
