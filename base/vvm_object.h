#ifndef   __VVM_OBJECT
#define   __VVM_OBJECT

#include  "base/vvm_void.h"
#include  <string>

class vvm_object  : public  vvm_void {
  private:
    std::string   name;

  public:
    vvm_object(std::string  name):name(name)  {};

    void        set_name(std::string  name);
    std::string get_name();

};

#include  "vvm_object.imp.h"

#endif  //__VVM_OBJECT
