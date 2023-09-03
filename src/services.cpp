//
// Created by shecannotsee on 23-9-2.
//

#include "services.h"
#include <log_wrapper.h>
#include <nlohmann/json.hpp>
#include <memory_store/she_memory_ky.h>

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
  log_ptr->info("start=========================");
  log_ptr->info((request->content).string());
  log_ptr->info("end=========================");

  nlohmann::json ret;


  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_04(Response response, Request request) {
  logModule::registerLogger("login");
  auto log_ptr = logModule::getLogger("login");
  log_ptr->info((request->content).string());

  nlohmann::json user = nlohmann::json::parse(request->content); // string to json


  /* mock data */
  she_memory_ky<std::string,std::vector<std::string>> user_role;/* add data */ {
    user_role.set("test1",{"menu_A","menu_B","menu_C","menu_D"});
    user_role.set("test2",{"menu_A","menu_B","menu_C"});
    user_role.set("test3",{"menu_A","menu_B"});
    user_role.set("test4",{"menu_A"});
  }

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  ret["data"]["user_type"] = 1;
  ret["data"]["token"] = 1;
  auto _ = user_role.get(user["user_name"]);
  for(const auto& element : std::get<1>(_) ) {
    ret["data"]["role_codes"].push_back(element);
  };

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}
