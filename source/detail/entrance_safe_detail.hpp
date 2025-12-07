#ifndef TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP
#define TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP

#include "entrance_safe_rotation.hpp"

#include <algorithm>
#include <cstddef>
#include <ranges>
#include <stdexcept>

namespace tprt::aoc_2025
{

namespace detail
{

template <std::size_t d_max>
class entrance_safe
{
public:
	struct out_of_range_exception final : std::out_of_range
	{ out_of_range_exception(); };

	using dial_t = std::size_t;
	using zeroes_visited = std::size_t;

	static constexpr auto dial_min = dial_t{ 0 };
	static constexpr auto dial_max = dial_t{ d_max };

	constexpr explicit
	entrance_safe(const dial_t d = dial_min) : dial{ d }
	{ if (dial > dial_max) throw out_of_range_exception{}; }

	[[nodiscard]] constexpr auto
	get_dial() const noexcept { return dial; }

	constexpr void
	set_dial(const dial_t d) noexcept { dial = d; }

	constexpr auto
	turn_dial(const entrance_safe_rotation) noexcept -> zeroes_visited;

private:
	constexpr auto
	turn_dial(
		const entrance_safe_rotation::distance_t,
		auto &&do_single_turn) noexcept
	-> zeroes_visited;

	dial_t dial{ 0 };
};

template <std::size_t d_max>
entrance_safe<d_max>::out_of_range_exception::out_of_range_exception() :
	std::out_of_range{ "entrance safe dial out of range" }
{}

template <std::size_t d_max>
constexpr auto
entrance_safe<d_max>::turn_dial(const entrance_safe_rotation r) noexcept
-> zeroes_visited
{
	auto turn_left_once =
		[this] () constexpr noexcept
		{ dial = 0 == dial ? dial_max : dial - 1; };

	auto turn_right_once =
		[this] () constexpr noexcept
		{ dial = dial_max == dial ? 0 : dial + 1; };

	if (entrance_safe_rotation::direction_t::left == r.get_direction())
		return turn_dial(r.get_distance(), turn_left_once);
	else
		return turn_dial(r.get_distance(), turn_right_once);
}

template <std::size_t d_max>
constexpr auto
entrance_safe<d_max>::turn_dial(
	const entrance_safe_rotation::distance_t d,
	auto &&do_single_turn) noexcept -> zeroes_visited
{
	using distance_t = entrance_safe_rotation::distance_t;

	return std::ranges::fold_left(
		std::views::iota(distance_t{ 0 }, d), zeroes_visited{ 0 },
		[this, &do_single_turn] [[nodiscard]]
		(const auto zv, const auto) constexpr noexcept
		{ do_single_turn(); return zv + (0 == dial); });

}

} // namespace detail

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP
