#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/bcd7seg_case_coNegative/obj_dir/Vbcd7seg_case_coNegative.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vbcd7seg_case_coNegative* top;

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
    top = new Vbcd7seg_case_coNegative;
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
    printf("This is a Co-Negative 7-Signals BCD");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> b = 0b0000;
    step_and_dump_wave();
    top -> b = 0b0001;
    step_and_dump_wave();
    top -> b = 0b0010;
    step_and_dump_wave();
    top -> b = 0b0011;
    step_and_dump_wave();
    top -> b = 0b0100;
    step_and_dump_wave();
    top -> b = 0b0101;
    step_and_dump_wave();
    top -> b = 0b0110;
    step_and_dump_wave();
    top -> b = 0b0111;
    step_and_dump_wave();
    top -> b = 0b1000;
    step_and_dump_wave();
    top -> b = 0b1001;
    step_and_dump_wave();
    top -> b = 0b1010;
    step_and_dump_wave();
    top -> b = 0b1011;
    step_and_dump_wave();
    top -> b = 0b1100;
    step_and_dump_wave();
    top -> b = 0b1101;
    step_and_dump_wave();
    top -> b = 0b1110;
    step_and_dump_wave();
    top -> b = 0b1111;
    step_and_dump_wave();

    sim_exit();
}