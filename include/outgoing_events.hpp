#ifndef COMPUTERCLUB_INCLUDE_OUTGOINGEVENTS_HPP_
#define COMPUTERCLUB_INCLUDE_OUTGOINGEVENTS_HPP_

#include <string>
#include <vector>

#include "client.hpp"
#include "event.hpp"
#include "time.hpp"

namespace computer_club {

class OutgoingEventId {
 public:
  static const size_t ClientFromQueueLeft = 11UL;
  static const size_t ClientFromQueueSatDown = 12UL;
  static const size_t Error = 13UL;
};

class ClientFromQueueLeft : public Event {
 public:
  ClientFromQueueLeft(const Time &, const Client &);
  ~ClientFromQueueLeft();

  std::ostream &Print(std::ostream &) const override;

  Client client;
};

class ClientFromQueueSatDown : public Event {
 public:
  ClientFromQueueSatDown(const Time &, const Client &, size_t);
  ~ClientFromQueueSatDown();

  std::ostream &Print(std::ostream &) const override;

  Client client;
  size_t table_id;
};

class Error : public Event {
 public:
  Error(const Time &, const std::string &);
  ~Error();

  std::ostream &Print(std::ostream &) const override;

  const std::string message_;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_OUTGOINGEVENTS_HPP_
