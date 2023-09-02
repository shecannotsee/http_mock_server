//
// Created by shecannotsee on 23-9-2.
//
#include "http_wrapper.h"

void http_server::register_rest_api() {

}

void http_server::start() {
  this->register_rest_api();
  http_server_.start();
}
