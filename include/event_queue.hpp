#ifndef COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_
#define COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_

#include <cstdint>
#include <fstream>
#include <vector>

#include "event.hpp"
#include "event_factory.hpp"
#include "exceptions.hpp"
#include "time.hpp"

namespace computer_club {
class EventQueue {
 public:
  EventQueue(std::ifstream&, size_t);
  ~EventQueue();

  std::vector<std::shared_ptr<Event>>::iterator begin();
  std::vector<std::shared_ptr<Event>>::iterator end();

  std::shared_ptr<Event> const& operator[](int) const;
  size_t Size() const;

 private:
  const std::regex kRule;
  std::vector<std::shared_ptr<Event>> queue_;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_
