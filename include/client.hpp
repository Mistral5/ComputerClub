#ifndef COMPUTERCLUB_INCLUDE_CLIENT_HPP_
#define COMPUTERCLUB_INCLUDE_CLIENT_HPP_

#include <iostream>
#include <regex>
#include <string>

#include "exceptions.hpp"

namespace computer_club {
class Client {
 public:
  Client();
  Client(const std::string &);
  ~Client();

  bool operator==(const Client &) const;
  friend std::ostream &operator<<(std::ostream &, const Client &);
  friend bool operator<(const Client &, const Client &);

  bool name_is_valid(const std::string &);

  inline static const std::string str_rule_{"(([0-9]*[a-z]*?_?-*)*)"};

 private:
  inline static const std::regex rule_{str_rule_};
  std::string name_;
};

std::ostream &operator<<(std::ostream &, const Client &);
bool operator<(const Client &, const Client &);

}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_CLIENT_HPP_
