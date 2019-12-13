#ifndef __VVM_ROOT
#define __VVM_ROOT

template<class  DUT_T>  class vvm_root  {
  private:
    static  DUT_T*  dut_ref;

  public:
    vvm_root(DUT_T* dut);
    void  set_dut_ref(DUT_T*  ref);
    void  eval_dut(void);

};

#include "base/vvm_root.imp.h"

#endif  //__VVM_ROOT
