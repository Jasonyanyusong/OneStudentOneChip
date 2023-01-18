// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLogicLeftShiftRegister_NegEdge_2Bit.h"
#include "VLogicLeftShiftRegister_NegEdge_2Bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VLogicLeftShiftRegister_NegEdge_2Bit::VLogicLeftShiftRegister_NegEdge_2Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VLogicLeftShiftRegister_NegEdge_2Bit__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , D{vlSymsp->TOP.D}
    , Q{vlSymsp->TOP.Q}
    , rootp{&(vlSymsp->TOP)}
{
}

VLogicLeftShiftRegister_NegEdge_2Bit::VLogicLeftShiftRegister_NegEdge_2Bit(const char* _vcname__)
    : VLogicLeftShiftRegister_NegEdge_2Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VLogicLeftShiftRegister_NegEdge_2Bit::~VLogicLeftShiftRegister_NegEdge_2Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_initial(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);
void VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_settle(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);
void VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);
QData VLogicLeftShiftRegister_NegEdge_2Bit___024root___change_request(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_debug_assertions(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VLogicLeftShiftRegister_NegEdge_2Bit___024root___final(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf);

static void _eval_initial_loop(VLogicLeftShiftRegister_NegEdge_2Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_settle(&(vlSymsp->TOP));
        VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicLeftShiftRegister_NegEdge_2Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicLeftShiftRegister_NegEdge_2Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicLeftShiftRegister_NegEdge_2Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLogicLeftShiftRegister_NegEdge_2Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLogicLeftShiftRegister_NegEdge_2Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VLogicLeftShiftRegister_NegEdge_2Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicLeftShiftRegister_NegEdge_2Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicLeftShiftRegister_NegEdge_2Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicLeftShiftRegister_NegEdge_2Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VLogicLeftShiftRegister_NegEdge_2Bit::final() {
    VLogicLeftShiftRegister_NegEdge_2Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VLogicLeftShiftRegister_NegEdge_2Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VLogicLeftShiftRegister_NegEdge_2Bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VLogicLeftShiftRegister_NegEdge_2Bit___024root__traceInitTop(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VLogicLeftShiftRegister_NegEdge_2Bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLogicLeftShiftRegister_NegEdge_2Bit___024root*>(voidSelf);
    VLogicLeftShiftRegister_NegEdge_2Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VLogicLeftShiftRegister_NegEdge_2Bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VLogicLeftShiftRegister_NegEdge_2Bit___024root__traceRegister(VLogicLeftShiftRegister_NegEdge_2Bit___024root* vlSelf, VerilatedVcd* tracep);

void VLogicLeftShiftRegister_NegEdge_2Bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VLogicLeftShiftRegister_NegEdge_2Bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
