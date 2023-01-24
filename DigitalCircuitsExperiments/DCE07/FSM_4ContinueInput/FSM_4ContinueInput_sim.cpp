#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "./obj_dir/VFSM_4ContinueInput.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VFSM_4ContinueInput* top;

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
	top = new VFSM_4ContinueInput;
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
	printf("This is a FSM_4ContinueInput\n");
	sim_init();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 1; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 1; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();

    top -> clk = 0; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    top -> clk = 1; top -> reset = 0; top -> in = 0; step_and_dump_wave();
    

	sim_exit();
	return 0;
}
