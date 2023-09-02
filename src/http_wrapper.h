//
// Created by shecannotsee on 23-9-2.
//

#ifndef HTTP_MOCK_SERVER_HTTP_WRAPPER_H
#define HTTP_MOCK_SERVER_HTTP_WRAPPER_H

#include <string>
#include <memory>

#include <nlohmann/json.hpp>
#include <server_http.hpp>
#include <asio.hpp>
#include <log_wrapper.h>

class http_server {
  using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
  using Response   = std::shared_ptr<HttpServer::Response>;
  using Request    = std::shared_ptr<HttpServer::Request>;
 public:
  // copy:off
  http_server(const http_server&) = delete;
  http_server& operator=(const http_server&) = delete;
  // move:off
  http_server(http_server&&) = delete;
  http_server& operator=(http_server&&) = delete;
  // destructors
  ~http_server() = default;
  // constructors
  http_server() = default;

 private:
  HttpServer http_server_;

 public:
  // register rest api
  void register_rest_api();

  // server start
  void start();

};


#endif //HTTP_MOCK_SERVER_HTTP_WRAPPER_H
