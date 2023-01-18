#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "./obj_dir/VArithmeticLeftShiftRegister_NegEdge_4Bit.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VArithmeticLeftShiftRegister_NegEdge_4Bit* top;

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
	top = new VArithmeticLeftShiftRegister_NegEdge_4Bit;
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
	printf("This is a ArithmeticLeftShiftRegister_NegEdge_4Bit\n");
	sim_init();

    // Positive Edge, No Reset
    top -> clock = 0; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();

    // Positive Edge, Reset
    top -> clock = 0; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();

    // Negative Edge, No Reset
    top -> clock = 1; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 0; top -> D = 0b1111; step_and_dump_wave();

    // Negative Edge, Reset
    top -> clock = 1; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b0111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1000; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1001; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1010; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1011; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1100; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1101; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1110; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 1; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();
    top -> clock = 0; top -> reset = 1; top -> D = 0b1111; step_and_dump_wave();

	sim_exit();
	return 0;
}
