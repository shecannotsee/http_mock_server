//
// Created by shecannotsee on 23-9-6.
//

#ifndef HTTP_MOCK_SERVER_USER_H
#define HTTP_MOCK_SERVER_USER_H

#include <string>
#include "role.h"

namespace store {
class user {
 public:
  explicit user(int id, std::string name, std::string password, role role__)
      : id_(id),
        name_(name),
        password_(password),
        role_(role__) {};

 private:
  int id_;
  std::string name_;
  std::string password_;
  role role_;

 public:
  auto get_id() const -> decltype(0) {
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

  auto get_password() const -> decltype(std::string()) {
    return this->password_;
  }

  void set_password(std::string password) {
    this->password_ = std::move(password);
  }

  auto get_role() const -> decltype(this->role_) {
    return this->role_;
  }

  void set_role (role role_1) {
    this->role_.set_id(role_1.get_id());
    this->role_.set_name(role_1.get_name());
    this->role_.set_role_codes(role_1.get_role_codes());
  }
};
}


#endif //HTTP_MOCK_SERVER_USER_H
