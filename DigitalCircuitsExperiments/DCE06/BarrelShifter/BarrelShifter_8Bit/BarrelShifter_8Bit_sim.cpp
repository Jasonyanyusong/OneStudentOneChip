#include "verilated.h"
#include "verilated_vcd_c.h"
#include "./obj_dir/VBarrelShifter_8Bit.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VBarrelShifter_8Bit* top;

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
    top = new VBarrelShifter_8Bit;
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
    printf("This is a 8-Bit Barrel Shifter modeled by Structure");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> lr = 0; top -> al = 0; top -> shamt = 0b000; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b001; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b010; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b011; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b100; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b101; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b110; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 0; top -> shamt = 0b111; top -> din = 0b10110101; step_and_dump_wave();

    top -> lr = 0; top -> al = 1; top -> shamt = 0b000; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b001; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b010; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b011; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b100; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b101; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b110; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 0; top -> al = 1; top -> shamt = 0b111; top -> din = 0b10110101; step_and_dump_wave();

    top -> lr = 1; top -> al = 0; top -> shamt = 0b000; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b001; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b010; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b011; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b100; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b101; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b110; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 0; top -> shamt = 0b111; top -> din = 0b10110101; step_and_dump_wave();

    top -> lr = 1; top -> al = 1; top -> shamt = 0b000; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b001; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b010; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b011; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b100; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b101; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b110; top -> din = 0b10110101; step_and_dump_wave();
    top -> lr = 1; top -> al = 1; top -> shamt = 0b111; top -> din = 0b10110101; step_and_dump_wave();
    
    sim_exit();
}