//#include <verilated.h>
//#include <verilated_vcd_c.h>
//#include <obj_dir/Vmux_2to1_Datastream.h>

#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/ce/OneStudentOneChip/DigitalCircuitsExperiments/DCE01/mux_2to1_Datastream/obj_dir/Vmux_2to1_Datastream.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux_2to1_Datastream* top;

void step_and_dump_wave()
{
    top -> eval();
    contextp -> timeInc(1);
    tfp -> dump(contextp -> time());
}

void sim_init() // Initilize the simulator
{

}

void sim_exit() // Terminate the simulator
{

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
    sim_exit();
}