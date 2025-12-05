#ifndef TPRT_AOC_2025_UTILS_INPUT_RANGE_OF_BYTES_HPP
#define TPRT_AOC_2025_UTILS_INPUT_RANGE_OF_BYTES_HPP

#include "utils/byte_like.hpp"

#include <ranges>

namespace tprt
{

template <typename R>
concept input_range_of_bytes =
	std::ranges::input_range<R> and
	byte_like<std::ranges::range_value_t<R>>;

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_INPUT_RANGE_OF_BYTES_HPP
