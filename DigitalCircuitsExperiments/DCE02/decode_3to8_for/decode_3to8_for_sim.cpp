#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/decode_3to8_for/obj_dir/Vdecode_3to8_for.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vdecode_3to8_for* top;

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
    top = new Vdecode_3to8_for;
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
    printf("This is a 3 to 8 Decoder modeled by for");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b0000;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b001;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b010;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b011;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b100;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b101;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b110;
    step_and_dump_wave();

    top -> en = 0b0;
    top -> x = 0b111;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b000;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b001;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b010;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b011;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b100;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b101;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b110;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b111;
    step_and_dump_wave();

    sim_exit();
}