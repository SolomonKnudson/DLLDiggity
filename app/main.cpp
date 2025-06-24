#include <DLLDiggity/DLLDiggity.hpp>
#include <iostream>

int
main()
{
  std::string libCurses{"./libCurses++.so"};
  std::string libError{"Test"};
  DLLDiggity::load_module(libCurses, DLLDiggity::types::Now);
  std::cout << DLLDiggity::error() << '\n';
  return 0;
}
