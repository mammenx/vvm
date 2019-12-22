#ifndef __VVM_REPORT_OBJECT
#define __VVM_REPORT_OBJECT

#include "base/vvm_object.h"
#include <vector>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class vvm_report_object : public  vvm_object {
  private:
    std::shared_ptr<spdlog::logger>       _logger;

  public:
    static  std::vector<spdlog::sink_ptr> glbl_sinks;

    vvm_report_object(std::string name):vvm_object(name)  {
      try {
        _logger = std::make_shared<spdlog::logger>(this->get_name()+"_logger", begin(vvm_report_object::glbl_sinks), end(vvm_report_object::glbl_sinks));
        _logger->set_level(spdlog::level::debug);
        _logger->set_pattern("[%n][%^%l%$] %v");
        spdlog::register_logger(_logger);
      } catch (const  spdlog::spdlog_ex& ex)  {
        std::cout<<"Log initialization failed: "<<ex.what()<<std::endl;
      }
    }

    static  std::vector<spdlog::sink_ptr>  get_glbl_sinks();
    static  void                           add_glbl_sink(const  spdlog::sink_ptr sink);
    std::shared_ptr<spdlog::logger>        get_logger();

    template<typename...  Args> void  vvm_report_info(std::string const&  fmt,  const Args &... args);
    template<typename...  Args> void  vvm_report_warning(std::string const&  fmt,  const Args &... args);
    template<typename...  Args> void  vvm_report_error(std::string const&  fmt,  const Args &... args);  
    template<typename...  Args> void  vvm_report_fatal(std::string const&  fmt,  const Args &... args);
    template<typename...  Args> void  vvm_report_debug(std::string const&  fmt,  const Args &... args);
};

#include  "vvm_report_object.imp.h"

#endif  //__VVM_REPORT_OBJECT
