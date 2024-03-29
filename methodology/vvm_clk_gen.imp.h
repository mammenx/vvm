#include  "methodology/vvm_clk_gen.h"
#include  "base/vvm_component.h"
#include  <string>

template<class DUT_T>  vvm_status_t  vvm_clk_gen<DUT_T>::add_dut_clock(std::string name, unsigned  char* dut_clk_ref,  unsigned  int period, unsigned int init_val, unsigned int start_delay)  {
  vvm_clk clk_info(name);

  clk_info.dut_clk_ref  = dut_clk_ref;
  clk_info.phase0_steps = period  / 2;
  clk_info.phase1_steps = period  - clk_info.phase0_steps;
  clk_info.init_val     = init_val;
  clk_info.start_delay  = start_delay;

  clk_info_vec.push_back(clk_info);

  return  SUCCESS;
}

template<class DUT_T>  void  vvm_clk_gen<DUT_T>::init_dut_clocks(void) {
  m_tickcount = 0;

  for(int i=0;  i<clk_info_vec.size();  i++)  {
    *(clk_info_vec[i].dut_clk_ref)  = clk_info_vec[i].init_val;
    clk_info_vec[i].next_tickcount  = m_tickcount + clk_info_vec[i].start_delay + clk_info_vec[i].phase0_steps;
  }

  dut_ref->eval();
}

template<class DUT_T>  std::vector<vvm_clk>  vvm_clk_gen<DUT_T>::toggle_next_clock(void) {
  std::vector<vvm_clk>  result;

  while(1)  {
    for(int i=0;  i<clk_info_vec.size();  i++)  {
      if(m_tickcount  >=  clk_info_vec[i].next_tickcount) {
        if(*(clk_info_vec[i].dut_clk_ref)  ==  1)  { //Currently in Phase0
          clk_info_vec[i].next_tickcount  +=  clk_info_vec[i].phase1_steps;
          *(clk_info_vec[i].dut_clk_ref) = 0;
        } else  { //Currently in Phase1
          clk_info_vec[i].next_tickcount  +=  clk_info_vec[i].phase0_steps;
          *(clk_info_vec[i].dut_clk_ref) = 1;
        }
        result.push_back(clk_info_vec[i]);
      }
    }

    if(result.size()) {
      dut_ref->eval();
      break;
    }

    m_tickcount++;
  };

  return  result;
}

template<class DUT_T>  unsigned  long  vvm_clk_gen<DUT_T>::get_tickcount(void) {
  return  this->m_tickcount;
}

