#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  if (argc != 3) {
    std::cout << "wrong number of arguments\n";
    return 1;
  }

  auto const a = std::stoi(argv[1]);
  auto const b = std::stoi(argv[2]);

  if (b == 0) {
    std::cout << "Nie dzielimy przez 0\n";
  } else {
    std::cout << (a / b) << "\n";
  }
  return 0;
}
