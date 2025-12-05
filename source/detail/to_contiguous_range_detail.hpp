#ifndef TPRT_AOC_2025_DETAIL_TO_CONTIGUOUS_RANGE_DETAIL_HPP
#define TPRT_AOC_2025_DETAIL_TO_CONTIGUOUS_RANGE_DETAIL_HPP

#include "utils/contiguous_range_of.hpp"
#include "utils/contiguous_view_of.hpp"

#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

namespace tprt::detail
{

struct to_contiguous_range_functor
{
	template <std::ranges::contiguous_range R>
	[[nodiscard]] static constexpr auto
	operator()(R&& r)
	-> contiguous_view_of<std::ranges::range_value_t<R>> auto
	{ return std::views::all(std::forward<R>(r)); }

	template <std::ranges::input_range R>
	[[nodiscard]] static constexpr auto
	operator()(R&& r)
	-> contiguous_range_of<std::ranges::range_value_t<R>> auto
	{
		using return_range_t =
			std::vector<std::ranges::range_value_t<R>>;

		if constexpr (std::is_rvalue_reference_v<R>)
		{
			return std::forward<R>(r)
				| std::views::as_rvalue
				| std::ranges::to<return_range_t>();
		}
		else
		{
			return std::forward<R>(r)
				| std::ranges::to<return_range_t>();
		}
	}
};

} // namespace tprt::detail

#endif // ifndef TPRT_AOC_2025_DETAIL_TO_CONTIGUOUS_RANGE_DETAIL_HPP
