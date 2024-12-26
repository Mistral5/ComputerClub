#include "incoming_events.hpp"

using EventId = computer_club::IncomingEventId;

// ClientCameIn
computer_club::ClientCameIn::ClientCameIn(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id != EventId::ClientCameIn) {
    throw InvalidDataException(str);
  }

  client = str[2];
}

computer_club::ClientCameIn::ClientCameIn(const Time& time,
                                          const Client& client)
    : Event(time, EventId::ClientCameIn), client(client) {}

computer_club::ClientCameIn::~ClientCameIn() = default;

std::ostream& computer_club::ClientCameIn::Print(std::ostream& os) const {
  return os << time << ' ' << id << ' ' << client;
}

// ClientSatDown
computer_club::ClientSatDown::ClientSatDown(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 4 || id != EventId::ClientSatDown) {
    throw InvalidDataException(str);
  }

  client = str[2];
  table_id = std::stoul(str[3]);
}

computer_club::ClientSatDown::ClientSatDown(const Time& time,
                                            const Client& client,
                                            size_t table_id)
    : Event(time, EventId::ClientSatDown), client(client), table_id(table_id) {}

computer_club::ClientSatDown::~ClientSatDown() = default;

std::ostream& computer_club::ClientSatDown::Print(std::ostream& os) const {
  return os << time << ' ' << id << ' ' << client << ' ' << table_id;
}

// ClientIsWaiting
computer_club::ClientIsWaiting::ClientIsWaiting(
    const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id != EventId::ClientIsWaiting) {
    throw InvalidDataException(str);
  }

  client = str[2];
}

computer_club::ClientIsWaiting::ClientIsWaiting(const Time& time,
                                                const Client& client)
    : Event(time, EventId::ClientIsWaiting), client(client) {}

computer_club::ClientIsWaiting::~ClientIsWaiting() = default;

std::ostream& computer_club::ClientIsWaiting::Print(std::ostream& os) const {
  return os << time << ' ' << id << ' ' << client;
}

// ClientLeft
computer_club::ClientLeft::ClientLeft(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id != EventId::ClientLeft) {
    throw InvalidDataException(str);
  }

  client = str[2];
}

computer_club::ClientLeft::ClientLeft(const Time& time, const Client& client)
    : Event(time, EventId::ClientLeft), client(client) {}

computer_club::ClientLeft::~ClientLeft() = default;

std::ostream& computer_club::ClientLeft::Print(std::ostream& os) const {
  return os << time << ' ' << id << ' ' << client;
}
