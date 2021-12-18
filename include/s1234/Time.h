#ifndef S1234_Time_H
#define S1234_Time_H

#include <iostream>
#include <sstream>
#include <string>
struct Time {
  int ht;
  int mt;
  int st;

  Time(int h, int m, int s) {
    ht = h;
    mt = m;
    st = s;
  }
  auto to_string() const -> std::string;
  auto next_second();
  auto next_minute();
  auto next_hour();
};

#endif
