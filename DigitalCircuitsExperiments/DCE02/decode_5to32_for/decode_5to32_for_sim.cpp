#include "verilated.h"
#include "verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE02/decode_5to32_for/obj_dir/Vdecode_5to32_for.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vdecode_5to32_for* top;

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
    top = new Vdecode_5to32_for;
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
    printf("This is a 5 to 32 Decoder modeled by for");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> en = 0b0;
    top -> x = 0b00000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00011;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00101;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00110;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b00111;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01011;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01101;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01110;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b01111;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10011;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10101;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10110;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b10111;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11000;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11001;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11010;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11011;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11100;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11101;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11110;
    step_and_dump_wave();
    top -> en = 0b0;
    top -> x = 0b11111;
    step_and_dump_wave();

    top -> en = 0b1;
    top -> x = 0b00000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00011;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00101;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00110;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b00111;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01011;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01101;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01110;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b01111;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10011;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10101;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10110;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b10111;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11000;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11001;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11010;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11011;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11100;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11101;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11110;
    step_and_dump_wave();
    top -> en = 0b1;
    top -> x = 0b11111;
    step_and_dump_wave();

    sim_exit();
}