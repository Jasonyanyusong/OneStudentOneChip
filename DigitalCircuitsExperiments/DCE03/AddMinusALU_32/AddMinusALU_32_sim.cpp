#include "verilated.h"
#include "verilated_vcd_c.h"
#include "./obj_dir/VAddMinusALU_32.h"
#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VAddMinusALU_32* top;

void step_and_dump_wave()
{
    top -> eval();
    contextp -> timeInc(1);
    tfp -> dump(contextp -> time());
}

void sim_init() // Initilize the simulator
{
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VAddMinusALU_32;
    contextp -> traceEverOn(true);
    top -> trace (tfp, 0);
    tfp -> open("dump.vcd");
}

void sim_exit() // Terminate the simulator
{
    step_and_dump_wave();
    tfp -> close();
}

int main()
{
    // Print the Experiment Informations
    printf("Verilator Generated File simulator");
    printf("\n");
    printf("This is a 32-bit Add-Minus ALU");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    // 1 Add, No Carry
    top -> sub_add = 0; top -> a = 1000000000; top -> b = 1000000000; step_and_dump_wave();
    // 2 Add, Carry
    top -> sub_add = 0; top -> a = 2000000000; top -> b = 2000000000; step_and_dump_wave();
    // 3 Add, Zero
    top -> sub_add = 0; top -> a = 0; top -> b = 0; step_and_dump_wave();
    // 4 Sub, No Overflow
    top -> sub_add = 1; top -> a = 2000050000; top -> b = 1000000000; step_and_dump_wave();
    // 5 Sub, Overflow
    top -> sub_add = 1; top -> a = 1000000000; top -> b = 2000000000; step_and_dump_wave();
    // 6 Sub, Zero
    top -> sub_add = 1; top -> a = 0; top -> b = 0; step_and_dump_wave();
    sim_exit();
}