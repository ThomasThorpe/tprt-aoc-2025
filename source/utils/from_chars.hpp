#ifndef TPRT_AOC_2025_UTILS_FROM_CHARS_HPP
#define TPRT_AOC_2025_UTILS_FROM_CHARS_HPP

#include "utils/input_range_of_bytes.hpp"

#include <concepts>
#include <optional>

namespace tprt
{

template <std::integral T>
using from_chars_result = std::optional<T>;

template <std::integral T> requires (not std::same_as<T, bool>)
[[nodiscard]] constexpr auto
from_chars(input_range_of_bytes auto &&, const int base = 10)
noexcept -> from_chars_result<T>;

} // namespace tprt

#include "utils/from_chars.ipp"

#endif // ifndef TPRT_AOC_2025_UTILS_FROM_CHARS_HPP
