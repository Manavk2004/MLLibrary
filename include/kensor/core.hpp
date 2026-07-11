#pragma once
// kensor/core.hpp - library-wide basics. Every kensor header includes this.

#include <cstddef>  // std::size_t
#include <cstdint>  // fixed-width integers

namespace kensor {

// Index type used for all shapes/strides. Signed on purpose: subtracting two
// unsigned sizes silently wraps around to a huge number - a classic source of
// invisible bugs in stride math. (PyTorch uses int64_t for the same reason.)
using index_t = std::int64_t;

inline constexpr const char* version() { return "0.1.0"; }

}  // namespace kensor
