// Apple-platform stub for the CPU JitCompiler (mlx core 0.32.1).
//
// The real mlx/backend/cpu/jit_compiler.cpp shells out via std::system,
// which is unavailable on iOS. Its full implementation is only consumed by
// cpu/compiled.cpp — already excluded on Apple platforms — but
// compiled_conditional.cpp still links JitCompiler::available(). Reporting
// "no CPU JIT" makes CPU-stream compiled primitives fall back to the
// interpreted path on every Apple platform, matching iOS semantics.
#ifdef __APPLE__
// (Empty elsewhere: non-Apple builds compile the real jit_compiler.cpp.)
#include "mlx/backend/cpu/jit_compiler.h"

namespace mlx::core {

bool JitCompiler::available() {
  return false;
}

} // namespace mlx::core

#endif // __APPLE__
