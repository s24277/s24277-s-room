#include <iostream>

int liczba;
auto main () -> int
{
std::cout << "Fizz or Buzz?\n";
std::cout << "Podaj Liczbe:\n";
std::cin >> liczba;
for(int i=1; i<=liczba; i++ )
{
if((i % 15) ==0)
std::cout << i << " FizzBuzz\n";
else if((i % 3) ==0)
std::cout << i << " Fizz\n";
else if((i % 5) ==0)
std::cout << i << " Buzz\n";
else
std::cout << i << "\n";
}


return 0;
}
