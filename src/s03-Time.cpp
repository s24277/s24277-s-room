#include "../include/s1234/Time.h"
#include <iostream>
#include <string>

auto Time::next_second() {
  st = st + 1;
  if (st > 59) {
    st = 00;
    mt = mt + 1;
    if (mt > 59) {
      mt = 00;
      ht = ht + 1;
      if (ht > 23) {
        ht = 00;
      }
    }
  }
}

auto Time::next_minute() {
  mt = mt + 1;
  if (mt > 59) {
    mt = 00;
    ht = ht + 1;
    if (ht > 23) {
      ht = 00;
    }
  }
}

auto Time::next_hour() {
  ht = ht + 1;
  if (ht > 23) {
    ht = 00;
  }
}
auto Time::to_string() const -> std::string {
  auto out = std::ostringstream{};
  std::string sdd, mdd, hdd;
  if (st < 10) {
     sdd = "0";
  } else {
     sdd = "";
  }

  if (mt < 10) {
     mdd = "0";
  } else {
     mdd = "";
  }

  if (ht < 10) {
     hdd = "0";
  } else {
     hdd = "";
  }

  out << hdd << ht << ":" << mdd << mt << ":" << sdd << st << "\n";
  return out.str();
}

int main() {
  Time time(23, 58, 59);
  std::cout << time.to_string();
  time.next_second();
  std::cout << time.to_string();
  time.next_minute();
  std::cout << time.to_string();
  time.next_hour();
  std::cout << time.to_string();
}
