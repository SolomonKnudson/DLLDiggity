#ifndef DLL_DIGGITY_H
#define DLL_DIGGITY_H
#include <dlfcn.h>

namespace DllDiggity
{
  template <typename ReturnType, typename... Args>
  using fn = ReturnType (*)(Args&&... args);
} // namespace DllDiggity
#endif
