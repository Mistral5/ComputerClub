#include <fstream>
#include <iostream>
#include <queue>
#include <set>

#include "client.hpp"
#include "computer_club.hpp"
#include "computer_club_params.hpp"
#include "event_factory.hpp"
#include "event_queue.hpp"
#include "time.hpp"

// обновить define guard
// ~/.vs/ComputerClub/build$ cmake --build . && ./bin/ComputerClub

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Wrong number of arguments!" << std::endl;
    return 1;
  }

  std::ifstream test_stream(argv[1]);

  if (!test_stream.is_open()) {
    std::cout << "Can't open test file!" << std::endl;
    return 1;
  }

  try {
    computer_club::ComputerClubParams club_params(test_stream);

    computer_club::EventQueue event_queue(test_stream,
                                          computer_club::Client::str_rule_,
                                          club_params.num_of_tables);

    computer_club::ComputerClub computer_club(club_params);

    computer_club.ProcessQueue(event_queue);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}