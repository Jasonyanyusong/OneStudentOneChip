#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "./obj_dir/VMultiShifter_4Bit.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VMultiShifter_4Bit* top;

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
	top = new VMultiShifter_4Bit;
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
	printf("This is a MultiShifter_4Bit\n");
	sim_init();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b010; top -> inp = 0b0000; step_and_dump_wave(); // Logic Right 2 steps
    top -> clk = 1; top -> sel = 0b010; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b010; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b010; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b011; top -> inp = 0b0000; step_and_dump_wave(); // Logic Left 2 steps
    top -> clk = 1; top -> sel = 0b011; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b011; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b011; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b100; top -> inp = 0b0000; step_and_dump_wave(); // Arithmetic Right 2 steps
    top -> clk = 1; top -> sel = 0b100; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b100; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b100; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b101; top -> inp = 0b0000; step_and_dump_wave(); // Arithmetic Left 2 steps
    top -> clk = 1; top -> sel = 0b101; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b101; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b101; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1001; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b110; top -> inp = 0b0000; step_and_dump_wave(); // Cyclic Right 2 steps
    top -> clk = 1; top -> sel = 0b110; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b110; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b110; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

    top -> clk = 0; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave(); // Assign Value
    top -> clk = 1; top -> sel = 0b001; top -> inp = 0b1101; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b111; top -> inp = 0b0000; step_and_dump_wave(); // Cyclic Left 2 steps
    top -> clk = 1; top -> sel = 0b111; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b111; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 1; top -> sel = 0b111; top -> inp = 0b0000; step_and_dump_wave();
    top -> clk = 0; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave(); // Clear Value
    top -> clk = 1; top -> sel = 0b000; top -> inp = 0b0000; step_and_dump_wave();

	sim_exit();
	return 0;
}
