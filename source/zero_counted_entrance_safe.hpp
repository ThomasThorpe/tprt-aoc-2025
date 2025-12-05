#ifndef TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP
#define TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP

#include "entrance_safe.hpp"

#include <concepts>
#include <cstddef>
#include <utility>

namespace tprt::aoc_2025
{

class entrance_safe_rotation;

class zero_counted_entrance_safe
{
public:
	template <typename... safe_arguments> requires
		std::constructible_from<entrance_safe, safe_arguments...>
	constexpr zero_counted_entrance_safe(safe_arguments&&... arguments) :
		safe{ std::forward<safe_arguments>(arguments)... }
	{}

	[[nodiscard]] constexpr auto
	get_zero_count() const noexcept { return zero_count; }

	constexpr void
	turn_dial(const entrance_safe_rotation r) noexcept
	{ safe.turn_dial(r); if (0 == safe.get_dial()) ++zero_count; }

private:
	entrance_safe safe{};
	std::size_t   zero_count{ 0 };
};

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP
