#ifndef COMPUTERCLUB_INCLUDE_INCOMINGEVENTS_HPP_
#define COMPUTERCLUB_INCLUDE_INCOMINGEVENTS_HPP_

#include <string>
#include <vector>

#include "client.hpp"
#include "event.hpp"
#include "exceptions.hpp"
#include "time.hpp"

namespace computer_club {

class IncomingEventId {
 public:
  static const size_t ClientCameIn = 1UL;
  static const size_t ClientSatDown = 2UL;
  static const size_t ClientIsWaiting = 3UL;
  static const size_t ClientLeft = 4UL;
};

class ClientCameIn : public Event {
 public:
  ClientCameIn(const std::vector<std::string> &);
  ClientCameIn(const Time &, const Client &);
  ~ClientCameIn();

  std::ostream &Print(std::ostream &os) const override;

  Client client_;
};

class ClientSatDown : public Event {
 public:
  ClientSatDown(const std::vector<std::string> &);
  ClientSatDown(const Time &, const Client &, size_t);
  ~ClientSatDown();

  std::ostream &Print(std::ostream &) const override;

  Client client_;
  size_t table_id_;
};

class ClientIsWaiting : public Event {
 public:
  ClientIsWaiting(const std::vector<std::string> &);
  ClientIsWaiting(const Time &, const Client &);
  ~ClientIsWaiting();

  std::ostream &Print(std::ostream &) const override;

  Client client_;
};

class ClientLeft : public Event {
 public:
  ClientLeft(const std::vector<std::string> &);
  ClientLeft(const Time &, const Client &);
  ~ClientLeft();

  std::ostream &Print(std::ostream &) const override;

  Client client_;
};

}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_INCOMINGEVENTS_HPP_
