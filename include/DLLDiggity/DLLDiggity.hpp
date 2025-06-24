#ifndef DLL_DIGGITY_H
#define DLL_DIGGITY_H
#include <dlfcn.h>
#include <stdexcept>
#include <string>

namespace DLLDiggity
{
  namespace types
  {
    using DLL = void*;

    template <typename ReturnType, typename... Args>
    using fn = ReturnType (*)(Args&&... args);

    enum RTLD : decltype(RTLD_LAZY)
    {
      /*
        * Relocations (resolving symbolic references to functions or variables)
        * are performed at the time a function is called, rather than 
        * immediately when the library is loaded 
      */
      Lazy = RTLD_LAZY,

      /*
        * All relocations are performed when the library is loaded, potentially
        * causing a delay during loading but ensuring that all symbols 
        * are available immediately 
      */
      Now = RTLD_NOW,

      /*
        * Symbols from the loaded library are not made available for relocation
        * processing by other dynamically loaded modules.
      */
      Local = RTLD_LOCAL,

      /*
        * Symbols from the loaded library are made available for relocation 
        * processing by other dynamically loaded modules 
      */
      Global = RTLD_GLOBAL,

      /* Do not load the object.  */
      NoLoad = RTLD_NOLOAD,

      /* Do not delete object when closed.  */
      NoDelete = RTLD_NODELETE,

      /* Mask of binding time value.  */
      BindingMask = RTLD_BINDING_MASK,

      /* Use deep binding.  */
      DeepBing = RTLD_DEEPBIND,
    };
  } // namespace types

  inline types::DLL
  load_module(const std::string& module_path, const types::RTLD mode)
  {
    return dlopen(module_path.c_str(), mode);
  }

  inline int32_t
  close_module(types::DLL module)
  {
    return dlclose(module);
  }

  template <typename fn>
  fn
  load_function(const types::DLL module, const std::string& function_name)
  {
    return reinterpret_cast<fn>(dlsym(module, function_name.c_str()));
  }

  inline std::string
  error()
  {
    /* 
      * If there is no error, dlerror() returns a null c-style string 
      * Attempting to initialize a std::string with a null c-style string 
      * causes std::logic_error to be thrown
      *
      * If that happens, there is no error according to dlerror()(big brain)
    */
    try
    {
      std::string error{dlerror()};
      return error;
    }
    catch (const std::exception& error)
    {
      return "No error";
    }
  }
} // namespace DLLDiggity
#endif
