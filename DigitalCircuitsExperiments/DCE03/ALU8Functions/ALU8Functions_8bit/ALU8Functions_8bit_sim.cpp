#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/ALU8Functions/ALU8Functions_8bit/obj_dir/VALU8Functions_8bit.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VALU8Functions_8bit* top;

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
    top = new VALU8Functions_8bit;
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
    printf("This is a 8-bit 8-functions-ALU modeled by datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    for(int i = 0b000; i <= 0b111; i += 0b001)
    {
        for(int j = 0b00000000; j <= 0b11111111; j += 0b001)
        {
            for(int k = 0b00000000; k <= 0b11111111; k += 0b001)
            {
                top -> input_mode_select = i; top -> input_a = j; top -> input_b = k; step_and_dump_wave();
                std :: cout << "1) input_mode_select = " << i <<" 2) input_a =  " << j << " 3) input_b = " << k << " 4) output_result = " << top -> output_result << std :: endl;
            }
        }
    }

    sim_exit();
}