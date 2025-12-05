#ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_VIEW_OF_HPP
#define TPRT_AOC_2025_UTILS_CONTIGUOUS_VIEW_OF_HPP

#include "utils/contiguous_range_of.hpp"

#include <ranges>

namespace tprt
{

template <typename R, typename V>
concept contiguous_view_of =
	std::ranges::view<R> and contiguous_range_of<R, V>;

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_VIEW_OF_HPP
