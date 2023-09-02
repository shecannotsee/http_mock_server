//
// Created by shecannotsee on 23-9-2.
//
#include <iostream>
#include <future>
#include <log_wrapper.h>
#include <http_wrapper.h>
#include <unistd.h>

int main() {
  std::async(std::launch::async,[](){
    logModule::defaultSetting();
    logModule::registerLogger("main");
    auto main_log = logModule::getLogger("main");
  });

  http_server enity;
  enity.start();

  return 0;
};
