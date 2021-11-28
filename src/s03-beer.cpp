#include <iostream>
int i;
auto main() -> int {
  for (int i = 99; i > 0; i--) {
    if (i == 1) {
      std::cout << i << " bottle of beer on the wall," << i
                << " bottle of beer.\n";
      std::cout << "Take one down, pass it around, no more bottles of beer on "
                   "the wall...\n";
    } else if (i >= 1) {
      std::cout << i << " bottles of beer on the wall," << i
                << " bottles of beer.\n";
      std::cout << "Take one down, pass it around," << i - 1
                << "bottles of beer on the wall...\n";
    }
  }
  std::cout
      << "No more bottles of beer on the wall, no more bottles of beer.\n";
  std::cout << "Go to the store and buy some more, 99 bottles of beer on the "
               "wall...\n";

  return 0;
}
