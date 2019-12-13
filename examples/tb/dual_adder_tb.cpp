#include  "Vdual_adder.h"
#include  "verilated.h"
#include "verilated_vcd_c.h"
#include  "vvm.h"


//template class vvm::vvm_clk_gen<Vdual_adder>;

int main(int argc, char** argv, char** env) {
  Verilated::commandArgs(argc, argv);

  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;

  Vdual_adder* top = new Vdual_adder;

  vvm::vvm_clk_gen<Vdual_adder>  clk_gen(top);

  top->trace(tfp, 99);  // Trace 99 levels of hierarchy
  tfp->open("sim.vcd");

  clk_gen.add_dut_clock(&(top->clk0),  3);
  clk_gen.add_dut_clock(&(top->clk1),  5);

  clk_gen.init_dut_clocks();

  for(int i=0;  i<20; i++)  {
    clk_gen.toggle_next_clock();
    tfp->dump(clk_gen.get_tickcount());
  }

  tfp->close();
  delete top;
  exit(0);
}
