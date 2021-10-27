#include <iostream>
#include <string>
#include <algorithm>


auto main(int argc, char *argv[]) -> int 
{
auto args = std::vector<std::string>{};
std::copy_n(argv,argc,std::back_inserter(args));

// jezeli litera to zrob to
if(argv[1] == "-r" && argv[2] == "-l" || argv[1] == "-l" && argv[2] == "-r"))
{
std::reverse (vec.begin(), vec.end());

for (auto const& each :args)
{std::cout << each << "\n";

}
else if(argv[1] == "-r" && argv[2] == "-n" || argv[1] == "-n" && argv[2] == "-r"))
{
std::reverse (vec.begin(), vec.end());

for (auto const& each :args)
{std::cout << each ;

}
else if(argv[1] == "-n")
{
for (auto const& each :args)
std::cout << each ;
}
else if(argv[1] == "-r")
{
std::reverse (vec.begin(), vec.end());

for (auto const& each :args)
{std::cout << each <<;

}
else if(argv[1] == "-l")
{
for (auto const& each :args)
{std::cout << each << "\n";

}
else 
{
for (auto const& each :args)
{std::cout << each << "\n";

}




return 0;
}
