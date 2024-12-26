#include <gtest/gtest.h>

#include <vector>

#include "computer_club.hpp"
#include "computer_club_params.hpp"
#include "event_queue.hpp"
#include "time.hpp"

TEST(time, output_case) {
  // Arrange
  using computer_club::Time;

  std::vector<Time> times = {Time(610), Time(10, 10), Time("10:10")};
  times.push_back(times[0]);

  for (Time time : times) {
    // Assert
    EXPECT_EQ(time, Time("10:10"));
  }
}

TEST(time, comparison_case) {
  // Arrange
  using computer_club::Time;

  // Act
  Time time_early_am("00:00");
  Time time_am("03:17");
  Time time_pm("12:01");
  Time time_late_pm("23:59");

  // Assert
  EXPECT_EQ(time_am == time_am, true);
  EXPECT_EQ(time_am != time_am, false);
  EXPECT_EQ(time_am == time_pm, false);

  EXPECT_EQ(time_early_am < time_am, true);
  EXPECT_EQ(time_early_am < time_pm, true);
  EXPECT_EQ(time_early_am < time_late_pm, true);

  EXPECT_EQ(time_am > time_early_am, true);
  EXPECT_EQ(time_am > time_pm, false);
  EXPECT_EQ(time_am > time_late_pm, false);

  EXPECT_EQ(time_late_pm <= time_early_am, false);
  EXPECT_EQ(time_late_pm <= time_pm, false);
  EXPECT_EQ(time_late_pm >= time_late_pm, true);
}

using computer_club::ComputerClub;
using computer_club::ComputerClubParams;
using computer_club::Time;

TEST(computer_club, is_open_test) {
  {
    // Arrange
    Time open_time("12:00");
    Time close_time("16:00");
    ComputerClubParams params(0, open_time, close_time, 0);
    ComputerClub club(params);

    // Assert
    EXPECT_EQ(club.IsOpenAt(Time("08:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("14:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("20:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("12:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("16:00")), false);
  }
  {
    // Arrange
    Time open_time("08:00");
    Time close_time("20:00");
    ComputerClubParams params(0, open_time, close_time, 0);
    ComputerClub club(params);

    // Assert
    EXPECT_EQ(club.IsOpenAt(Time("04:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("12:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("22:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("02:00")), false);
  }
  {
    // Arrange
    Time open_time("23:00");
    Time close_time("00:20");
    ComputerClubParams params(0, open_time, close_time, 0);
    ComputerClub club(params);

    // Assert
    EXPECT_EQ(club.IsOpenAt(Time("22:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("23:30")), true);
    EXPECT_EQ(club.IsOpenAt(Time("00:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("03:00")), false);
  }
  {
    // Arrange
    Time open_time("15:00");
    Time close_time("12:00");
    ComputerClubParams params(0, open_time, close_time, 0);
    ComputerClub club(params);

    // Assert
    EXPECT_EQ(club.IsOpenAt(Time("11:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("14:30")), false);
    EXPECT_EQ(club.IsOpenAt(Time("16:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("12:00")), false);
    EXPECT_EQ(club.IsOpenAt(Time("15:00")), true);
  }
  {
    // Arrange
    Time open_time("00:00");
    Time close_time("00:01");
    ComputerClubParams params(0, open_time, close_time, 0);
    ComputerClub club(params);

    // Assert
    EXPECT_EQ(club.IsOpenAt(Time("23:59")), false);
    EXPECT_EQ(club.IsOpenAt(Time("00:00")), true);
    EXPECT_EQ(club.IsOpenAt(Time("00:01")), false);
  }
}

TEST(time, arithmetic) {
  // Arrange
  using computer_club::Time;

  // Act
  Time time_early_am("00:00");
  Time time_am("03:17");
  Time time_pm("12:01");
  Time time_late_pm("23:59");

  // Assert
  EXPECT_EQ(time_early_am.distanceTo(time_am), time_am);
  EXPECT_EQ(time_early_am.distanceTo(time_late_pm), time_late_pm);

  EXPECT_EQ(time_pm.distanceTo(time_am), Time("15:16"));
  EXPECT_EQ(time_pm.distanceTo(time_late_pm), Time("11:58"));

  Time a1("10:00");
  Time a2("10:00");
  Time a3 = a1 + a2;
  EXPECT_EQ(a3, Time("20:00"));

  a1 += a2;
  EXPECT_EQ(a1, Time("20:00"));
}
