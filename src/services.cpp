//
// Created by shecannotsee on 23-9-2.
//

#include "services.h"
#include "interface_route.h"
#include <log_wrapper.h>
#include <nlohmann/json.hpp>
#include <store/entity.h>

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
  log_ptr->info(interface::path("04"));

  log_ptr->info((request->content).string());

  nlohmann::json _ = nlohmann::json::parse(request->content); // string to json
  std::string user_name = _["user_name"].get<std::string>();
  std::string user_passwd = _["user_passwd"].get<std::string>();

  bool pass_login = false;
  int role_id = -1;
  std::vector<std::string> role_codes;
  for(auto e : store::user_entity.db_) {
    auto _1 = store::tuple_to_user(e.second);
    if (_1.get_name()==user_name && _1.get_password()==user_passwd) {
      pass_login = true;
      role_id = _1.get_role().get_id();
      role_codes = _1.get_role().get_role_codes();
      break;
    }
  }


  /* mock data */
  she_memory_ky<std::string,std::vector<std::string>> user_role;/* add data */ {
    //"baseInfo", "statusQuery", "faultAlarm", "versionInfo", "logsManage", "config", "resetSettings", "performance", "projectByMonth", "account", "role", "webLogs"

    user_role.set("test1",{"baseInfo", "statusQuery", "faultAlarm", "versionInfo", "logsManage", "config", "resetSettings", "performance", "remoteUpgrade", "account", "role", "webLogs"});
    user_role.set("test2",{"menu_A","menu_B","menu_C"});
    user_role.set("test3",{"menu_A","menu_B"});
    user_role.set("test4",{"menu_A"});
  }
  nlohmann::json ret;
  if (pass_login) {
    ret["code"] = 200;
    ret["err_msg"] = "meow meow meow~";
    ret["data"]["user_type"] = role_id;
    ret["data"]["token"] = "test_token";
    for (const auto &element: role_codes ) {
      ret["data"]["role_codes"].push_back(element);
    };
  } else {
    ret["code"] = 400;
    ret["err_msg"] = "account or password error";
    ret["data"];
  }

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_05(Response response, Request request) {
  log_ptr->info(interface::path("05"));

  log_ptr->info((request->content).string());

  nlohmann::json role_add = nlohmann::json::parse(request->content); // string to json
  std::string role_name = role_add["role_name"].get<std::string>();
  store::role _(++store::role_key,role_name,{});
  store::role_entity.set(store::role_key, store::role_to_tuple(_));

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_06(Response response, Request request) {
  log_ptr->info(interface::path("06"));

  log_ptr->info((request->content).string());

  nlohmann::json role_edit = nlohmann::json::parse(request->content); // string to json
  auto _ = store::role_entity.get(role_edit["role_id"].get<int>());
  std::string err_msg;
  if (std::get<0>(_)) {
    err_msg = "meow meow meow~";
    auto _role = store::tuple_to_role(std::get<1>(_));
    std::vector<std::string> _role_codes;/* get role codes from request */ {
      for (auto element: role_edit["role_codes"]) {
        _role_codes.push_back(element.get<std::string>());
      };
    }
    _role.set_role_codes(_role_codes);
    // insert
    store::role_entity.set(_role.get_id(),store::role_to_tuple(_role));
  } else {
    // do nothing...
    err_msg = "error find";
  }

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = err_msg;
  ret["data"];

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_07(Response response, Request request) {
  log_ptr->info(interface::path("07"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "meow meow meow~";
  for (auto e : store::role_entity.db_) {
    nlohmann::json _1;
    auto _2 = store::tuple_to_role(e.second);
    _1["role_id"] = _2.get_id();
    _1["role_name"] = _2.get_name();
    for (auto role_code : _2.get_role_codes()) {
      _1["role_codes"].push_back(role_code);
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

void services::interface_route_10(Response response, Request request) {
  log_ptr->info(interface::path("10"));
  log_ptr->info((request->content).string());

  nlohmann::json ret;
  ret["code"] = 200;
  ret["err_msg"] = "no";
  ret["data"];
  for (auto element : store::user_entity.db_) {
    nlohmann::json _;
    auto _user = store::tuple_to_user(element.second);
    _["user_id"] = _user.get_id();
    _["user_name"] = _user.get_name();
    _["role_id"] = _user.get_role().get_id();
    _["role_name"] = _user.get_role().get_name();
    ret["data"].push_back(_);
  }

  log_ptr->info(ret.dump());
  response->write(ret.dump());
}

void services::interface_route_11(Response response, Request request) {
  log_ptr->info(interface::path("11"));
  log_ptr->info((request->content).string());

  nlohmann::json user_add = nlohmann::json::parse(request->content);
  int i = 0;
//  for (auto element : user::entity.db_ ) {
//    if (i == element.first ) {
//      i = element.first + 1;
//    }
//  }
//  user::format _;
//  auto [user_name,role_id,role_name] = _;
//  user_name = user_add["user_name"].dump();
//  role_id = std::atoi(user_add["user_type"].dump().c_str());
//  role_name = "admin";
//  user::entity.set(i,_);

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
