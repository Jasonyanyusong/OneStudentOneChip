#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/add_1bit_structure/obj_dir/Vadd_1bit_structure.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vadd_1bit_structure* top;

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
    top = new Vadd_1bit_structure;
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
    printf("This is a 1-bit ADDER modeled by structure");
    printf("\n");

    // Simulator Main Parts
    sim_init();


    top -> c_i = 0;
    top -> a_i = 0;
    top -> b_i = 0;
    step_and_dump_wave();

    top -> c_i = 0;
    top -> a_i = 0;
    top -> b_i = 1;
    step_and_dump_wave();

    top -> c_i = 0;
    top -> a_i = 1;
    top -> b_i = 0;
    step_and_dump_wave();

    top -> c_i = 0;
    top -> a_i = 1;
    top -> b_i = 1;
    step_and_dump_wave();

    top -> c_i = 1;
    top -> a_i = 0;
    top -> b_i = 0;
    step_and_dump_wave();

    top -> c_i = 1;
    top -> a_i = 0;
    top -> b_i = 1;
    step_and_dump_wave();

    top -> c_i = 1;
    top -> a_i = 1;
    top -> b_i = 0;
    step_and_dump_wave();

    top -> c_i = 1;
    top -> a_i = 1;
    top -> b_i = 1;
    step_and_dump_wave();

    sim_exit();
}