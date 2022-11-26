#include <verilated.h>
#include <verilated_vcd_c.h>
#include <obj_dir/Vmux_2to1_Datastream.h>

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux_2to1_Datastream* top;

void step_and_dump_wave()
{
    top -> eval();
    contextp -> timeInc(1);
}