// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLogicRightShiftRegister_PosEdge_32Bit.h"
#include "VLogicRightShiftRegister_PosEdge_32Bit__Syms.h"

//============================================================
// Constructors

VLogicRightShiftRegister_PosEdge_32Bit::VLogicRightShiftRegister_PosEdge_32Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VLogicRightShiftRegister_PosEdge_32Bit__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , D{vlSymsp->TOP.D}
    , Q{vlSymsp->TOP.Q}
    , rootp{&(vlSymsp->TOP)}
{
}

VLogicRightShiftRegister_PosEdge_32Bit::VLogicRightShiftRegister_PosEdge_32Bit(const char* _vcname__)
    : VLogicRightShiftRegister_PosEdge_32Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VLogicRightShiftRegister_PosEdge_32Bit::~VLogicRightShiftRegister_PosEdge_32Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_initial(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);
void VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_settle(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);
void VLogicRightShiftRegister_PosEdge_32Bit___024root___eval(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);
QData VLogicRightShiftRegister_PosEdge_32Bit___024root___change_request(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_debug_assertions(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VLogicRightShiftRegister_PosEdge_32Bit___024root___final(VLogicRightShiftRegister_PosEdge_32Bit___024root* vlSelf);

static void _eval_initial_loop(VLogicRightShiftRegister_PosEdge_32Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_settle(&(vlSymsp->TOP));
        VLogicRightShiftRegister_PosEdge_32Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicRightShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicRightShiftRegister_PosEdge_32Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicRightShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLogicRightShiftRegister_PosEdge_32Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLogicRightShiftRegister_PosEdge_32Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLogicRightShiftRegister_PosEdge_32Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VLogicRightShiftRegister_PosEdge_32Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VLogicRightShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("LogicRightShiftRegister_PosEdge_32Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VLogicRightShiftRegister_PosEdge_32Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VLogicRightShiftRegister_PosEdge_32Bit::final() {
    VLogicRightShiftRegister_PosEdge_32Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VLogicRightShiftRegister_PosEdge_32Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VLogicRightShiftRegister_PosEdge_32Bit::name() const {
    return vlSymsp->name();
}
