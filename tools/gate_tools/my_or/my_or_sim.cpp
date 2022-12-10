#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/tools/gate_tools/my_or/obj_dir/Vmy_or.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmy_or* top;

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
    top = new Vmy_or;
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
    printf("This is a OR GATE TOOLS module");
    printf("\n");

    // Simulator Main Parts
    sim_init();


    top -> a = 0;
    top -> b = 0;
    step_and_dump_wave();

    top -> a = 0;
    top -> b = 1;
    step_and_dump_wave();

    top -> a = 1;
    top -> b = 0;
    step_and_dump_wave();

    top -> a = 1;
    top -> b = 1;
    step_and_dump_wave();

    sim_exit();
}