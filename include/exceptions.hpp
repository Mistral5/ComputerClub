#ifndef TAPESORT_INCLUDE_EXCEPTIONS_HPP_
#define TAPESORT_INCLUDE_EXCEPTIONS_HPP_

#include <exception>
#include <string>

namespace computer_club {
class InvalidDataException : public std::exception {
 public:
  explicit InvalidDataException(const std::string& data) : message_{data} {};
  explicit InvalidDataException(const std::vector<std::string>& data) {
    for (auto i : data) message_ += i + ' ';
  };

  const char* what() const throw() override { return message_.c_str(); }

 private:
  std::string message_;
};

class InvalidTimeDataException : public std::exception {
 public:
  explicit InvalidTimeDataException(uint16_t minutes)
      : message_{"\"" + std::to_string(minutes) + "\" " + exc_msg_} {};

  explicit InvalidTimeDataException(uint8_t hours, uint8_t minutes)
      : message_{"\"" + std::to_string(hours) + ":" + std::to_string(minutes) +
                 "\" " + exc_msg_} {};

  const char* what() const throw() override { return message_.c_str(); }

 private:
  inline static const std::string exc_msg_{"cannot be converted to Time type!"};
  std::string message_;
};
}  // namespace computer_club

#endif  // TAPESORT_INCLUDE_EXCEPTIONS_HPP_