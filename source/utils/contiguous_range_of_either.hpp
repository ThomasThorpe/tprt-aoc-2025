#ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_EITHER_HPP
#define TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_EITHER_HPP

#include "utils/same_as_either.hpp"

#include <ranges>

namespace tprt
{

template <typename R, typename V, typename... VS>
concept contiguous_range_of_either =
	std::ranges::contiguous_range<R> and
	same_as_either<std::ranges::range_value_t<R>, V, VS...>;

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_EITHER_HPP
