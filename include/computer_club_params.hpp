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
  ComputerClubParams(uint16_t, const Time&, const Time&, uint32_t);
  ~ComputerClubParams();

  uint16_t num_of_tables;
  Time open_time;
  Time close_time;
  uint32_t hourly_fee;

 private:
  inline static const std::string str_end_{"\r?"};
  inline static const std::regex table_num_{"\\d+" + str_end_};
  inline static const std::regex operating_time_{Time::str_rule_ + ' ' +
                                                 Time::str_rule_ + str_end_};
  inline static const std::regex hourly_fee_{"\\d+" + str_end_};
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_COMPUTERCLUBPARAMS_HPP_
