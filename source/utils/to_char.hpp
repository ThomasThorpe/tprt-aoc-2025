#ifndef TPRT_AOC_2025_UTILS_TO_CHAR_HPP
#define TPRT_AOC_2025_UTILS_TO_CHAR_HPP

#include "utils/byte_like.hpp"

namespace tprt
{

inline constexpr auto to_char =
	[] [[nodiscard]] (byte_like auto byte) static constexpr noexcept
	{ return static_cast<char>(byte); };

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_TO_CHAR_HPP
