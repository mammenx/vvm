#ifndef __VVM_CLK_GEN
#define __VVM_CLK_GEN

#include <vector>
#include <string>
#include "base/vvm_types.h"
#include "base/vvm_component.h"
#include "base/vvm_object.h"

class vvm_clk : vvm_object  {
  public:
    std::string     name;
    unsigned  char* dut_clk_ref;
    unsigned  int   phase0_steps;
    unsigned  int   phase1_steps;
    unsigned  int   init_val;
    unsigned  int   start_delay;
    unsigned  int   next_tickcount;

    void  print_clk_state() {
      printf("[Clock %s] curr_val : %d, phase0_steps : %d, phase1_steps : %d, start_delay : %d, init_val : %d, next_tickcount : %d\n",name.c_str(),*(dut_clk_ref),phase0_steps,phase1_steps,start_delay,init_val,next_tickcount);
    }
};

template<class DUT_T>  class vvm_clk_gen : vvm_component {
  private:
    DUT_T*  dut_ref;
    std::vector<vvm_clk> clk_info_vec;
    unsigned  long  m_tickcount;

  public:
    vvm_clk_gen(DUT_T* dut):dut_ref(dut) {};
    vvm_status_t                add_dut_clock(std::string name,  unsigned  char* dut_clk_ref,  unsigned  int period,  unsigned int init_val=0, unsigned int start_delay=0);
    void                        init_dut_clocks(void);
    std::vector<vvm_clk>        toggle_next_clock(void);
    unsigned  long              get_tickcount(void);

};

#include "methodology/vvm_clk_gen.imp.h"

#endif  //__VVM_CLK_GEN
