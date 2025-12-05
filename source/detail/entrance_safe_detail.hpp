#ifndef TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP
#define TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP

#include "entrance_safe_rotation.hpp"

#include <cstddef>
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

	static constexpr auto dial_min = dial_t{ 0 };
	static constexpr auto dial_max = dial_t{ d_max };

	constexpr explicit
	entrance_safe(const dial_t d = dial_min) : dial{ d }
	{ if (dial > dial_max) throw out_of_range_exception{}; }

	[[nodiscard]] constexpr auto
	get_dial() const noexcept { return dial; }

	constexpr void
	set_dial(const dial_t d) noexcept { dial = d; }

	constexpr void
	turn_dial(const entrance_safe_rotation r) noexcept;

private:
	dial_t dial{ 0 };
};

template <std::size_t d_max>
entrance_safe<d_max>::out_of_range_exception::out_of_range_exception() :
	std::out_of_range{ "entrance safe dial out of range" }
{}

template <std::size_t d_max>
constexpr void
entrance_safe<d_max>::turn_dial(const entrance_safe_rotation r) noexcept
{
	static constexpr auto clicks_max = dial_max + 1;

	if (entrance_safe_rotation::direction_t::left == r.get_direction())
	{
		const auto distance = r.get_distance() % clicks_max;

		if (dial >= distance)
			dial -= distance;
		else
			dial = clicks_max - (distance - dial);
	}
	else
	{
		dial += r.get_distance();
		dial = dial % clicks_max;
	}
}

} // namespace detail

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_DETAIL_ENTRANCE_SAFE_DETAIL_HPP
