#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  if (argc == 0) {
    return 1;
  }
  auto const password = std::string{argv[1]};
  std::cout << "Hasło: \n";

  auto name = std::string{};
  std::getline(std::cin, name);

  while (name != password) {
    std::cout << "Hasło: \n";
    std::getline(std::cin, name);
  }
  std::cout << "Pomyślnie zalogowano\n";
  return 0;
}
