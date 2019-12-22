#ifndef __VVM_CLK_GEN
#define __VVM_CLK_GEN

#include <vector>
#include <string>
#include "base/vvm_types.h"
#include "base/vvm_component.h"
#include "base/vvm_object.h"

class vvm_clk : public  vvm_report_object  {
  public:
    vvm_clk(std::string name):vvm_report_object(name)  {};
    unsigned  char* dut_clk_ref;
    unsigned  int   phase0_steps;
    unsigned  int   phase1_steps;
    unsigned  int   init_val;
    unsigned  int   start_delay;
    unsigned  int   next_tickcount;

    void  print_clk_state() {
      vvm_report_debug("[Clock {}] curr_val : {}, phase0_steps : {}, phase1_steps : {}, start_delay : {}, init_val : {}, next_tickcount : {}",get_name(),*(dut_clk_ref),phase0_steps,phase1_steps,start_delay,init_val,next_tickcount);
    }
};

template<class DUT_T>  class vvm_clk_gen : public vvm_component {
  private:
    DUT_T*  dut_ref;
    std::vector<vvm_clk> clk_info_vec;
    unsigned  long  m_tickcount;

  public:
    vvm_clk_gen(DUT_T* dut):vvm_component("clk_gen"),dut_ref(dut) {};
    vvm_status_t                add_dut_clock(std::string name,  unsigned  char* dut_clk_ref,  unsigned  int period,  unsigned int init_val=0, unsigned int start_delay=0);
    void                        init_dut_clocks(void);
    std::vector<vvm_clk>        toggle_next_clock(void);
    unsigned  long              get_tickcount(void);

};

#include "methodology/vvm_clk_gen.imp.h"

#endif  //__VVM_CLK_GEN
