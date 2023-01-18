// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLogicLeftShiftRegister_PosEdge_32Bit.h"
#include "VLogicLeftShiftRegister_PosEdge_32Bit__Syms.h"

//============================================================
// Constructors

VLogicLeftShiftRegister_PosEdge_32Bit::VLogicLeftShiftRegister_PosEdge_32Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VLogicLeftShiftRegister_PosEdge_32Bit__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , D{vlSymsp->TOP.D}
    , Q{vlSymsp->TOP.Q}
    , rootp{&(vlSymsp->TOP)}
{
}

VLogicLeftShiftRegister_PosEdge_32Bit::VLogicLeftShiftRegister_PosEdge_32Bit(const char* _vcname__)
    : VLogicLeftShiftRegister_PosEdge_32Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VLogicLeftShiftRegister_PosEdge_32Bit::~VLogicLeftShiftRegister_PosEdge_32Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_initial(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);
void VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_settle(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);
void VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);
QData VLogicLeftShiftRegister_PosEdge_32Bit___024root___change_request(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_debug_assertions(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VLogicLeftShiftRegister_PosEdge_32Bit___024root___final(VLogicLeftShiftRegister_PosEdge_32Bit___024root* vlSelf);

static void _eval_initial_loop(VLogicLeftShiftRegister_PosEdge_32Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_settle(&(vlSymsp->TOP));
        VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicLeftShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicLeftShiftRegister_PosEdge_32Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicLeftShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLogicLeftShiftRegister_PosEdge_32Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLogicLeftShiftRegister_PosEdge_32Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VLogicLeftShiftRegister_PosEdge_32Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicLeftShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicLeftShiftRegister_PosEdge_32Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicLeftShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VLogicLeftShiftRegister_PosEdge_32Bit::final() {
    VLogicLeftShiftRegister_PosEdge_32Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VLogicLeftShiftRegister_PosEdge_32Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VLogicLeftShiftRegister_PosEdge_32Bit::name() const {
    return vlSymsp->name();
}
