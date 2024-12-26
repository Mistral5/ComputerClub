#include "outgoing_events.hpp"

using EventId = computer_club::OutgoingEventId;

computer_club::ClientFromQueueLeft::ClientFromQueueLeft(const Time &time,
                                                        const Client &client)
    : Event(time, EventId::ClientFromQueueLeft), client(client) {}

computer_club::ClientFromQueueLeft::~ClientFromQueueLeft() = default;

std::ostream &computer_club::ClientFromQueueLeft::Print(
    std::ostream &os) const {
  return os << time << ' ' << id << ' ' << client;
}

computer_club::ClientFromQueueSatDown::ClientFromQueueSatDown(
    const Time &time, const Client &client, size_t table_id)
    : Event(time, EventId::ClientFromQueueSatDown),
      client(client),
      table_id(table_id) {}

computer_club::ClientFromQueueSatDown::~ClientFromQueueSatDown() = default;

std::ostream &computer_club::ClientFromQueueSatDown::Print(
    std::ostream &os) const {
  return os << time << ' ' << id << ' ' << client << ' ' << table_id;
}

computer_club::Error::Error(const Time &time, const std::string &message)
    : Event(time, EventId::Error), message_(message) {}

computer_club::Error::~Error() = default;

std::ostream &computer_club::Error::Print(std::ostream &os) const {
  return os << time << ' ' << id << ' ' << message_;
}
