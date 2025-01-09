#ifndef COMPUTERCLUB_INCLUDE_COMPUTERCLUBPARAMS_HPP_
#define COMPUTERCLUB_INCLUDE_COMPUTERCLUBPARAMS_HPP_

#include <cinttypes>
#include <fstream>
#include <regex>
#include <string>

#include "exceptions.hpp"
#include "time.hpp"

namespace computer_club {
class ComputerClubParams {
 public:
  ComputerClubParams(std::ifstream&);
  ComputerClubParams(size_t, const Time&, const Time&, uint32_t);
  ~ComputerClubParams();

  size_t num_of_tables;
  Time open_time;
  Time close_time;
  uint32_t hourly_fee;

 private:
  inline static const std::string kStrEnd{"\r?"};
  inline static const std::regex kTableNum{"\\d+" + kStrEnd};
  inline static const std::regex kOperatingTime{Time::kStringRule + ' ' +
                                                Time::kStringRule + kStrEnd};
  inline static const std::regex kHourlyFee{"\\d+" + kStrEnd};
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_COMPUTERCLUBPARAMS_HPP_
