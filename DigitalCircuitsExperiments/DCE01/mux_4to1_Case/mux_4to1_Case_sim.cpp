//#include <verilated.h>
//#include <verilated_vcd_c.h>
//#include <obj_dir/Vmux_4to1_Case.h>

#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/ce/OneStudentOneChip/DigitalCircuitsExperiments/DCE01/mux_4to1_Case/obj_dir/Vmux_4to1_Case.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux_4to1_Case* top;

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
    top = new Vmux_4to1_Case;
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
    printf("This is a Mutiplexer modeled by Case");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> s = 0b00;
    top -> a = 0b0001;
    step_and_dump_wave();

    top -> s = 0;
    top -> a = 0;
    step_and_dump_wave();

    top -> s = 0;
    top -> a = 1;
    step_and_dump_wave();

    top -> s = 0;
    top -> a = 1;
    step_and_dump_wave();

    top -> s = 1;
    top -> a = 0;
    step_and_dump_wave();

    top -> s = 1;
    top -> a = 0;
    step_and_dump_wave();

    top -> s = 1;
    top -> a = 1;
    step_and_dump_wave();

    top -> s = 1;
    top -> a = 1;
    step_and_dump_wave();

    sim_exit();
}