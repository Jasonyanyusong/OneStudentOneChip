#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE05/register2/obj_dir/Vregister2.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vregister2* top;

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
	top = new Vregister2;
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
	printf("This is a 2 bit register\n");

	int timecount = 1;

	sim_init();

	std :: cout << "Simulation TASK 1-00 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b00). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-00 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-01 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b01). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-01 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-10 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b10). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-10 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-11 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b11). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-11 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-00 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b00). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-00 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-01 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b01). Expected Q (0b01)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-01 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-10 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b10). Expected Q (0b10)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-10 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-11 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b11). Expected Q (0b11)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-11 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-00 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b00). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-00 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-01 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b01). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-01 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-10 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b10). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-10 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-11 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b11). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-11 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-00 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b00). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b00; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-00 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-01 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b01). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b01; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-01 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-10 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b10). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b10; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-10 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-11 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b11). Expected Q (0b00)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b11; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-11 (STOP)" << std :: endl << std :: endl;

	sim_exit();

	return 0;
}
