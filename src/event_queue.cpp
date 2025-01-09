#include "event_queue.hpp"

computer_club::EventQueue::EventQueue(std::ifstream &stream, size_t tables_num)
    : kRule(Time::kStringRule + " \\d " + Client::kStringRule + " ?\\d?\r?") {
  std::vector<std::string> input_args;

  while (!stream.eof()) {
    std::string input;

    while (getline(stream, input, '\n')) {
      input_args.push_back(input);
    }
  }

  EventFactory factory;

  for (std::string str : input_args) {
    if (!std::regex_match(str, kRule)) {
      throw InvalidDataException(str);
    }

    std::stringstream ss(str);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> elems(begin, end);

    if (elems.size() == 4) {
      size_t curr_table = std::stoul(elems[3]);
      if (1 > curr_table || curr_table > tables_num) {
        throw InvalidDataException(str);
      }
    }

    std::shared_ptr<Event> curr = factory.Create(elems);

    if ((*queue_.front()).time > (*curr).time) {
      throw InvalidDataException(str);
    }

    queue_.push_back(curr);
  }
}

computer_club::EventQueue::~EventQueue() = default;

std::vector<std::shared_ptr<computer_club::Event>>::iterator
computer_club::EventQueue::begin() {
  return std::begin(queue_);
}

std::vector<std::shared_ptr<computer_club::Event>>::iterator
computer_club::EventQueue::end() {
  return std::end(queue_);
}

std::shared_ptr<computer_club::Event> const &
computer_club::EventQueue::operator[](int index) const {
  return queue_[index];
}

size_t computer_club::EventQueue::Size() const { return queue_.size(); }
