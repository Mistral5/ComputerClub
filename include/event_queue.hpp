#ifndef COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_
#define COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_

#include <cstdint>
#include <fstream>
#include <vector>

#include "client.hpp"
#include "event.hpp"
#include "event_factory.hpp"
#include "exceptions.hpp"
#include "time.hpp"

namespace computer_club {
class EventQueue {
 public:
  EventQueue(std::ifstream&);
  ~EventQueue();

  std::vector<std::shared_ptr<Event>>::iterator begin();
  std::vector<std::shared_ptr<Event>>::iterator end();

  std::shared_ptr<Event> const& operator[](int index) const;
  size_t size() const;

 private:
  inline static const std::regex rule_{Time::str_rule_ + " \\d " +
                                       Client::str_rule_ + " ?\\d?\r?"};
  std::vector<std::shared_ptr<Event>> queue_;

  Time prev_event_;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_EVENTQUEUE_HPP_
