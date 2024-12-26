#ifndef COMPUTERCLUB_INCLUDE_TABLE_HPP_
#define COMPUTERCLUB_INCLUDE_TABLE_HPP_

#include "time.hpp"

namespace computer_club {
struct Table {
  // Table();
  // ~Table();

  bool occupation;
  uint32_t rental_hours;
  Time rental_time;
  Time last_session_start;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_TABLE_HPP_
