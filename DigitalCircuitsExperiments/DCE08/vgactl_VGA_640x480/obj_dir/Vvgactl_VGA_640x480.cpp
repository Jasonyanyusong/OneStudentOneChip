// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvgactl_VGA_640x480.h"
#include "Vvgactl_VGA_640x480__Syms.h"

//============================================================
// Constructors

Vvgactl_VGA_640x480::Vvgactl_VGA_640x480(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vvgactl_VGA_640x480__Syms(_vcontextp__, _vcname__, this)}
    , pclk{vlSymsp->TOP.pclk}
    , reset{vlSymsp->TOP.reset}
    , vga_data{vlSymsp->TOP.vga_data}
    , h_addr{vlSymsp->TOP.h_addr}
    , v_addr{vlSymsp->TOP.v_addr}
    , hsync{vlSymsp->TOP.hsync}
    , vsync{vlSymsp->TOP.vsync}
    , valid{vlSymsp->TOP.valid}
    , vga_r{vlSymsp->TOP.vga_r}
    , vga_g{vlSymsp->TOP.vga_g}
    , vga_b{vlSymsp->TOP.vga_b}
    , rootp{&(vlSymsp->TOP)}
{
}

Vvgactl_VGA_640x480::Vvgactl_VGA_640x480(const char* _vcname__)
    : Vvgactl_VGA_640x480(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vvgactl_VGA_640x480::~Vvgactl_VGA_640x480() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvgactl_VGA_640x480___024root___eval_initial(Vvgactl_VGA_640x480___024root* vlSelf);
void Vvgactl_VGA_640x480___024root___eval_settle(Vvgactl_VGA_640x480___024root* vlSelf);
void Vvgactl_VGA_640x480___024root___eval(Vvgactl_VGA_640x480___024root* vlSelf);
QData Vvgactl_VGA_640x480___024root___change_request(Vvgactl_VGA_640x480___024root* vlSelf);
#ifdef VL_DEBUG
void Vvgactl_VGA_640x480___024root___eval_debug_assertions(Vvgactl_VGA_640x480___024root* vlSelf);
#endif  // VL_DEBUG
void Vvgactl_VGA_640x480___024root___final(Vvgactl_VGA_640x480___024root* vlSelf);

static void _eval_initial_loop(Vvgactl_VGA_640x480__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvgactl_VGA_640x480___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvgactl_VGA_640x480___024root___eval_settle(&(vlSymsp->TOP));
        Vvgactl_VGA_640x480___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vvgactl_VGA_640x480___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vgactl_VGA_640x480.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vvgactl_VGA_640x480___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vvgactl_VGA_640x480::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvgactl_VGA_640x480::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvgactl_VGA_640x480___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvgactl_VGA_640x480___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vvgactl_VGA_640x480___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vgactl_VGA_640x480.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vvgactl_VGA_640x480___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vvgactl_VGA_640x480::final() {
    Vvgactl_VGA_640x480___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vvgactl_VGA_640x480::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvgactl_VGA_640x480::name() const {
    return vlSymsp->name();
}
