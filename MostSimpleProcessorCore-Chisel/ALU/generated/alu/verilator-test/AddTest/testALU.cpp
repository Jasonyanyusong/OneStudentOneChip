#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/VALU.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VALU* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VALU;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();
  for(int testNumber = 0; testNumber < 65536; testNumber = testNumber + 1)
  {
    top -> io_OperateCode = 0b0000;
    long long GenerateInputA = (-9223372036854775807LL - 1) + rand() * 9223372036854775807LL;
    top -> io_DataInA = GenerateInputA;
    long long GenerateInputB = (-9223372036854775807LL - 1) + rand() * 9223372036854775807LL;
    top -> io_DataInB = GenerateInputB;
    step_and_dump_wave();
  }
  sim_exit();
}
