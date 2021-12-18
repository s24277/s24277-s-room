#ifndef S1234_Student_H
#define S1234_Student_H

#include <iostream>
#include <sstream>

struct Student {
  std::string imie;
  std::string nazwisko;
  std::string n_index;
  int semestr;
  int sr_ocen;

  Student(std::string i, std::string n, std::string ni, int s, int sr) {
    imie = i;
    nazwisko = n;
    n_index = ni;
    semestr = s;
    sr_ocen = sr;
  }
  auto to_string() const -> std::string;
};

#endif
