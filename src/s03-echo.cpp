#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int 
{
if(argc == 0 )
{
return 0;
}
if ((argv[1] == std::string("-r") && argv[2] == std::string("-l")) || (argv[1] == std::string("-l") && argv[2] == std::string("-r"))  )
{
for (auto i=argc - 1; i>2; i--)
{
std::cout << argv[i] << " \n";
}
}

else if ((argv[1] == std::string("-r") && argv[2] == std::string("-n")) || (argv[1] == std::string("-n") && argv[2] == std::string("-r"))  )
{
for (auto i=argc - 1; i>2; i--)
{
std::cout << argv[i] << " ";
}
}

else if (argv[1] == std::string("-n") )
{
for (auto i=2; i<argc; i++)
{
std::cout << argv[i] << " ";
}
}

else if (argv[1] == std::string("-r") )
{
for (auto i=argc - 1; i>1; i--)
{
std::cout << argv[i] << " ";
}
std::cout << "\n";
}

else if (argv[1] == std::string("-l") )
{
for (auto i=2; i<argc; i++)
{
std::cout << argv[i] << " \n";
}
}

else
{
for (auto i=1; i<argc; i++)
{
std::cout << argv[i] << " ";
}
std::cout << "\n";
}
return 0;
}
