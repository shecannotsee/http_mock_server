//
// Created by shecannotsee on 23-9-2.
//

#include "services.h"
#include "interface_route.h"
#include <log_wrapper.h>
#include <nlohmann/json.hpp>
#include <memory_store/she_memory_ky.h>

void services::interface_route_N1(Response response, Request request) {
  log_ptr->info(interface::path("N1"));

}

void services::interface_route_01(Response response, Request request) {
  log_ptr->info(interface::path("01"));

}

void services::interface_route_02(Response response, Request request) {
  log_ptr->info(interface::path("02"));

  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"]["file_download_url"] = "http://localhost:5001/config/xxx.txt";

  log_ptr->info(ret.dump());

  response->write(ret.dump());
}

void services::interface_route_03(Response response, Request request) {
  log_ptr->info(interface::path("03"));

  log_ptr->info("start=========================");
  log_ptr->info((request->content).string());
  log_ptr->info("end=========================");

  nlohmann::json ret;


  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_04(Response response, Request request) {
  log_ptr->info(interface::path("05"));

  log_ptr->info((request->content).string());

  nlohmann::json user = nlohmann::json::parse(request->content); // string to json


  /* mock data */
  she_memory_ky<std::string,std::vector<std::string>> user_role;/* add data */ {
    //"baseInfo", "statusQuery", "faultAlarm", "versionInfo", "logsManage", "config", "resetSettings", "performance", "projectByMonth", "account", "role", "webLogs"

    user_role.set("test1",{"baseInfo", "statusQuery", "faultAlarm", "versionInfo", "logsManage", "config", "resetSettings", "performance", "remoteUpgrade", "account", "role", "webLogs"});
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
  log_ptr->info(interface::path("05"));

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
  log_ptr->info(interface::path("06"));

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
  log_ptr->info(interface::path("07"));

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
  log_ptr->info(interface::path("08"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());

  response->write(ret.dump());
}

void services::interface_route_09(Response response, Request request) {
  log_ptr->info(interface::path("09"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

namespace user {
using user_format = std::tuple<std::string,int,std::string>;
static she_memory_ky<int, user_format> entity = {
  {1,{"admin",1,"超级管理员"}}
};
} // namespace user

void services::interface_route_10(Response response, Request request) {
  log_ptr->info(interface::path("10"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];
  using user_list = std::tuple<int,std::string,int,std::string>;
  user_list _;
  for (auto it : user::entity.db_) {
    nlohmann::json _1;
    _1["user_id"] = std::to_string(it.first);
    _1["user_name"] = std::get<0>(it.second);
    _1["role_id"] = std::to_string(std::get<1>(it.second));
    _1["role_name"] = std::get<2>(it.second);
    ret["data"].push_back(_1);
  }

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_11(Response response, Request request) {
  log_ptr->info(interface::path("11"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_12(Response response, Request request) {
  log_ptr->info(interface::path("12"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_13(Response response, Request request) {
  log_ptr->info(interface::path("13"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}
