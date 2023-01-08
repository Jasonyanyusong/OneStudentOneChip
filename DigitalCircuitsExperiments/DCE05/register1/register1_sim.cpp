#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE05/register1/obj_dir/Vregister1.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vregister1* top;

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
	top = new Vregister1;
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
	printf("This is a 1 bit register\n");
	int timecount = 1;
	sim_init();

	// 1-Bit register simulation Task 1: Clock (POSEDGE), Clear (0), Load (0), Input (0). Expected Q (X)
	std :: cout << "Simulation TASK 1 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	// POSEDGE UP
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1 (STOP): Clock (POSEDGE), Clear (0), Load (0), Input (0). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 2: Clock (POSEDGE), Clear (0), Load (0), Input (1). Expected Q (X)
	// POSEDGE UP
	std :: cout << "Simulation TASK 2 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (1). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2 (STOP): Clock (POSEDGE), Clear (0), Load (0), Input (1). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 3: Clock (POSEDGE), Clear (0), Load (1), Input (0). Expected Q (0)
	// POSEDGE UP
	std :: cout << "Simulation TASK 3 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3 (STOP): Clock (POSEDGE), Clear (0), Load (1), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 4: Clock (POSEDGE), Clear (0), Load (1), Input (1). Expected Q (1)
	// POSEDGE UP
	std :: cout << "Simulation TASK 4 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (1). Expected Q (1)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4 (STOP): Clock (POSEDGE), Clear (0), Load (1), Input (1). Expected Q (1)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 5: Clock (POSEDGE), Clear (1), Load (0), Input (0). Expected Q (0)
	// POSEDGE UP
	std :: cout << "Simulation TASK 5 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 5 (STOP): Clock (POSEDGE), Clear (1), Load (0), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 6: Clock (POSEDGE), Clear (1), Load (0), Input (1). Expected Q (0)
	// POSEDGE UP
	std :: cout << "Simulation TASK 6 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (1). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 1; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 6 (STOP): Clock (POSEDGE), Clear (1), Load (0), Input (1). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 7: Clock (POSEDGE), Clear (1), Load (1), Input (0). Expected Q (0)
	// POSEDGE UP
	std :: cout << "Simulation TASK 7 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 7 (STOP): Clock (POSEDGE), Clear (1), Load (1), Input (0). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	// 1-Bit register simulation Task 8: Clock (POSEDGE), Clear (1), Load (1), Input (1). Expected Q (0)
	// POSEDGE UP
	std :: cout << "Simulation TASK 8 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (1). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	// POSEDGE DOWN
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 1; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 8 (STOP): Clock (POSEDGE), Clear (1), Load (1), Input (1). Expected Q (0)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;

	sim_exit();
	return 0;
}
