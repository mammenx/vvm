#ifndef __VVM_CLK_GEN
#define __VVM_CLK_GEN

#include <vector>
#include "base/vvm_types.h"
#include "base/vvm_component.h"

typedef struct  vvm_clk_info_t  {
  unsigned  char* dut_clk_ref;
  unsigned  int   phase0_steps;
  unsigned  int   phase1_steps;
  unsigned  int   next_tickcount;
} vvm_clk_info_t;

template<class DUT_T>  class vvm_clk_gen : vvm_component {
  private:
    DUT_T*  dut_ref;
    std::vector<vvm_clk_info_t> clk_info_vec;
    unsigned  long  m_tickcount;

  public:
    vvm_clk_gen(DUT_T* dut):dut_ref(dut) {};
    vvm_status_t                add_dut_clock(unsigned  char* dut_clk_ref,  unsigned  int period);
    void                        init_dut_clocks(void);
    std::vector<vvm_clk_info_t> toggle_next_clock(void);
    unsigned  long              get_tickcount(void);

};

#include "methodology/vvm_clk_gen.imp.h"

#endif  //__VVM_CLK_GEN
