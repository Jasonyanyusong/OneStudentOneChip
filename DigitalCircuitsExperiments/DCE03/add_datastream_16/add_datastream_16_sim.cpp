#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/add_datastream_16/obj_dir/Vadd_datastream_16.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vadd_datastream_16* top;

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
    top = new Vadd_datastream_16;
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
    printf("This is a 16-bit ADDER modeled by datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    for(int i = 0b0000000000000000; i <= 0b1111111111111111; i += 0b0000000000000001)
    {
        for (int j = 0b0000000000000000; j<= 0b1111111111111111; j += 0b0000000000000001)
        {
            top -> in_x = i; top -> in_y = j; step_and_dump_wave();
        }
    }

    sim_exit();
}