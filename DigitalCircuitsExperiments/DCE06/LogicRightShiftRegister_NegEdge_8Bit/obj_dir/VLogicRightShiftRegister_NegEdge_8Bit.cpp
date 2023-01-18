// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLogicRightShiftRegister_NegEdge_8Bit.h"
#include "VLogicRightShiftRegister_NegEdge_8Bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VLogicRightShiftRegister_NegEdge_8Bit::VLogicRightShiftRegister_NegEdge_8Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VLogicRightShiftRegister_NegEdge_8Bit__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , D{vlSymsp->TOP.D}
    , Q{vlSymsp->TOP.Q}
    , rootp{&(vlSymsp->TOP)}
{
}

VLogicRightShiftRegister_NegEdge_8Bit::VLogicRightShiftRegister_NegEdge_8Bit(const char* _vcname__)
    : VLogicRightShiftRegister_NegEdge_8Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VLogicRightShiftRegister_NegEdge_8Bit::~VLogicRightShiftRegister_NegEdge_8Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_initial(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);
void VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_settle(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);
void VLogicRightShiftRegister_NegEdge_8Bit___024root___eval(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);
QData VLogicRightShiftRegister_NegEdge_8Bit___024root___change_request(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_debug_assertions(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VLogicRightShiftRegister_NegEdge_8Bit___024root___final(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf);

static void _eval_initial_loop(VLogicRightShiftRegister_NegEdge_8Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_settle(&(vlSymsp->TOP));
        VLogicRightShiftRegister_NegEdge_8Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicRightShiftRegister_NegEdge_8Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicRightShiftRegister_NegEdge_8Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicRightShiftRegister_NegEdge_8Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLogicRightShiftRegister_NegEdge_8Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLogicRightShiftRegister_NegEdge_8Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLogicRightShiftRegister_NegEdge_8Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VLogicRightShiftRegister_NegEdge_8Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicRightShiftRegister_NegEdge_8Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicRightShiftRegister_NegEdge_8Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicRightShiftRegister_NegEdge_8Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VLogicRightShiftRegister_NegEdge_8Bit::final() {
    VLogicRightShiftRegister_NegEdge_8Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VLogicRightShiftRegister_NegEdge_8Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VLogicRightShiftRegister_NegEdge_8Bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VLogicRightShiftRegister_NegEdge_8Bit___024root__traceInitTop(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VLogicRightShiftRegister_NegEdge_8Bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLogicRightShiftRegister_NegEdge_8Bit___024root*>(voidSelf);
    VLogicRightShiftRegister_NegEdge_8Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VLogicRightShiftRegister_NegEdge_8Bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VLogicRightShiftRegister_NegEdge_8Bit___024root__traceRegister(VLogicRightShiftRegister_NegEdge_8Bit___024root* vlSelf, VerilatedVcd* tracep);

void VLogicRightShiftRegister_NegEdge_8Bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VLogicRightShiftRegister_NegEdge_8Bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
