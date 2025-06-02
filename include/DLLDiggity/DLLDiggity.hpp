#ifndef DLL_DIGGITY_H
#define DLL_DIGGITY_H
#include <dlfcn.h>
#include <string>

namespace DllDiggity
{
  using DLL = void*;

  template <typename ReturnType, typename... Args>
  using fn = ReturnType (*)(Args&&... args);

  inline DLL
  load_module(const std::string& module_path, const int32_t mode)
  {
    return dlopen(module_path.c_str(), mode);
  }

  inline int32_t
  close_module(DLL module)
  {
    return dlclose(module);
  }

  template <typename fn>
  fn
  load_function(const DLL module, const std::string function_name)
  {
    return reinterpret_cast<fn>(dlsym(module, function_name.c_str()));
  }
} // namespace DllDiggity
#endif
