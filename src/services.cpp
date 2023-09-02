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
  logModule::registerLogger("download");
  auto log_ptr = logModule::getLogger("download");
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"]["file_download_url"] = "http://localhost:5000/xx/xxx.txt";

  log_ptr->info(ret.dump());

  response->write(ret.dump());
}

void services::interface_route_03(Response response, Request request) {
  logModule::registerLogger("upload");
  auto log_ptr = logModule::getLogger("upload");



}
