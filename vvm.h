#ifndef __VVM
#define __VVM

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace vvm {

#include  "base/vvm_base.h"
#include  "methodology/vvm_methodology.h"

void  run_test()  {
  try {
    vvm_report_object::glbl_sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("vvm.log"));
    vvm_report_object::glbl_sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  } catch (const  spdlog::spdlog_ex& ex)  {
    std::cout<<"Log initialization failed: " <<ex.what()<<std::endl;
  }
}

}
#endif  //__VVM
