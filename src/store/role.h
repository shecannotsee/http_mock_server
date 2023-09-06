//
// Created by shecannotsee on 23-9-6.
//

#ifndef HTTP_MOCK_SERVER_ROLE_H
#define HTTP_MOCK_SERVER_ROLE_H

#include <string>
#include <utility>
#include <vector>
namespace store {

class role {
 public:
  explicit role(int id, std::string name, std::vector<std::string> role_code)
      : id_(id),
        name_(std::move(name)),
        role_codes_(std::move(role_code)) {};

 private:
  int id_;
  std::string name_;
  std::vector<std::string> role_codes_;

 public:
  auto get_id() const -> decltype(int{0}) {
    return this->id_;
  }

  void set_id(int id) {
    this->id_ = id;
  }

  auto get_name() const -> decltype(std::string()) {
    return this->name_;
  }

  void set_name(std::string name) {
    this->name_ = std::move(name);
  }

  auto get_role_codes() const -> decltype(std::vector<std::string>()) {
    return this->role_codes_;
  }

  void set_role_codes(std::vector<std::string> role_codes) {
    this->role_codes_ = std::move(role_codes);
  }

};
}


#endif //HTTP_MOCK_SERVER_ROLE_H
