#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/encode_8to3_case/obj_dir/Vencode_8to3_case.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencode_8to3_case* top;

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
    top = new Vencode_8to3_case;
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
    printf("This is a 8 to 3 Encoder modeled by case");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b00000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00001000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00010000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00100000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10000000;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b00000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00001000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00010000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00100000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10000000;
    step_and_dump_wave();

    sim_exit();
}