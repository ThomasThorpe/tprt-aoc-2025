#ifndef TPRT_AOC_2025_UTILS_TO_CONTIGUOUS_RANGE_HPP
#define TPRT_AOC_2025_UTILS_TO_CONTIGUOUS_RANGE_HPP

#include "detail/to_contiguous_range_detail.hpp"

namespace tprt
{

// Call signatures.
//
// [[nodiscard]] constexpr auto
// to_contiguous_range(std::ranges::contiguous_range auto &&r)
// -> contiguous_view_of<std::ranges::range_value_t<decltype(r)>> auto
//
// [[nodiscard]] constexpr auto
// to_contiguous_range(std::ranges::input_range auto &&r)
// -> contiguous_range_of<std::ranges::range_value_t<decltype(r)>> auto
inline constexpr auto to_contiguous_range =
	detail::to_contiguous_range_functor{};

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_TO_CONTIGUOUS_RANGE_HPP
