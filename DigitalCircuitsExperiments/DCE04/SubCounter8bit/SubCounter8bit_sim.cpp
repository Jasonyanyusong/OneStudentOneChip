#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE04/SubCounter8bit/obj_dir/VSubCounter8bit.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VSubCounter8bit* top;

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
    top = new VSubCounter8bit;
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
    printf("This is a 8bit Sub-Counter modeled by datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();
    top -> en = 1; top -> clk = 0; step_and_dump_wave();
    top -> en = 1; top -> clk = 1; step_and_dump_wave();

    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();
    top -> en = 0; top -> clk = 0; step_and_dump_wave();
    top -> en = 0; top -> clk = 1; step_and_dump_wave();

    sim_exit();
}
