#include "time.hpp"

computer_club::Time::Time(const Time &other) : min_(other.min_) {}

computer_club::Time::Time(const std::string &str_time) {
  if (!regex_match(str_time.data(), rule_)) {
    throw InvalidDataException(str_time);
  }

  uint8_t hours = std::stoi(str_time.substr(0, 2));
  uint8_t minutes = std::stoi(str_time.substr(3, 2));

  min_ = hours * kMinsInAHour + minutes;
}

computer_club::Time::Time(uint8_t hours, uint8_t minutes) {
  if (hours >= kHoursInADay || minutes >= kMinsInAHour) {
    throw InvalidTimeDataException(hours, minutes);
  }
  min_ = hours * kMinsInAHour + minutes;
}

computer_club::Time::Time(uint16_t minutes) {
  if (minutes >= (kHoursInADay * kMinsInAHour)) {
    throw InvalidTimeDataException(minutes);
  }
  min_ = minutes;
}

computer_club::Time &computer_club::Time::operator=(const Time &other) {
  min_ = other.min_;
  return *this;
}

computer_club::Time computer_club::Time::distanceTo(const Time &other) const {
  if (other.min_ < min_) {
    return Time(kMinsInADay - min_ + other.min_);
  }
  return Time(other.min_ - min_);
}

uint32_t computer_club::Time::getHoursRoundedUp() const {
  auto pair = getBoth();
  if (pair.second) {
    ++pair.first;
  }
  return pair.first;
}

uint8_t computer_club::Time::getHours() const { return min_ / kMinsInAHour; }

uint8_t computer_club::Time::getMinutes() const { return min_ % kMinsInAHour; }

std::pair<uint8_t, uint8_t> computer_club::Time::getBoth() const {
  uint8_t hours = min_ / kMinsInAHour;
  uint8_t min = min_ - hours * kMinsInAHour;
  return std::make_pair(hours, min);
}

computer_club::Time computer_club::Time::operator+(const Time &other) const {
  uint16_t result = min_ + other.min_;
  return result > kMinsInADay ? Time(result - kMinsInADay) : Time(result);
}

computer_club::Time &computer_club::Time::operator+=(const Time &other) {
  uint16_t result = min_ + other.min_;
  min_ = result > kMinsInADay ? result - kMinsInADay : result;
  return *this;
}

bool computer_club::Time::operator==(const Time &other) const {
  return min_ == other.min_;
}

bool computer_club::Time::operator<(const Time &other) const {
  return min_ < other.min_;
}

bool computer_club::Time::operator>(const Time &other) const {
  return (other < *this);
}

bool computer_club::Time::operator<=(const Time &other) const {
  return !this->operator>(other);
}

bool computer_club::Time::operator>=(const Time &other) const {
  return !this->operator<(other);
}

std::ostream &computer_club::operator<<(std::ostream &os, const Time &time) {
  const auto &[hours, mins] = time.getBoth();

  return std::cout << std::setw(2) << std::setfill('0')
                   << static_cast<uint16_t>(hours) << ':' << std::setw(2)
                   << std::setfill('0') << static_cast<uint16_t>(mins);
}
