#pragma once

#include <array>
#include <cstddef>

namespace advent
{
inline std::byte day{1};
inline std::array<void (*)(), 31> advent_functions{};
void register_functions();
} // namespace advent
