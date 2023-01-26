#include "verilated.h"
#include "verilated_vcd_c.h"
#include "./obj_dir/Vps2_keyboard_sim_fn.h"

#include <iostream>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vps2_keyboard_sim_fn* top;

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
    top = new Vps2_keyboard_sim_fn;
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
    printf("This is a PS/2 Keyboard Controler, Simulations are F1-F12");
    printf("\n");

    // Simulator Main Parts
    sim_init();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F1: 1'b0 8'b 1010 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 0110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F2: 1'b0 8'b 0110 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 0010 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F3: 1'b0 8'b 0010 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0011 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F4: 1'b0 8'b 0011 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1100 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F5: 1'b0 8'b 1100 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F6: 1'b0 8'b 1101 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F6: 1'b0 8'b 1101 000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1100 0001
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F7: 1'b0 8'b 1100 0001 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 0101 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F8: 1'b0 8'b 0101 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1000 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F9: 1'b0 8'b 1000 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1001 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F10: 1'b0 8'b 1001 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 0001 1110
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F11: 1'b0 8'b 0001 1110 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();




    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 1 (1/1): Start Signal 1'b0
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (1/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (2/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (3/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (4/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (5/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (6/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (7/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 2 (8/8): Data Signal 8'b 1110 0000
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 0; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 3 (1/1): Check Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    // F12: 1'b0 8'b 1110 0000 1'b1 1'b1
    // STEP 4 (1/1): Stop Signal 1'b1
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 1; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 0; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();
    top -> clk = 1; top -> ps2_clk = 0; top -> clrn = 1; top -> ps2_data = 1; top -> nextdata_n = 1; step_and_dump_wave();

    sim_exit();
}