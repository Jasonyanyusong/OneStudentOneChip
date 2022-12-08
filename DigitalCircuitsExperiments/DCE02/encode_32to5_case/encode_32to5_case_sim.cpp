#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/encode_32to5_case/obj_dir/Vencode_32to5_case.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencode_32to5_case* top;

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
    top = new Vencode_32to5_case;
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
    printf("This is a 32 to 5 Encoder modeled by case");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000000001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000000010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000000100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000001000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000010000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000000100000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000001000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000010000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000000100000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000001000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000010000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000000100000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000001000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000010000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000000100000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000001000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000010000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000000100000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000001000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000010000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000000100000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000001000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000010000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000000100000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000001000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000010000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00000100000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00001000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00010000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00100000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01000000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10000000000000000000000000000000;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000000001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000000010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000000100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000001000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000010000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000000100000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000001000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000010000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000000100000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000001000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000010000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000000100000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000001000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000010000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000000100000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000001000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000010000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000000100000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000001000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000010000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000000100000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000001000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000010000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000000100000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000001000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000010000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00000100000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00001000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00010000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00100000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01000000000000000000000000000000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10000000000000000000000000000000;
    step_and_dump_wave();

    sim_exit();
}