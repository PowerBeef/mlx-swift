// Apple-platform stub for the CPU JitCompiler (mlx core 0.32.1).
//
// The real mlx/backend/cpu/jit_compiler.cpp shells out via std::system,
// which is unavailable on iOS, so it is excluded on Apple platforms.
// compiled_conditional.cpp links the full call surface; with available()
// reporting false, CPU-stream compiled primitives take the interpreted
// fallback and the remaining members are unreachable (they throw if a
// future core version ever calls them unguarded).
#ifdef __APPLE__
// (Empty elsewhere: non-Apple builds compile the real jit_compiler.cpp.)
#include <stdexcept>
#include <tuple>

#include "mlx/backend/cpu/jit_compiler.h"

namespace mlx::core {

bool JitCompiler::available() {
  return false;
}

const std::tuple<bool, std::string, std::string>& JitCompiler::get_preamble() {
  static const std::tuple<bool, std::string, std::string> empty{
      false, std::string{}, std::string{}};
  return empty;
}

std::string JitCompiler::build_command(
    const std::filesystem::path&,
    const std::string&,
    const std::string&) {
  throw std::runtime_error("[JitCompiler] CPU JIT is disabled on Apple platforms.");
}

std::string JitCompiler::exec(const std::string&) {
  throw std::runtime_error("[JitCompiler] CPU JIT is disabled on Apple platforms.");
}

} // namespace mlx::core

#endif // __APPLE__
