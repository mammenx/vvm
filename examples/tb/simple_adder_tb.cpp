#include  "Vsimple_adder.h"
#include  "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv, char** env) {
  Verilated::commandArgs(argc, argv);

   Verilated::traceEverOn(true);
   VerilatedVcdC* tfp = new VerilatedVcdC;

   unsigned long  m_tickcount;

  Vsimple_adder* top = new Vsimple_adder;

   top->trace(tfp, 99);  // Trace 99 levels of hierarchy
   tfp->open("sim.vcd");


  m_tickcount = 0l;

  while (!Verilated::gotFinish()) {
    top->clk          = 1;
    top->rst_n        = 0;
    top->din_valid    = 0;
    top->din          = 0;
    top->eval();
    tfp->dump(m_tickcount);

    //One cycle
    m_tickcount++;
    top->clk          = 0;
    top->eval();
    tfp->dump(10*m_tickcount-2);
    top->clk          = 1;
    top->eval();
    tfp->dump(10*m_tickcount);
    top->clk          = 0;
    top->eval();
    tfp->dump(10*m_tickcount+5);

    tfp->flush();

    break;
  }
  tfp->close();
  delete top;
  exit(0);
}
