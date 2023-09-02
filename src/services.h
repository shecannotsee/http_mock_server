//
// Created by shecannotsee on 23-9-2.
//

#ifndef HTTP_MOCK_SERVER_SERVICES_H
#define HTTP_MOCK_SERVER_SERVICES_H

#include <server_http.hpp>

class services {
 public:
  using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
  using Response   = std::shared_ptr<HttpServer::Response>;
  using Request    = std::shared_ptr<HttpServer::Request>;
 public:
  void interface_route_N1(Response,Request);
  void interface_route_01(Response,Request);
  void interface_route_02(Response,Request);

};


#endif //HTTP_MOCK_SERVER_SERVICES_H
