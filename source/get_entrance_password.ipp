#ifndef TPRT_AOC_2025_ENTRANCE_PASSWORD_IPP
#define TPRT_AOC_2025_ENTRANCE_PASSWORD_IPP

#include "zero_counted_entrance_safe.hpp"
#include "utils/to_char.hpp"

#include <algorithm>
#include <ranges>
#include <string_view>

namespace tprt::aoc_2025
{

namespace detail
{

[[nodiscard]] constexpr auto
get_entrance_password(
	input_range_of_bytes auto &&attached_document,
	input_range_of_bytes auto &&new_line) noexcept
-> get_entrance_password_result
{
	static constexpr auto not_empty =
		[] [[nodiscard]] (std::ranges::range auto &&r)
		static constexpr noexcept
		{ return not std::ranges::empty(r); };

	try
	{
		auto rotations = attached_document
			| std::views::transform(to_char)
			| std::views::split(
				new_line | std::views::transform(to_char))
			| std::views::filter(not_empty)
			| std::views::transform(to_entrance_safe_rotation);

		const auto zces = std::ranges::fold_left(
			rotations, zero_counted_entrance_safe{ 50uz },
			[] [[nodiscard]] (auto zces, const auto r)
			static constexpr noexcept
			{ zces.turn_dial(r); return zces; });

		return zces.get_zero_count();
	}
	catch (const get_entrance_password_result::error_type &e)
	{
		return get_entrance_password_result::unexpected_type{ e };
	}
}

} // namespace detail

[[nodiscard]] constexpr auto
get_entrance_password(input_range_of_bytes auto &&attached_document) noexcept
-> get_entrance_password_result
{
	using namespace std::string_view_literals;

	return detail::get_entrance_password(attached_document, "\n"sv);
}

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_ENTRANCE_PASSWORD_IPP
