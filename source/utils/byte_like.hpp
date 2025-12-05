#ifndef TPRT_AOC_2025_UTILS_BYTE_LIKE_HPP
#define TPRT_AOC_2025_UTILS_BYTE_LIKE_HPP

#include "utils/same_as_either.hpp"

#include <cstddef>

namespace tprt
{

template <typename T>
concept byte_like =
	same_as_either<T,
		std::byte, char, unsigned char, signed char, char8_t>;

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_IS_BYTE_LIKE_HPP
