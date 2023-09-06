//
// Created by shecannotsee on 23-9-2.
//

#ifndef HTTP_MOCK_SERVER_INTERFACE_ROUTE_H
#define HTTP_MOCK_SERVER_INTERFACE_ROUTE_H

#include <string>
#include <map>
#include <tuple>

namespace interface {
using std::string;
using std::map;
using std::tuple;

// 接口信息最好不要变更
const map<string,tuple<string,string>> route = {
      {"demo",   {"POST",   "^/xxxxx$"}}, // 接口示例
/*-1*/{"-1",     {"POST",   "^/test$"}}, // 测试接口1
/*51*/{"01",     {"POST",   "^/other/sendPicture$"}}, // 接口示例
      {"02",     {"POST",   "/rsu/configure_manage/export_configure"}},// 从服务器下载文件到前端接口
      {"03",     {"POST",   "/rsu/remote_manage/import_configure"}},// 上传文件到服务器接口
      {"04",     {"POST",   "/rsu/user_manage/login"}},// 登陆接口
      {"05",     {"POST",   "/rsu/user_manage/role_add"}  },// 角色添加
      {"06",     {"POST",   "/rsu/user_manage/role_edit"}},// 角色修改
      {"07",     {"POST",   "/rsu/user_manage/role_list"}},// 角色列表
      {"08",     {"POST",   "/rsu/configure_manage/eth_configure"}},// eth
      {"09",     {"POST",   "/rsu/configure_manage/wifi_configure"}},// wifi
      {"10",     {"POST",   "/rsu/user_manage/user_list"}},// 用户列表
      {"11",     {"POST",   "/rsu/user_manage/add_user"}},// 用户新增
      {"12",     {"POST",   "/rsu/user_manage/remove_user"}},// 用户删除
      {"13",     {"POST",   "/rsu/user_manage/user_pwd_update"}},// 用户修改密码
      {"9999999",{"POST",   "end"}} // 只是用来做末尾,无意义
};

// TODO:获取请求路径和方法函数均未做异常处理(interface::path("xxx")和interface::method("xxx")),处理请参考以下代码
//    if (route.find(i)==route.end()) {//没有该接口
//      std::cout<< "can not find interface["<<i<<"].\n";
//    } else { /*有该接口,正常返回即可*/ }
// 获取请求url
static string path(string interface_name) {
  return std::get<1>(route.find(interface_name)->second);
};
// 获取请求方法函数
static string method(const string& interface_name) {
  return std::get<0>(route.find(interface_name)->second);
};

};// namespace interface


#endif //HTTP_MOCK_SERVER_INTERFACE_ROUTE_H
