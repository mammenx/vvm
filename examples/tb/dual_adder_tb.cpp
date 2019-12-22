#include  "Vdual_adder.h"
#include  "verilated.h"
#include "verilated_vcd_c.h"
#include  "vvm.h"
#include  <vector>
#include  <iostream>
#include  <thread>
#include  <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>


void thread_function(std::string  name, std::shared_ptr<spdlog::logger> _logger)
{
  _logger->info("Thread {}",name);
}


//template class vvm::vvm_clk_gen<Vdual_adder>;

int main(int argc, char** argv, char** env) {

    vvm::run_test();

  try {
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("my_logger.log"));
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    auto my_logger =  std::make_shared<spdlog::logger>("basic_logger", begin(sinks), end(sinks));
    spdlog::register_logger(my_logger);
    //auto er =  spdlog::basic_logger_mt("basic_logger","my_logger.log");

  } catch (const  spdlog::spdlog_ex& ex)  {
    std::cout<<"Log initialization failed: " <<ex.what()<<std::endl;
  }

  auto  my_logger = spdlog::get("basic_logger");
  my_logger->info("Main thread");

  std::thread t1(&thread_function,"t1",my_logger);
  std::thread t2(&thread_function,"t2",my_logger);
  std::cout << "main thread\n";

  t1.join();
  t2.join();

  Verilated::commandArgs(argc, argv);

  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;

  Vdual_adder* top = new Vdual_adder;

  vvm::vvm_clk_gen<Vdual_adder>  clk_gen(top);

  top->trace(tfp, 99);  // Trace 99 levels of hierarchy
  tfp->open("sim.vcd");

  clk_gen.add_dut_clock("CLKA", &(top->clk0),  3, 1,  20);
  clk_gen.add_dut_clock("CLKB", &(top->clk1),  5, 0,  10);
  //clk_gen.add_dut_clock(&(top->clk1),  5);
  std::vector<vvm::vvm_clk>   tggl_clk_vec;

  clk_gen.init_dut_clocks();

  for(int i=0;  i<20; i++)  {
    tggl_clk_vec = clk_gen.toggle_next_clock();
    tfp->dump(clk_gen.get_tickcount());

    for(int i=0;  i<tggl_clk_vec.size();  i++)  {
      tggl_clk_vec[i].print_clk_state();
    }

    std::cout<<"..."<<std::endl;
  }

  tfp->close();
  delete top;
  exit(0);
}
