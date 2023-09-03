//
// Created by shecannotsee on 23-9-3.
//

#ifndef HTTP_MOCK_SERVER_SHE_MEMORY_KY_H
#define HTTP_MOCK_SERVER_SHE_MEMORY_KY_H

#include <tuple>
#include <unordered_map>

template<typename T_Key,typename T_Value>
class she_memory_ky {
 private:
  std::unordered_map<T_Key,T_Value> db_;

 public:
  std::tuple<bool,T_Value> get(T_Key key) {
    if (db_.find(key)) {
      return std::make_tuple(true,db_[key]);
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
