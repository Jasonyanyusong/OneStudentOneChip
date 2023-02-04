#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "./obj_dir/VCyclicShifter_Left_4Bit.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VCyclicShifter_Left_4Bit* top;

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
	top = new VCyclicShifter_Left_4Bit;
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
	printf("This is a CyclicShifter_Left_4Bit\n");
	sim_init();

    top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave();
    top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave();

    top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave();
    top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave();

	sim_exit();
	return 0;
}
