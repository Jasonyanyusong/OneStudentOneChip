//#include <verilated.h>
//#include <verilated_vcd_c.h>
//#include <obj_dir/Vmux_4to1_Case.h>

#include "/usr/local/share/verilator/include/verilated.h"
#include "/usr/local/share/verilator/include/verilated_vcd_c.h"
#include "/home/ce/OneStudentOneChip/DigitalCircuitsExperiments/DCE01/mux_4to1_case_further/obj_dir/Vmux_4to1_Case.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux_4to1_Case* top;

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
    top = new Vmux_4to1_Case;
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
    printf("This is a Mutiplexer modeled by Case");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    top -> s = 0b00;
    top -> a = 0b0000; // 0
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0001; // 1
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0010; // 2
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0011; // 3
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0100; // 4
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0101; // 5
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0110; // 6
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b0111; // 7
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1000; // 8
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1001; // 9
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1010; // 10
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1011; // 11
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1100; // 12
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1101; // 13
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1110; // 14
    step_and_dump_wave();
    top -> s = 0b00;
    top -> a = 0b1111; // 15
    step_and_dump_wave();

    top -> s = 0b01;
    top -> a = 0b0000; // 0
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0001; // 1
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0010; // 2
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0011; // 3
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0100; // 4
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0101; // 5
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0110; // 6
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b0111; // 7
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1000; // 8
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1001; // 9
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1010; // 10
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1011; // 11
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1100; // 12
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1101; // 13
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1110; // 14
    step_and_dump_wave();
    top -> s = 0b01;
    top -> a = 0b1111; // 15
    step_and_dump_wave();

    top -> s = 0b10;
    top -> a = 0b0000; // 0
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0001; // 1
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0010; // 2
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0011; // 3
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0100; // 4
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0101; // 5
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0110; // 6
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b0111; // 7
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1000; // 8
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1001; // 9
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1010; // 10
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1011; // 11
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1100; // 12
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1101; // 13
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1110; // 14
    step_and_dump_wave();
    top -> s = 0b10;
    top -> a = 0b1111; // 15
    step_and_dump_wave();

    top -> s = 0b11;
    top -> a = 0b0000; // 0
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0001; // 1
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0010; // 2
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0011; // 3
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0100; // 4
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0101; // 5
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0110; // 6
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b0111; // 7
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1000; // 8
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1001; // 9
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1010; // 10
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1011; // 11
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1100; // 12
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1101; // 13
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1110; // 14
    step_and_dump_wave();
    top -> s = 0b11;
    top -> a = 0b1111; // 15
    step_and_dump_wave();

    sim_exit();
}