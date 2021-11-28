#include <iostream>

int liczba;
int main() {
  std::cout << "Podaj liczbe:";
  std::cin >> liczba;
  for (int i = liczba; i >= 0; i--) {
    std::cout << i << "...\n";
  }
  return 0;
}
