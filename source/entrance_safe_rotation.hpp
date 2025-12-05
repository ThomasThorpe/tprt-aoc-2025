#ifndef TPRT_AOC_2025_ENTRANCE_SAFE_ROTATION_HPP
#define TPRT_AOC_2025_ENTRANCE_SAFE_ROTATION_HPP

#include "utils/byte_like.hpp"
#include "utils/from_chars.hpp"
#include "utils/input_range_of_bytes.hpp"

#include <cstddef>
#include <ranges>
#include <stdexcept>
#include <string>
#include <utility>

namespace tprt::aoc_2025
{

class entrance_safe_rotation
{
public:
	struct parse_exception final : std::invalid_argument
	{ using std::invalid_argument::invalid_argument; };

	using distance_t = std::size_t;

	enum class direction_t : bool { left, right };

	constexpr explicit
	entrance_safe_rotation(input_range_of_bytes auto &&);

	[[nodiscard]] constexpr auto
	get_direction() const noexcept { return direction; }

	[[nodiscard]] constexpr auto
	get_distance() const noexcept { return distance; }

	constexpr void
	set_direction(const direction_t d) noexcept { direction = d; }

	constexpr void
	set_distance(const distance_t d) noexcept { distance = d; }

private:
	constexpr bool
	set_direction(byte_like auto ascii_direction) noexcept;

	constexpr bool
	set_distance(input_range_of_bytes auto &&) noexcept;

	direction_t direction{};
	distance_t  distance{ 0 };
};

constexpr
entrance_safe_rotation::entrance_safe_rotation(input_range_of_bytes auto &&i)
{
	if ((std::ranges::size(i) < 2) or
	    (not set_direction(*std::ranges::begin(i))) or
	    (not set_distance(i | std::views::drop(1))))
	{
		throw parse_exception{ i | std::ranges::to<std::string>() };
	}
}

constexpr bool
entrance_safe_rotation::set_direction(byte_like auto ascii_direction) noexcept
{
	switch (static_cast<char>(ascii_direction))
	{
		case 'l': [[fallthrough]];
		case 'L': direction = direction_t::left; return true;

		case 'r': [[fallthrough]];
		case 'R': direction = direction_t::right; return true;

		default: return false;
	}
}

constexpr bool
entrance_safe_rotation::set_distance(input_range_of_bytes auto &&i) noexcept
{
	const auto maybe_distance =
		from_chars<distance_t>(std::forward<decltype(i)>(i));

	if (maybe_distance) distance = *maybe_distance;

	return static_cast<bool>(maybe_distance);
}

inline constexpr auto to_entrance_safe_rotation =
	[] [[nodiscard]] (input_range_of_bytes auto &&i) static constexpr
	{ return entrance_safe_rotation{ std::forward<decltype(i)>(i) }; };

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_ENTRANCE_SAFE_ROTATION_HPP
