#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/ALU32/ALU32_Test/Add_WithCarryOrOverflow/Add_WithOnlyCarry/obj_dir/VALU32_Test.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VALU32_Test* top;

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
    top = new VALU32_Test;
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

    // Print module informations
    std :: cout << "A 32 bit ALU can accept numbers range from -2147483648 to 2147483647" << std :: endl;

    // Simulator Main Parts
    sim_init();

    // TEST FUNCTION 1: ADD
    // TEST SET 2: With Carry, No Overflow
    // Test Branch 1: A > 0 and B > 0
    top -> sub_add = 0b0;
    top -> a = 0b01100011010101110101000010101010; // + 1666666666
    top -> b = 0b01100011010101110101000010101010; // + 1666666666
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A > 0 > B, A + B > 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "1" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b01000110101011101010000101010100" << std :: endl;
    step_and_dump_wave();

    sim_exit();
}
