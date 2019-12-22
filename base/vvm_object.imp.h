#include  "vvm_object.h"
#include  <string>


void  vvm_object::set_name(std::string  name) {
  this->name  = name;
}

std::string vvm_object::get_name()  {
  return  name;
}
