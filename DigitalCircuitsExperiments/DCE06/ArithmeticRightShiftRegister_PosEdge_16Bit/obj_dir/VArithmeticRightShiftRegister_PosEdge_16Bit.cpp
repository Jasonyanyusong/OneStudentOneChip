// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VArithmeticRightShiftRegister_PosEdge_16Bit.h"
#include "VArithmeticRightShiftRegister_PosEdge_16Bit__Syms.h"

//============================================================
// Constructors

VArithmeticRightShiftRegister_PosEdge_16Bit::VArithmeticRightShiftRegister_PosEdge_16Bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VArithmeticRightShiftRegister_PosEdge_16Bit__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , D{vlSymsp->TOP.D}
    , Q{vlSymsp->TOP.Q}
    , rootp{&(vlSymsp->TOP)}
{
}

VArithmeticRightShiftRegister_PosEdge_16Bit::VArithmeticRightShiftRegister_PosEdge_16Bit(const char* _vcname__)
    : VArithmeticRightShiftRegister_PosEdge_16Bit(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VArithmeticRightShiftRegister_PosEdge_16Bit::~VArithmeticRightShiftRegister_PosEdge_16Bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_initial(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);
void VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_settle(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);
void VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);
QData VArithmeticRightShiftRegister_PosEdge_16Bit___024root___change_request(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);
#ifdef VL_DEBUG
void VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_debug_assertions(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);
#endif  // VL_DEBUG
void VArithmeticRightShiftRegister_PosEdge_16Bit___024root___final(VArithmeticRightShiftRegister_PosEdge_16Bit___024root* vlSelf);

static void _eval_initial_loop(VArithmeticRightShiftRegister_PosEdge_16Bit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_settle(&(vlSymsp->TOP));
        VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VArithmeticRightShiftRegister_PosEdge_16Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ArithmeticRightShiftRegister_PosEdge_16Bit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VArithmeticRightShiftRegister_PosEdge_16Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VArithmeticRightShiftRegister_PosEdge_16Bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VArithmeticRightShiftRegister_PosEdge_16Bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VArithmeticRightShiftRegister_PosEdge_16Bit___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VArithmeticRightShiftRegister_PosEdge_16Bit___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ArithmeticRightShiftRegister_PosEdge_16Bit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VArithmeticRightShiftRegister_PosEdge_16Bit___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VArithmeticRightShiftRegister_PosEdge_16Bit::final() {
    VArithmeticRightShiftRegister_PosEdge_16Bit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VArithmeticRightShiftRegister_PosEdge_16Bit::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VArithmeticRightShiftRegister_PosEdge_16Bit::name() const {
    return vlSymsp->name();
}
