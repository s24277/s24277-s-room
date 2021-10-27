#include <iostream>
#include <random>

std::random_device rd;
std::uniform_int_distribution<int> liczba (1, 100);
auto const x =  liczba(rd);
int strzal;
auto main() -> int
{
std::cout << "Do you want to play a game?\n" ;

while(x != strzal)
{
std::cout << "Choose your number (1 - 100)\n";
std::cin >> strzal;
if(strzal == 69)
std::cout << "NICE\n";
if(strzal > x)
std::cout << "too big!\n";
else if(strzal < x)
std::cout << "too small!\n";
}
std::cout << "Well Done!\n";
return 0;
}
