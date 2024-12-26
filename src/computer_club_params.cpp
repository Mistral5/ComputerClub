#include "computer_club_params.hpp"

computer_club::ComputerClubParams::ComputerClubParams(std::ifstream& stream) {
  // table num
  std::string str_table_num;
  std::getline(stream, str_table_num);

  if (!regex_match(str_table_num, kTableNum)) {
    throw InvalidDataException(str_table_num);
  }

  num_of_tables = std::stoul(str_table_num);

  // operating time
  std::string str_operating_time;
  std::getline(stream, str_operating_time);

  if (!regex_match(str_operating_time, kOperatingTime)) {
    throw InvalidDataException(str_operating_time);
  }

  try {
    open_time = Time(str_operating_time.substr(0, 5));
    close_time = Time(str_operating_time.substr(6, 5));
  } catch (const InvalidDataException& e) {
    std::cerr << str_operating_time << std::endl;
    return;
  }

  // hourly fee
  std::string str_hourly_fee;
  std::getline(stream, str_hourly_fee);

  if (!regex_match(str_hourly_fee, kHourlyFee)) {
    throw InvalidDataException(str_hourly_fee);
  }

  hourly_fee = std::stoul(str_hourly_fee);
}

computer_club::ComputerClubParams::ComputerClubParams(size_t num_of_tables,
                                                      const Time& open_time,
                                                      const Time& close_time,
                                                      uint32_t hourly_fee)
    : num_of_tables(num_of_tables),
      open_time(open_time),
      close_time(close_time),
      hourly_fee(hourly_fee) {}

computer_club::ComputerClubParams::~ComputerClubParams() = default;
