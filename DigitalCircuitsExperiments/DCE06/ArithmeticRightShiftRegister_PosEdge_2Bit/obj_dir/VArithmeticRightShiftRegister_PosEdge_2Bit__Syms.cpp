// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VArithmeticRightShiftRegister_PosEdge_2Bit__Syms.h"
#include "VArithmeticRightShiftRegister_PosEdge_2Bit.h"
#include "VArithmeticRightShiftRegister_PosEdge_2Bit___024root.h"

// FUNCTIONS
VArithmeticRightShiftRegister_PosEdge_2Bit__Syms::~VArithmeticRightShiftRegister_PosEdge_2Bit__Syms()
{
}

VArithmeticRightShiftRegister_PosEdge_2Bit__Syms::VArithmeticRightShiftRegister_PosEdge_2Bit__Syms(VerilatedContext* contextp, const char* namep,VArithmeticRightShiftRegister_PosEdge_2Bit* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
