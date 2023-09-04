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
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"]["file_download_url"] = "http://localhost:5000/xx/xxx.txt";

  log_ptr->info(ret.dump());

  response->write(ret.dump());
}

void services::interface_route_03(Response response, Request request) {
  log_ptr->info("start=========================");
  log_ptr->info((request->content).string());
  log_ptr->info("end=========================");

  nlohmann::json ret;


  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_04(Response response, Request request) {
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

namespace role {
static she_memory_ky<std::string, std::vector<std::string>> entity = {
  {"admin", {"menu_A", "menu_B", "menu_C", "menu_D"}}
};
} // namespace role

void services::interface_route_05(Response response, Request request) {
  log_ptr->info((request->content).string());

  nlohmann::json role_add = nlohmann::json::parse(request->content); // string to json
  role::entity.set(role_add["role_name"],{});

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  ret["data"][""];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_06(Response response, Request request) {
  log_ptr->info((request->content).string());

  nlohmann::json role_edit = nlohmann::json::parse(request->content); // string to json
  std::vector<std::string> _;
  for (auto element : role_edit["role_codes"]) {
    _.push_back(element);
  };
  role::entity.set(role_edit["role_name"],_);

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  ret["data"][""];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_07(Response response, Request request) {
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  int i=1;
  for (auto element:role::entity.db_) {
    nlohmann::json _1;
    _1["role"] = i++;
    _1["role_name"] = element.first;
    for(auto _ : element.second) {
     _1["role_codes"].push_back(_);
    }
    ret["data"].push_back(_1);
  }

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_08(Response response, Request request) {
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());

  response->write(ret.dump());
}

void services::interface_route_09(Response response, Request request) {
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}
