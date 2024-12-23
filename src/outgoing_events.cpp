#include "outgoing_events.hpp"

using EventId = computer_club::OutgoingEventId;

computer_club::ClientFromQueueLeft::ClientFromQueueLeft(const Time &time,
                                                        const Client &client)
    : Event(time, EventId::ClientFromQueueLeft), client_(client) {}

computer_club::ClientFromQueueLeft::~ClientFromQueueLeft() = default;

std::ostream &computer_club::ClientFromQueueLeft::Print(
    std::ostream &os) const {
  return os << time_ << ' ' << id_ << ' ' << client_;
}

computer_club::ClientFromQueueSatDown::ClientFromQueueSatDown(
    const Time &time, const Client &client, size_t table)
    : Event(time, EventId::ClientFromQueueSatDown),
      client_(client),
      table_(table) {}

computer_club::ClientFromQueueSatDown::~ClientFromQueueSatDown() = default;

std::ostream &computer_club::ClientFromQueueSatDown::Print(
    std::ostream &os) const {
  return os << time_ << ' ' << id_ << ' ' << client_ << ' ' << table_;
}

computer_club::Error::Error(const Time &time, const std::string &message)
    : Event(time, EventId::Error), message_(message) {}

computer_club::Error::~Error() = default;

std::ostream &computer_club::Error::Print(std::ostream &os) const {
  return os << time_ << ' ' << id_ << ' ' << message_;
}
