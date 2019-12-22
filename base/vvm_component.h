#ifndef __VVM_COMPONENT
#define __VVM_COMPONENT

#include  "base/vvm_report_object.h"

class vvm_component : public  vvm_report_object {
  private:

  public:
    vvm_component(std::string name):vvm_report_object(name) {};

};

#endif  //__VVM_COMPONENT
