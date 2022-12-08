#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/decode_2to4_for/obj_dir/Vdecode_2to4_for.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vdecode_2to4_for* top;

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
    top = new Vdecode_2to4_for;
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
    printf("This is a 2 to 4 Decoder modeled by for");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b00;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b01;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b10;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b11;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b00;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b01;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b10;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b11;
    step_and_dump_wave();

    sim_exit();
}