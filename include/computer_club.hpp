#ifndef COMPUTERCLUB_INCLUDE_COMPUTERCLUB_HPP_
#define COMPUTERCLUB_INCLUDE_COMPUTERCLUB_HPP_

#include <cstdint>
#include <forward_list>
#include <list>
#include <queue>
#include <set>
#include <vector>

#include "client.hpp"
#include "computer_club_params.hpp"
#include "event.hpp"
#include "event_queue.hpp"
#include "incoming_events.hpp"
#include "outgoing_events.hpp"
#include "table.hpp"
#include "time.hpp"

namespace computer_club {

using TableId = size_t;  // "0" if in a club, ">0" if at a table.

class ComputerClub {
 public:
  ComputerClub(const ComputerClubParams &);
  ~ComputerClub();

  bool IsOpenAt(const Time &) const;
  void ProcessEvent(const Event &);

  void ProcessQueue(EventQueue &);

  void Process(const ClientCameIn &);
  void Process(const ClientSatDown &);
  void Process(const ClientIsWaiting &);
  void Process(const ClientLeft &);

  void PrintStat();

 private:
  void KickEveryone();
  void ClearTable(const Client &, const Time &, TableId);

  std::queue<Client> client_queue_;
  std::map<Client, TableId> clients_;
  std::vector<Table> tables_;

  ComputerClubParams params_;
};
}  // namespace computer_club

#endif  // COMPUTERCLUB_INCLUDE_COMPUTERCLUB_HPP_
