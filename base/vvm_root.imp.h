#include  "base/vvm_root.h"
#include  "base/vvm_types.h"
#include  "base/vvm_component.h"

template<class DUT_T> DUT_T*  vvm_root<DUT_T>::dut_ref  = VVM_NULL;

template<class DUT_T>  vvm_root<DUT_T>::vvm_root(DUT_T* dut)  : vvm_component() {
  vvm_root<DUT_T>::dut_ref  = dut;
}

template<class DUT_T>  void  vvm_root<DUT_T>::set_dut_ref(DUT_T*  ref)  {
  vvm_root<DUT_T>::dut_ref  = ref;

}

template<class DUT_T>  void  vvm_root<DUT_T>::eval_dut(void)  {
  vvm_root<DUT_T>::dut_ref->eval();
}
