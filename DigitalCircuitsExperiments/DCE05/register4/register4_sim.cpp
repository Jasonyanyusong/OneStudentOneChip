#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE05/register4/obj_dir/Vregister4.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vregister4* top;

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
	top = new Vregister4;
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
	printf("This is a 4 bit register\n");

	int timecount = 1;

	sim_init();

	std :: cout << "Simulation TASK 1-0000 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0000). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0001 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0001). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0010 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0010). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0011 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0011). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0100 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0100). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0101 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0101). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0110 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0110). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-0111 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b0111). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-0111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1000 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1000). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1001 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1001). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1010 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1010). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1011 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1011). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1100 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1100). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1101 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1101). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1110 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1110). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 1-1111 (BEGIN): Clock (POSEDGE), Clear (0), Load (0), Input (0b1111). Expected Q (X)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 1-1111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0000 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0000). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0001 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0001). Expected Q (0b0001)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0010 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0010). Expected Q (0b0010)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0011 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0011). Expected Q (0b0011)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0100 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0100). Expected Q (0b0100)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0101 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0101). Expected Q (0b0101)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0110 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0110). Expected Q (0b0110)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-0111 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b0111). Expected Q (0b0111)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-0111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1000 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1000). Expected Q (0b1000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1001 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1001). Expected Q (0b1001)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1010 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1010). Expected Q (0b1010)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1011 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1011). Expected Q (0b1011)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1100 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1100). Expected Q (0b1100)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1101 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1101). Expected Q (0b1101)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1110 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1110). Expected Q (0b1110)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 2-1111 (BEGIN): Clock (POSEDGE), Clear (0), Load (1), Input (0b1111). Expected Q (0b1111)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 0; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 2-1111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0000 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0000). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0001 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0001). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0010 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0010). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0011 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0011). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0100 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0100). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0101 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0101). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0110 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0110). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-0111 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b0111). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-0111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1000 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1000). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1001 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1001). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1010 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1010). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1011 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1011). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1100 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1100). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1101 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1101). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1110 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1110). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 3-1111 (BEGIN): Clock (POSEDGE), Clear (1), Load (0), Input (0b1111). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 0; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 3-1111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0000 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0000). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0001 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0001). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0010 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0010). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0011 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0011). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0100 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0100). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0101 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0101). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0110 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0110). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-0111 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b0111). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b0111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-0111 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1000 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1000). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1000; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1000 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1001 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1001). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1001; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1001 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1010 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1010). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1010; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1010 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1011 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1011). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1011; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1011 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1100 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1100). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1100; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1100 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1101 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1101). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1101; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1101 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1110 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1110). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1110; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1110 (STOP)" << std :: endl << std :: endl;

	std :: cout << "Simulation TASK 4-1111 (BEGIN): Clock (POSEDGE), Clear (1), Load (1), Input (0b1111). Expected Q (0b0000)" << std :: endl;
	std :: cout << "Current time: " << timecount << std :: endl;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 1; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	top -> clk = 0; top -> clr = 1; top -> load = 1; top -> inp = 0b1111; step_and_dump_wave(); timecount ++;
	std :: cout << "Simulation TASK 4-1111 (STOP)" << std :: endl << std :: endl;

	sim_exit();

	return 0;
}
