#include "incoming_events.hpp"

using EventId = computer_club::IncomingEventId;

// ClientCameIn
computer_club::ClientCameIn::ClientCameIn(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id_ != EventId::ClientCameIn) {
    throw InvalidDataException(str);
  }

  client_ = str[2];
}

computer_club::ClientCameIn::ClientCameIn(const Time& time,
                                          const Client& client)
    : Event(time, EventId::ClientCameIn), client_(client) {}

computer_club::ClientCameIn::~ClientCameIn() = default;

std::ostream& computer_club::ClientCameIn::Print(std::ostream& os) const {
  return os << time_ << ' ' << id_ << ' ' << client_;
}

// ClientSatDown
computer_club::ClientSatDown::ClientSatDown(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 4 || id_ != EventId::ClientSatDown) {
    throw InvalidDataException(str);
  }

  client_ = str[2];
  table_id_ = std::stoul(str[3]);
}

computer_club::ClientSatDown::ClientSatDown(const Time& time,
                                            const Client& client,
                                            size_t table_id)
    : Event(time, EventId::ClientSatDown),
      client_(client),
      table_id_(table_id) {}

computer_club::ClientSatDown::~ClientSatDown() = default;

std::ostream& computer_club::ClientSatDown::Print(std::ostream& os) const {
  return os << time_ << ' ' << id_ << ' ' << client_ << ' ' << table_id_;
}

// ClientIsWaiting
computer_club::ClientIsWaiting::ClientIsWaiting(
    const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id_ != EventId::ClientIsWaiting) {
    throw InvalidDataException(str);
  }

  client_ = str[2];
}

computer_club::ClientIsWaiting::ClientIsWaiting(const Time& time,
                                                const Client& client)
    : Event(time, EventId::ClientIsWaiting), client_(client) {}

computer_club::ClientIsWaiting::~ClientIsWaiting() = default;

std::ostream& computer_club::ClientIsWaiting::Print(std::ostream& os) const {
  return os << time_ << ' ' << id_ << ' ' << client_;
}

// ClientLeft
computer_club::ClientLeft::ClientLeft(const std::vector<std::string>& str)
    : Event(str[0], std::stoul(str[1])) {
  if (str.size() != 3 || id_ != EventId::ClientLeft) {
    throw InvalidDataException(str);
  }

  client_ = str[2];
}

computer_club::ClientLeft::ClientLeft(const Time& time, const Client& client)
    : Event(time, EventId::ClientLeft), client_(client) {}

computer_club::ClientLeft::~ClientLeft() = default;

std::ostream& computer_club::ClientLeft::Print(std::ostream& os) const {
  return os << time_ << ' ' << id_ << ' ' << client_;
}
