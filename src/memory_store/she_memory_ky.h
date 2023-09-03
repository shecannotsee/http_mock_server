//
// Created by shecannotsee on 23-9-3.
//

#ifndef HTTP_MOCK_SERVER_SHE_MEMORY_KY_H
#define HTTP_MOCK_SERVER_SHE_MEMORY_KY_H

#include <tuple>
#include <unordered_map>

template<typename T_Key,typename T_Value>
class she_memory_ky {
 public:
  she_memory_ky() = default;
  she_memory_ky(std::initializer_list<std::pair<T_Key, T_Value>> init_list) {
    for (const auto& pair : init_list) {
      db_[pair.first] = pair.second;
    }
  }
 private:
  std::unordered_map<T_Key,T_Value> db_;

 public:
  std::tuple<bool,T_Value> get(T_Key key) {
    auto it = db_.find(key);
    if (it != db_.end()) {
      return std::make_tuple(true, it->second);
    } else {
      return std::make_tuple(false,T_Value{});
    }
  };

  void set(T_Key key, T_Value value) {
    db_[key] = value;
  };

  bool get_op(std::tuple<bool,T_Value> _) {
    return std::get<0>(_);
  }

  T_Value get_value(std::tuple<bool,T_Value> _) {
    return std::get<1>(_);
  }

};


#endif //HTTP_MOCK_SERVER_SHE_MEMORY_KY_H
