#include "computer_club.hpp"

computer_club::ComputerClub::ComputerClub(const ComputerClubParams &params)
    : params_(params) {
  tables_.resize(params.num_of_tables + 1);
  tables_[0].occupation_ = true;
  std::cout << params_.open_time << std::endl;
}

computer_club::ComputerClub::~ComputerClub() {
  KickEveryone();
  std::cout << params_.close_time << std::endl;
  PrintStat();
}

void computer_club::ComputerClub::ProcessQueue(EventQueue &queue) {
  for (std::shared_ptr<Event> event : queue) {
    ProcessEvent(*event);
  }
}

void computer_club::ComputerClub::ProcessEvent(const Event &event) {
  switch (event.id_) {
    case IncomingEventId::ClientCameIn:
      Process(static_cast<const ClientCameIn &>(event));
      break;
    case IncomingEventId::ClientSatDown:
      Process(static_cast<const ClientSatDown &>(event));
      break;
    case IncomingEventId::ClientIsWaiting:
      Process(static_cast<const ClientIsWaiting &>(event));
      break;
    case IncomingEventId::ClientLeft:
      Process(static_cast<const ClientLeft &>(event));
      break;
    default:
      throw std::exception();
  }
}

void computer_club::ComputerClub::Process(const ClientCameIn &event) {
  std::cout << event << std::endl;

  if (!IsOpenAt(event.time_)) {
    Error outgoing(event.time_, "NotOpenYet");
    std::cout << outgoing << std::endl;
    return;
  }

  if (clients_.contains(event.client_)) {
    Error outgoing(event.time_, "YouShallNotPass");
    std::cout << outgoing << std::endl;
    return;
  }

  clients_[event.client_] = 0;
}

void computer_club::ComputerClub::Process(const ClientSatDown &event) {
  std::cout << event << std::endl;

  if (!clients_.contains(event.client_)) {
    Error outgoing(event.time_, "ClientUnknown");
    std::cout << outgoing << std::endl;
    return;
  }

  if (tables_[event.table_id_].occupation_) {
    Error outgoing(event.time_, "PlaceIsBusy");
    std::cout << outgoing << std::endl;
    return;
  }

  // Так как, я не понял, что должно произойти когда клиент из очереди сядет за
  // стол не через ID 4. Я предполагаю, что так может сделать только верхний в
  // очереди клиент, и тихо удаляю его когда он садится за стол.
  if (client_queue_.front() == event.client_) {
    client_queue_.pop();
  }

  // desk clearing
  if (clients_[event.client_]) {
    ClearTable(event.client_, event.time_, event.table_id_);
  }

  // table occupation
  tables_[event.table_id_].occupation_ = true;
  clients_[event.client_] = event.table_id_;
  tables_[event.table_id_].last_session_start_ = event.time_;
}

bool TableIsFree(const computer_club::Table &table) {
  return !table.occupation_;
}

void computer_club::ComputerClub::Process(const ClientIsWaiting &event) {
  std::cout << event << std::endl;

  if (!clients_.contains(event.client_)) {
    Error outgoing(event.time_, "ClientUnknown");
    std::cout << outgoing << std::endl;
    return;
  }

  auto result{std::find_if(begin(tables_), end(tables_), TableIsFree)};

  if (result != end(tables_)) {
    Error outgoing(event.time_, "ICanWaitNoLonger!");
    std::cout << outgoing << std::endl;
  }

  if (clients_.size() > tables_.size()) {
    ClientFromQueueLeft outgoing(event.time_, event.client_);
    std::cout << outgoing << std::endl;
    return;
  }

  client_queue_.push(event.client_);
}

void computer_club::ComputerClub::Process(const ClientLeft &event) {
  std::cout << event << std::endl;

  TableId curr_table = clients_[event.client_];

  if (!clients_.contains(event.client_)) {
    Error outgoing(event.time_, "ClientUnknown");
    std::cout << outgoing << std::endl;
    return;
  }

  // desk clearing
  ClearTable(event.client_, event.time_, curr_table);

  clients_.erase(event.client_);

  if (client_queue_.empty()) {
    return;
  }

  Client client_from_queue = client_queue_.front();
  client_queue_.pop();

  ClientFromQueueSatDown ongoing(event.time_, client_from_queue, curr_table);
  std::cout << ongoing << std::endl;

  // table occupation
  tables_[curr_table].occupation_ = true;
  clients_[client_from_queue] = curr_table;
  tables_[curr_table].last_session_start_ = event.time_;
}

void computer_club::ComputerClub::KickEveryone() {
  for (auto it = clients_.cbegin(); it != clients_.end();) {
    const auto &[client, table_id] = *it;

    if (table_id) {
      ClearTable(client, params_.close_time, table_id);
    }

    ClientFromQueueLeft event(params_.close_time, client);
    std::cout << event << std::endl;

    clients_.erase(it++);
  }
}

void computer_club::ComputerClub::ClearTable(const Client &client,
                                             const Time &time,
                                             TableId table_id) {
  Table &table = tables_[table_id];

  table.rental_hours_ +=
      table.last_session_start_.distanceTo(time).getHoursRoundedUp();
  table.rental_time_ += table.last_session_start_.distanceTo(time);
  table.occupation_ = false;
}

void computer_club::ComputerClub::TakeTable() {}

void computer_club::ComputerClub::PrintStat() {
  for (TableId id = 1; id < tables_.size(); ++id) {
    std::cout << id << ' ' << tables_[id].rental_hours_ * params_.hourly_fee
              << ' ' << tables_[id].rental_time_ << std::endl;
  }
}

bool computer_club::ComputerClub::IsOpenAt(const Time &time) const {
  if (params_.open_time <= params_.close_time) {
    if (params_.open_time <= time && time < params_.close_time) {
      return true;
    }
  } else {
    if (params_.open_time <= time || time < params_.close_time) {
      return true;
    }
  }

  return false;
}