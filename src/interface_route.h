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
