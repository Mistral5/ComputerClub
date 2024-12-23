#ifndef COMPUTERCLUB_INCLUDE_TIME_HPP_
#define COMPUTERCLUB_INCLUDE_TIME_HPP_

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

#include "exceptions.hpp"

namespace computer_club {

const uint8_t kHoursInADay = 24;
const uint8_t kMinsInAHour = 60;
constexpr uint16_t kMinsInADay = kHoursInADay * kMinsInAHour;

class Time {
 public:
  Time(const Time &);
  Time(const std::string &);
  Time(uint8_t hours, uint8_t minutes);
  Time(uint16_t minutes = 0);

  Time &operator=(const Time &);

  ~Time() = default;

  Time operator+(const Time &) const;
  Time &operator+=(const Time &);

  bool operator==(const Time &) const;
  bool operator<(const Time &) const;
  bool operator>(const Time &) const;
  bool operator<=(const Time &) const;
  bool operator>=(const Time &) const;

  Time distanceTo(const Time &) const;
  uint32_t getHoursRoundedUp() const;
  uint8_t getHours() const;
  uint8_t getMinutes() const;
  std::pair<uint8_t, uint8_t> getBoth() const;

  inline static const std::string str_rule_{"[0-2][0-9]:[0-5][0-9]"};

 private:
  inline static const std::regex rule_{str_rule_};
  uint16_t min_;
};

std::ostream &operator<<(std::ostream &, const Time &);
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_TIME_HPP_
