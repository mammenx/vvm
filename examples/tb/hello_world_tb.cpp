#include  "Vhello_world.h"
#include  "verilated.h"

int main(int argc, char** argv, char** env) {
  Verilated::commandArgs(argc, argv);

  Vhello_world* top = new Vhello_world;
  while (!Verilated::gotFinish()) { top->eval(); }
  delete top;
  exit(0);
}
