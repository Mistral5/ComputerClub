#ifndef COMPUTERCLUB_INCLUDE_EVENTFACTORY_HPP_
#define COMPUTERCLUB_INCLUDE_EVENTFACTORY_HPP_

#include <cstdint>
#include <string>
#include <vector>

#include "client.hpp"
#include "event.hpp"
#include "exceptions.hpp"
#include "incoming_events.hpp"
#include "outgoing_events.hpp"

namespace computer_club {
class EventFactory {
 public:
  std::shared_ptr<Event> Create(const std::vector<std::string>& str_event) {
    switch (std::stoul(str_event[1])) {
      case IncomingEventId::ClientCameIn:
        return std::shared_ptr<Event>(
            std::make_shared<ClientCameIn>(str_event));

      case IncomingEventId::ClientSatDown:
        return std::shared_ptr<Event>(
            std::make_shared<ClientSatDown>(str_event));

      case IncomingEventId::ClientIsWaiting:
        return std::shared_ptr<Event>(
            std::make_shared<ClientIsWaiting>(str_event));

      case IncomingEventId::ClientLeft:
        return std::shared_ptr<Event>(std::make_shared<ClientLeft>(str_event));

      default:
        throw InvalidDataException(str_event);
    }
  };
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_EVENTFACTORY_HPP_
