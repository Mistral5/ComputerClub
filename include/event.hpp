#ifndef COMPUTERCLUB_INCLUDE_EVENT_HPP_
#define COMPUTERCLUB_INCLUDE_EVENT_HPP_

#include <cstdint>
#include <string>
#include <vector>

#include "client.hpp"
#include "table.hpp"
#include "time.hpp"

namespace computer_club {
class Event {
 public:
  virtual ~Event(){};

  bool operator<(const Event&) const;
  friend std::ostream& operator<<(std::ostream& os, const Event& event);

  virtual std::ostream& Print(std::ostream& os) const;

  Time time_;
  const size_t id_;

 protected:
  Event(const Time&, size_t);
};

std::ostream& operator<<(std::ostream& os, const Event& event);

}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_EVENT_HPP_
