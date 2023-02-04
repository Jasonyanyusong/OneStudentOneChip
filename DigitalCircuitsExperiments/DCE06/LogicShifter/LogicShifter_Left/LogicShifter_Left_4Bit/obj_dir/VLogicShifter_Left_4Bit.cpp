// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLogicShifter_Left_4Bit.h"
#include "VLogicShifter_Left_4Bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VLogicShifter_Left_4Bit::VLogicShifter_Left_4Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VLogicShifter_Left_4Bit__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , clr{vlSymsp->TOP.clr}
    , load{vlSymsp->TOP.load}
    , inp{vlSymsp->TOP.inp}
    , outp{vlSymsp->TOP.outp}
    , rootp{&(vlSymsp->TOP)}
{
}

VLogicShifter_Left_4Bit::VLogicShifter_Left_4Bit(const char* _vcname__)
    : VLogicShifter_Left_4Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VLogicShifter_Left_4Bit::~VLogicShifter_Left_4Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VLogicShifter_Left_4Bit___024root___eval_initial(VLogicShifter_Left_4Bit___024root* vlSelf);
void VLogicShifter_Left_4Bit___024root___eval_settle(VLogicShifter_Left_4Bit___024root* vlSelf);
void VLogicShifter_Left_4Bit___024root___eval(VLogicShifter_Left_4Bit___024root* vlSelf);
QData VLogicShifter_Left_4Bit___024root___change_request(VLogicShifter_Left_4Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VLogicShifter_Left_4Bit___024root___eval_debug_assertions(VLogicShifter_Left_4Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VLogicShifter_Left_4Bit___024root___final(VLogicShifter_Left_4Bit___024root* vlSelf);

static void _eval_initial_loop(VLogicShifter_Left_4Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VLogicShifter_Left_4Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VLogicShifter_Left_4Bit___024root___eval_settle(&(vlSymsp->TOP));
        VLogicShifter_Left_4Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicShifter_Left_4Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicShifter_Left_4Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicShifter_Left_4Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLogicShifter_Left_4Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLogicShifter_Left_4Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLogicShifter_Left_4Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VLogicShifter_Left_4Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicShifter_Left_4Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicShifter_Left_4Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicShifter_Left_4Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VLogicShifter_Left_4Bit::final() {
    VLogicShifter_Left_4Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VLogicShifter_Left_4Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VLogicShifter_Left_4Bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VLogicShifter_Left_4Bit___024root__traceInitTop(VLogicShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VLogicShifter_Left_4Bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLogicShifter_Left_4Bit___024root*>(voidSelf);
    VLogicShifter_Left_4Bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VLogicShifter_Left_4Bit___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VLogicShifter_Left_4Bit___024root__traceRegister(VLogicShifter_Left_4Bit___024root* vlSelf, VerilatedVcd* tracep);

void VLogicShifter_Left_4Bit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VLogicShifter_Left_4Bit___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
