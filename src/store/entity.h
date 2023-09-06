//
// Created by shecannotsee on 23-9-6.
//

#ifndef HTTP_MOCK_SERVER_ENTITY_H
#define HTTP_MOCK_SERVER_ENTITY_H

#include <memory_store/she_memory_ky.h>
#include "role.h"
#include "user.h"

namespace store {

static int role_key = 1;
using n_role = std::tuple<int,std::string,std::vector<std::string>>;
static she_memory_ky<int, n_role> role_entity = {
  {role_key,{role_key,"admin",{"baseInfo",
                               "statusQuery",
                               "faultAlarm",
                               "versionInfo",
                               "logsManage",
                               "config",
                               "resetSettings",
                               "performance",
                               "remoteUpgrade",
                               "account",
                               "role",
                               "webLogs"}}}
};

static n_role role_2_tuple(role _) {
  n_role ret;
  std::get<0>(ret) = _.get_id();
  std::get<1>(ret) = _.get_name();
  std::get<2>(ret) = _.get_role_codes();
  return ret;
}
static role tuple_2_role(n_role _) {
  return role(
    std::get<0>(_),
    std::get<1>(_),
    std::get<2>(_));
}

static int user_key = 1;
using n_user = std::tuple<int,std::string,std::string,n_role>;
static she_memory_ky<int, n_user> user_entity = {
  {user_key,{user_key,"test1","123456",{role_key,"admin",{"baseInfo",
                                            "statusQuery",
                                            "faultAlarm",
                                            "versionInfo",
                                            "logsManage",
                                            "config",
                                            "resetSettings",
                                            "performance",
                                            "remoteUpgrade",
                                            "account",
                                            "role",
                                            "webLogs"}}}}
};

static n_user user_type_conversion(user _) {
  n_user ret;
  std::get<0>(ret) = _.get_id();
  std::get<1>(ret) = _.get_name();
  std::get<2>(ret) = _.get_password();
  auto _1 = role_2_tuple(_.get_role());
  (std::get<3>(ret)) = _1;
  return ret;
}
static user tuple_to_user(n_user _) {
  return user(
    std::get<0>(_),
    std::get<1>(_),
    std::get<2>(_),
    tuple_2_role(std::get<3>(_))
    );
};


} // namespace store

#endif //HTTP_MOCK_SERVER_ENTITY_H
