//
// Created by shecannotsee on 23-9-2.
//

#include "services.h"
#include <log_wrapper.h>
#include <nlohmann/json.hpp>

void services::interface_route_N1(Response response, Request request) {

}

void services::interface_route_01(Response response, Request request) {

}

void services::interface_route_02(Response response, Request request) {
  auto log_ptr = logModule::getLogger("http_server");
//  log_ptr->info((request->content).string());
  std::cout << (request->content).string() << std::endl;
  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"]["file_download_url"] = "http://localhost:5000/xx/xxx.txt";

//  log_ptr->info(ret.dump());
  std::cout << ret.dump() << std::endl;

  response->write(ret.dump());
}
