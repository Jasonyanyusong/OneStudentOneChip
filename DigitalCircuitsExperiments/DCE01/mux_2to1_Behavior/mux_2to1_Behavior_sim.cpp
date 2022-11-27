//#include <verilated.h>
//#include <verilated_vcd_c.h>
//#include <obj_dir/Vmux_2to1_Datastream.h>

#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/ce/OneStudentOneChip/DigitalCircuitsExperiments/DCE01/mux_2to1_Behavior/obj_dir/Vmux_2to1_Behavior.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux_2to1_Behavior* top;

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
    top = new Vmux_2to1_Behavior;
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
    printf("This is a Mutiplexer modeled by Datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    // Condition sab
    top -> s = 0;
    top -> a = 0;
    top -> b = 0;
    step_and_dump_wave();

    // Condition saB
    top -> s = 0;
    top -> a = 0;
    top -> b = 1;
    step_and_dump_wave();

    // Condition sAb
    top -> s = 0;
    top -> a = 1;
    top -> b = 0;
    step_and_dump_wave();

    // Condition sAB
    top -> s = 0;
    top -> a = 1;
    top -> b = 1;
    step_and_dump_wave();

    // Condition Sab
    top -> s = 1;
    top -> a = 0;
    top -> b = 0;
    step_and_dump_wave();

    // Condition SaB
    top -> s = 1;
    top -> a = 0;
    top -> b = 1;
    step_and_dump_wave();

    // Condition SAb
    top -> s = 1;
    top -> a = 1;
    top -> b = 0;
    step_and_dump_wave();

    // Condition SAB
    top -> s = 1;
    top -> a = 1;
    top -> b = 1;
    step_and_dump_wave();

    sim_exit();
}