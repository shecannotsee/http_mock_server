//
// Created by shecannotsee on 23-9-2.
//

#ifndef HTTP_MOCK_SERVER_SERVICES_H
#define HTTP_MOCK_SERVER_SERVICES_H

#include <server_http.hpp>
#include "log_wrapper.h"

class services {
 public:
  services() {
    logModule::registerLogger("services");
    log_ptr = logModule::getLogger("services");
  };
 private:
  logModule::loggerPtr log_ptr;
 public:
  using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
  using Response   = std::shared_ptr<HttpServer::Response>;
  using Request    = std::shared_ptr<HttpServer::Request>;
 public:
  void interface_route_N1(Response,Request);
  void interface_route_01(Response,Request);
  void interface_route_02(Response,Request);
  void interface_route_03(Response,Request);
  void interface_route_04(Response,Request);
  void interface_route_05(Response,Request);
  void interface_route_06(Response,Request);
  void interface_route_07(Response,Request);
  void interface_route_08(Response,Request);
  void interface_route_09(Response,Request);
  void interface_route_10(Response,Request);
  void interface_route_11(Response,Request);
  void interface_route_12(Response,Request);
  void interface_route_13(Response,Request);




};


#endif //HTTP_MOCK_SERVER_SERVICES_H
