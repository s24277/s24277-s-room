#include <iostream>
#include <string>

auto main() -> int
 {
  std::cout << "Hasło: \n";

  auto name = std::string{};
  std::getline(std::cin, name);

while (name != "student")
{
std::cout << "Hasło: \n";
std::getline(std::cin, name);
}
 std::cout << "Pomyślnie zalogowano\n";
  return 0;
}
