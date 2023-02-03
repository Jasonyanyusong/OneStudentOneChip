// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU4Bit_All.h"
#include "VALU4Bit_All__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VALU4Bit_All::VALU4Bit_All(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VALU4Bit_All__Syms(_vcontextp__, _vcname__, this)}
    , sel{vlSymsp->TOP.sel}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , result{vlSymsp->TOP.result}
    , overflow{vlSymsp->TOP.overflow}
    , carry{vlSymsp->TOP.carry}
    , zero{vlSymsp->TOP.zero}
    , rootp{&(vlSymsp->TOP)}
{
}

VALU4Bit_All::VALU4Bit_All(const char* _vcname__)
    : VALU4Bit_All(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VALU4Bit_All::~VALU4Bit_All() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VALU4Bit_All___024root___eval_initial(VALU4Bit_All___024root* vlSelf);
void VALU4Bit_All___024root___eval_settle(VALU4Bit_All___024root* vlSelf);
void VALU4Bit_All___024root___eval(VALU4Bit_All___024root* vlSelf);
QData VALU4Bit_All___024root___change_request(VALU4Bit_All___024root* vlSelf);
#ifdef VL_DEBUG
void VALU4Bit_All___024root___eval_debug_assertions(VALU4Bit_All___024root* vlSelf);
#endif  // VL_DEBUG
void VALU4Bit_All___024root___final(VALU4Bit_All___024root* vlSelf);

static void _eval_initial_loop(VALU4Bit_All__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VALU4Bit_All___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VALU4Bit_All___024root___eval_settle(&(vlSymsp->TOP));
        VALU4Bit_All___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VALU4Bit_All___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ALU4Bit_All.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VALU4Bit_All___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU4Bit_All::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU4Bit_All::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VALU4Bit_All___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VALU4Bit_All___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VALU4Bit_All___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ALU4Bit_All.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VALU4Bit_All___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VALU4Bit_All::final() {
    VALU4Bit_All___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VALU4Bit_All::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VALU4Bit_All::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VALU4Bit_All___024root__traceInitTop(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU4Bit_All___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU4Bit_All___024root*>(voidSelf);
    VALU4Bit_All__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VALU4Bit_All___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VALU4Bit_All___024root__traceRegister(VALU4Bit_All___024root* vlSelf, VerilatedVcd* tracep);

void VALU4Bit_All::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VALU4Bit_All___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
