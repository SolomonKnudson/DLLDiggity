#include <DLLDiggity/DLLDiggity.hpp>
#include <iostream>

int
main()
{
  std::string lib{"./libCurses++.so"};
  std::string libError{"Test"};

  if (DLLDiggity::load_module(lib, DLLDiggity::types::Now))
  {
    std::cout << lib << " is now loaded!\n";
  }
  else
  {
    std::cerr << DLLDiggity::error() << '\n';
    return 1;
  }

  return 0;
}
