//
// Created by shecannotsee on 23-9-2.
//
#include "http_wrapper.h"

#include <interface_route.h>
#include <log_wrapper.h>

http_server::http_server(int port) {
  http_server_.config.port = port;
  logModule::registerLogger("http_server");
  auto log_ptr = logModule::getLogger("http_server");
  log_ptr->info("http://{}:{}",http_server_.config.address,http_server_.config.port);
}


void http_server::register_rest_api() {
  using namespace std::placeholders;
  using namespace interface;

  http_server_.default_resource["OPTIONS"] = [](Response response, Request request) {};
  // 对未注册的POST请求的返回
  http_server_.default_resource["POST"]= [&](Response response, Request request) {
    auto log_ptr = logModule::getLogger("http_server");
    log_ptr->info("no POST request to register");
    log_ptr->info((request->content).string());
//    log_ptr->info((request->header));
    SimpleWeb::CaseInsensitiveMultimap header;
    response->write(SimpleWeb::StatusCode::client_error_not_found, "error,POST default", header);
  };
  // 对未注册的GET请求的返回
  http_server_.default_resource["GET"]= [&](Response response, Request request) {
    auto log_ptr = logModule::getLogger("http_server");
    log_ptr->info("no GET request to register");
    SimpleWeb::CaseInsensitiveMultimap header;
    response->write(SimpleWeb::StatusCode::client_error_not_found, "error,GET default", header);
  };

  /*-1*/http_server_.resource[path("-1")][method("-1")] =
          std::bind(&services::interface_route_N1,this->services_, _1, _2);
  /*01*/http_server_.resource[path("01")][method("01")] =
          std::bind(&services::interface_route_01,this->services_, _1, _2);
  /*02*/http_server_.resource[path("02")][method("02")] =
          std::bind(&services::interface_route_02,this->services_, _1, _2);
  /*03*/http_server_.resource[path("03")][method("03")] =
          std::bind(&services::interface_route_03,this->services_, _1, _2);
  /*04*/http_server_.resource[path("04")][method("04")] =
          std::bind(&services::interface_route_04,this->services_, _1, _2);
  /*05*/http_server_.resource[path("05")][method("05")] =
          std::bind(&services::interface_route_05,this->services_, _1, _2);
  /*06*/http_server_.resource[path("06")][method("06")] =
          std::bind(&services::interface_route_06,this->services_, _1, _2);
  /*07*/http_server_.resource[path("07")][method("07")] =
          std::bind(&services::interface_route_07,this->services_, _1, _2);
  /*08*/http_server_.resource[path("08")][method("08")] =
          std::bind(&services::interface_route_08,this->services_, _1, _2);
  /*09*/http_server_.resource[path("09")][method("09")] =
          std::bind(&services::interface_route_09,this->services_, _1, _2);
  /*10*/http_server_.resource[path("10")][method("10")] =
          std::bind(&services::interface_route_10,this->services_, _1, _2);
  /*11*/http_server_.resource[path("11")][method("11")] =
          std::bind(&services::interface_route_11,this->services_, _1, _2);
  /*12*/http_server_.resource[path("12")][method("12")] =
          std::bind(&services::interface_route_12,this->services_, _1, _2);
  /*13*/http_server_.resource[path("13")][method("13")] =
          std::bind(&services::interface_route_13,this->services_, _1, _2);

}

void http_server::start() {
  this->register_rest_api();
  http_server_.start();
}

http_server::~http_server() {
  http_server_.stop();
}

