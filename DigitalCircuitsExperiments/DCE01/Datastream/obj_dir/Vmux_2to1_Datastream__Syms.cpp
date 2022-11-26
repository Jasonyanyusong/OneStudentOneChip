// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmux_2to1_Datastream__Syms.h"
#include "Vmux_2to1_Datastream.h"



// FUNCTIONS
Vmux_2to1_Datastream__Syms::Vmux_2to1_Datastream__Syms(Vmux_2to1_Datastream* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
