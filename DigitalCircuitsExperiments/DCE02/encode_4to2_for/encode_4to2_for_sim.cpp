#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/encode_4to2_for/obj_dir/Vencode_4to2_for.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencode_4to2_for* top;

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
    top = new Vencode_4to2_for;
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
    printf("This is a 4 to 2 Encoder modeled by for");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b0000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b1000;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b0000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b1000;
    step_and_dump_wave();

    sim_exit();
}