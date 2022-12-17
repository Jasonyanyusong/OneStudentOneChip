#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/yanyusong/OneStudentOneChip/DigitalCircuitsExperiments/DCE03/ALU32/ALU32_Test/Sub_NoCarryNoOverflow/obj_dir/VALU32_Test.h"

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

    // TEST FUNCTION 2: SUB
    // TEST SET 1: No Carry, No Overflow
    // Test Branch 1: A > 0 and B < 0
    top -> sub_add = 0b1;
    top -> a = 0b00111010110111100110100010110001; // + 987654321
    top -> b = 0b11111000101001000011001011101011; // - 123456789
    std :: cout << "This test bench is designed for testing the ability to calculate A - B where A > 0 > B, A - B > 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b01000010001110100011010111000110" << std :: endl;
    step_and_dump_wave(); // PASS

    // Test Branch 2: A >= 0 and B >= 0
    top -> sub_add = 0b1;
    top -> a = 0b00111010110111100110100010110001; // + 987654321
    top -> b = 0b00000111010110111100110100010101; // + 123456789
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A >= 0 and B >= 0, A - B > 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b00110011100000101001101110011100" << std :: endl;
    step_and_dump_wave(); // PASS

    top -> sub_add = 0b1;
    top -> a = 0b00000000000000000000000000000000; // + 0
    top -> b = 0b00000000000000000000000000000000; // + 0
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A >= 0 and B >= 0, A - B = 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "1" << " Overflow: " << "0" << " Result: " << "0b00000000000000000000000000000000" << std :: endl;
    step_and_dump_wave(); // PASS

    top -> sub_add = 0b1;
    top -> a = 0b00000111010110111100110100010101; // + 123456789
    top -> b = 0b00111010110111100110100010110001; // + 987654321
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A >= 0 and B >= 0, A - B < 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b11001100011111010110010001100100" << std :: endl;
    step_and_dump_wave(); // PASS

    // Test Branch 3: A <= 0 and B <= 0
    top -> sub_add = 0b1;
    top -> a = 0b11000101001000011001011101001111; // - 987654321
    top -> b = 0b11111000101001000011001011101011; // - 123456789
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A <= 0 and B <= 0, A + B < 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b11001100011111010110010001100100" << std :: endl;
    step_and_dump_wave(); // PASS

    top -> sub_add = 0b1;
    top -> a = 0b00000000000000000000000000000000; // - 0
    top -> b = 0b00000000000000000000000000000000; // - 0
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A <= 0 and B <= 0, A - B = 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "1" << " Overflow: " << "0" << " Result: " << "0b00000000000000000000000000000000" << std :: endl;
    step_and_dump_wave(); // PASS

    top -> sub_add = 0b1;
    top -> a = 0b11111000101001000011001011101011; // - 123456789
    top -> b = 0b11000101001000011001011101001111; // - 987654321
    std :: cout << "This test bench is designed for testing the ability to calculate A + B where A <= 0 and B <= 0, A + B > 0" << std :: endl;
    std :: cout << "Sub_Add: " << top -> sub_add << " A: " << top -> a << " B: " << top -> b << std :: endl;
    std :: cout << "Actual Result: " << std :: endl;
    std :: cout << "Carry: " << top -> carry << " Zero: " << top -> zero << " Overflow: " << top -> overflow << " Result: " << top -> result << std :: endl;
    std :: cout << "Expected Result:" << std :: endl;
    std :: cout << "Carry: " << "0" << " Zero: " << "0" << " Overflow: " << "0" << " Result: " << "0b00110011100000101001101110011100" << std :: endl;
    step_and_dump_wave(); // PASS

    sim_exit();
}
