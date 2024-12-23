#include "event.hpp"

computer_club::Event::Event(const Time& time, size_t id)
    : time_(time), id_(id) {}

bool computer_club::Event::operator<(const Event&) const { return false; }

std::ostream& computer_club::operator<<(std::ostream& os, const Event& event) {
  event.Print(os);
  return os;
};

std::ostream& computer_club::Event::Print(std::ostream& os) const {
  return os << time_ << ' ' << id_;
};
