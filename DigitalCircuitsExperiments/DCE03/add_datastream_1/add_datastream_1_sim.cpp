#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/add_datastream_1/obj_dir/Vadd_datastream_1.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vadd_datastream_1* top;

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
    top = new Vadd_datastream_1;
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
    printf("This is a 1-bit ADDER modeled by datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> in_x = 0b0; top -> in_y = 0b0; step_and_dump_wave();
    top -> in_x = 0b0; top -> in_y = 0b1; step_and_dump_wave();
    top -> in_x = 0b1; top -> in_y = 0b0; step_and_dump_wave();
    top -> in_x = 0b1; top -> in_y = 0b1; step_and_dump_wave();

    sim_exit();
}