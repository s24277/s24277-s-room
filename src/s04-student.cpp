#include "../include/s1234/Student.h"
#include <iostream>

int main() {
  Student student("Karol", "Hulanicki", "s24277", 1, 3);
  std::cout << student.imie << " " << student.nazwisko << "\n";
  std::cout << student.n_index << " " << student.semestr << " "
            << student.sr_ocen << "\n";
}
