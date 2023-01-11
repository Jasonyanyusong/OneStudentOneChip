// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VBarrelShifter8_Structure.h"
#include "VBarrelShifter8_Structure__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VBarrelShifter8_Structure::VBarrelShifter8_Structure(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VBarrelShifter8_Structure__Syms(_vcontextp__, _vcname__, this)}
    , din{vlSymsp->TOP.din}
    , shamt{vlSymsp->TOP.shamt}
    , lr{vlSymsp->TOP.lr}
    , al{vlSymsp->TOP.al}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
}

VBarrelShifter8_Structure::VBarrelShifter8_Structure(const char* _vcname__)
    : VBarrelShifter8_Structure(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VBarrelShifter8_Structure::~VBarrelShifter8_Structure() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VBarrelShifter8_Structure___024root___eval_initial(VBarrelShifter8_Structure___024root* vlSelf);
void VBarrelShifter8_Structure___024root___eval_settle(VBarrelShifter8_Structure___024root* vlSelf);
void VBarrelShifter8_Structure___024root___eval(VBarrelShifter8_Structure___024root* vlSelf);
QData VBarrelShifter8_Structure___024root___change_request(VBarrelShifter8_Structure___024root* vlSelf);
#ifdef VL_DEBUG
void VBarrelShifter8_Structure___024root___eval_debug_assertions(VBarrelShifter8_Structure___024root* vlSelf);
#endif  // VL_DEBUG
void VBarrelShifter8_Structure___024root___final(VBarrelShifter8_Structure___024root* vlSelf);

static void _eval_initial_loop(VBarrelShifter8_Structure__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VBarrelShifter8_Structure___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VBarrelShifter8_Structure___024root___eval_settle(&(vlSymsp->TOP));
        VBarrelShifter8_Structure___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VBarrelShifter8_Structure___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("BarrelShifter8_Structure.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VBarrelShifter8_Structure___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VBarrelShifter8_Structure::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VBarrelShifter8_Structure::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VBarrelShifter8_Structure___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VBarrelShifter8_Structure___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VBarrelShifter8_Structure___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("BarrelShifter8_Structure.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VBarrelShifter8_Structure___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VBarrelShifter8_Structure::final() {
    VBarrelShifter8_Structure___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VBarrelShifter8_Structure::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VBarrelShifter8_Structure::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VBarrelShifter8_Structure___024root__traceInitTop(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VBarrelShifter8_Structure___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VBarrelShifter8_Structure___024root*>(voidSelf);
    VBarrelShifter8_Structure__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VBarrelShifter8_Structure___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VBarrelShifter8_Structure___024root__traceRegister(VBarrelShifter8_Structure___024root* vlSelf, VerilatedVcd* tracep);

void VBarrelShifter8_Structure::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VBarrelShifter8_Structure___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
