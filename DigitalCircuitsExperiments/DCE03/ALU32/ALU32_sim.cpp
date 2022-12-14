#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/ALU32/obj_dir/VALU32.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VALU32* top;

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
    top = new VALU32;
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
    printf("This is a 32-bit ALU modeled by datastream");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    //top -> sub_add = 0b0;
    //top -> a = 0b00111010110111100110100010110001; // + 987654321
    //top -> b = 0b11111000101001000011001011101011; // - 123456789
    //std :: cout << "This test bench is designed for testing the ability to calculate A + B where A > 0 > B" << std :: endl;
    //std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    //std :: cout << "Actual Result: " << std :: endl;
    //std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    //std :: cout << "Expected Result:" << std :: endl;
    //std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b00110011100000101001101110011100" << std :: endl;
    //step_and_dump_wave();

    sim_exit();
}
