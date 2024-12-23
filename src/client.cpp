#include "client.hpp"

computer_club::Client::Client() : name_("") {}

computer_club::Client::Client(const std::string &str_name) {
  if (!name_is_valid(str_name)) {
    throw InvalidDataException(str_name);
  }

  name_ = str_name;
}

computer_club::Client::~Client() = default;

std::ostream &computer_club::operator<<(std::ostream &os,
                                        const Client &client) {
  return os << client.name_;
}

bool computer_club::operator<(const Client &lhs, const Client &rhs) {
  return lhs.name_ < rhs.name_;
}

bool computer_club::Client::operator==(const Client &other) const {
  return name_ == other.name_;
}

bool computer_club::Client::name_is_valid(const std::string &str_name) {
  return regex_match(str_name.data(), rule_);
}