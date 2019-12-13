#include  "methodology/vvm_clk_gen.h"
#include  "base/vvm_root.h"

template<class DUT_T> vvm_clk_gen<DUT_T>::vvm_clk_gen(DUT_T* dut) : vvm_root<DUT_T>(dut)  {
  vvm_root<DUT_T>::set_dut_ref(dut);
}

template<class DUT_T>  vvm_status_t  vvm_clk_gen<DUT_T>::add_dut_clock(unsigned  char* dut_clk_ref,  unsigned  int period)  {
  vvm_clk_info_t  clk_info;

  clk_info.dut_clk_ref  = dut_clk_ref;
  clk_info.phase0_steps = period  / 2;
  clk_info.phase1_steps = period  - clk_info.phase0_steps;

  clk_info_vec.push_back(clk_info);

  return  SUCCESS;
}

template<class DUT_T>  void  vvm_clk_gen<DUT_T>::init_dut_clocks(void) {
  m_tickcount = 0;

  for(int i=0;  i<clk_info_vec.size();  i++)  {
    *(clk_info_vec[i].dut_clk_ref)  = 1;
    clk_info_vec[i].next_tickcount  = m_tickcount + clk_info_vec[i].phase0_steps;
  }

  this->eval_dut();
}

template<class DUT_T>  std::vector<vvm_clk_info_t>  vvm_clk_gen<DUT_T>::toggle_next_clock(void) {
  std::vector<vvm_clk_info_t>  result;

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
      this->eval_dut();
      break;
    }

    m_tickcount++;
  };

  return  result;
}

template<class DUT_T>  unsigned  long  vvm_clk_gen<DUT_T>::get_tickcount(void) {
  return  this->m_tickcount;
}

