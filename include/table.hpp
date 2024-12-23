#ifndef COMPUTERCLUB_INCLUDE_TABLE_HPP_
#define COMPUTERCLUB_INCLUDE_TABLE_HPP_

#include "time.hpp"

namespace computer_club {
class Table {
 public:
  Table();
  ~Table();

  bool occupation_;
  uint32_t rental_hours_;
  Time rental_time_;
  Time last_session_start_;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_TABLE_HPP_
