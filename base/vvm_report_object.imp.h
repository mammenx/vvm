#include  "base/vvm_report_object.h"
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

std::vector<spdlog::sink_ptr> vvm_report_object::glbl_sinks = {};

std::vector<spdlog::sink_ptr>  vvm_report_object::get_glbl_sinks()  {
  return  vvm_report_object::glbl_sinks;
}

void  vvm_report_object::add_glbl_sink(const  spdlog::sink_ptr sink)  {
  vvm_report_object::glbl_sinks.push_back(sink);
}

std::shared_ptr<spdlog::logger> vvm_report_object::get_logger() {
  return  _logger;
}

template<typename...  Args> void  vvm_report_object::vvm_report_info(std::string const&  fmt,  const Args &... args) {
  this->_logger->info(fmt,args...);
}

template<typename...  Args> void  vvm_report_object::vvm_report_warning(std::string const&  fmt,  const Args &... args) {
  this->_logger->warn(fmt,args...);
}

template<typename...  Args> void  vvm_report_object::vvm_report_error(std::string const&  fmt,  const Args &... args) {
  this->_logger->error(fmt,args...);
}

template<typename...  Args> void  vvm_report_object::vvm_report_fatal(std::string const&  fmt,  const Args &... args) {
  this->_logger->critical(fmt,args...);
}

template<typename...  Args> void  vvm_report_object::vvm_report_debug(std::string const&  fmt,  const Args &... args) {
  this->_logger->debug(fmt,args...);
}

