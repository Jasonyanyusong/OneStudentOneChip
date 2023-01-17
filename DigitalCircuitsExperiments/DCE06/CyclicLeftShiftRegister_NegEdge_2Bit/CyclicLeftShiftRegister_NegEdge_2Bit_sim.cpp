#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "./obj_dir/VCyclicLeftShiftRegister_NegEdge_2Bit.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VCyclicLeftShiftRegister_NegEdge_2Bit* top;

void step_and_dump_wave()
{
	top -> eval();
	contextp -> timeInc(1);
	tfp -> dump(contextp -> time());
}

void sim_init()
{
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new VCyclicLeftShiftRegister_NegEdge_2Bit;
	contextp -> traceEverOn(true);
	top -> trace (tfp, 0);
	tfp -> open ("dump.vcd");
}

void sim_exit()
{
	step_and_dump_wave();
	tfp -> close();
}

int main()
{
	printf("Verilator Generated File simulator\n");
	printf("This is a CyclicLeftShiftRegister_NegEdge_2Bit\n");
	sim_init();

    // Positive Edge, No Reset
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();

    // Positive Edge, Reset
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();

    // Negative Edge, No Reset
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();

    // Negative Edge, Reset
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();

    // Positive, No Reset
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();

    // Positive, Reset
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();

    // Negative, No Reset
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b11; step_and_dump_wave();

    // Negative, Reset
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b00; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b01; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b10; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b11; step_and_dump_wave();

	sim_exit();
	return 0;
}
