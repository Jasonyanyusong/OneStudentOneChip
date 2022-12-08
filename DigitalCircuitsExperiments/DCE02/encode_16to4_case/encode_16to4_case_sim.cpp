#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/encode_16to4_case/obj_dir/Vencode_16to4_case.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencode_16to4_case* top;

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
    top = new Vencode_16to4_case;
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
    printf("This is a 16 to 4 Encoder modeled by case");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b0000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000000001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000000010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000000100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000001000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000010000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000000100000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000001000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000010000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000000100000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000001000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000010000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0000100000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0001000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0010000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b0100000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b1000000000000000;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b0000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000000001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000000010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000000100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000001000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000010000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000000100000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000001000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000010000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000000100000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000001000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000010000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0000100000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0001000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0010000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b0100000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b1000000000000000;
    step_and_dump_wave();

    sim_exit();
}