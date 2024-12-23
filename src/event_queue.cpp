#include "event_queue.hpp"

computer_club::EventQueue::EventQueue(std::ifstream &stream) {
  std::vector<std::string> input_args;

  while (!stream.eof()) {
    std::string input;

    while (getline(stream, input, '\n')) {
      input_args.push_back(input);
    }
  }

  prev_event_ = Time(input_args[0].substr(0, 5));
  EventFactory factory;

  for (std::string str : input_args) {
    if (!std::regex_match(str, rule_)) {
      throw InvalidDataException(str);
    }

    std::stringstream ss(str);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> elems(begin, end);

    if (prev_event_ > Time(elems[0])) {
      throw InvalidDataException(str);
    }
    prev_event_ = elems[0];

    std::shared_ptr<Event> curr = factory.Create(elems);
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

size_t computer_club::EventQueue::size() const { return queue_.size(); }
