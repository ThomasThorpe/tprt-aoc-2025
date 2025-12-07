#ifndef TPRT_AOC_2025_ENTRANCE_COUNTED_ENTRANCE_SAFE_HPP
#define TPRT_AOC_2025_ENTRANCE_COUNTED_ENTRANCE_SAFE_HPP

#include "entrance/entrance_safe.hpp"
#include "entrance/entrance_safe_rotation.hpp"

#include <concepts>
#include <cstddef>
#include <utility>

namespace tprt::aoc_2025
{

template <typename T>
concept count_incrementor = requires (T t, entrance_safe::zeroes_visited zv)
	{ t.increment_count(zv); };

class counted_entrance_safe
{
public:
	using count_t = std::size_t;

	template <typename... safe_arguments> requires
		std::constructible_from<entrance_safe, safe_arguments...>
	constexpr counted_entrance_safe(safe_arguments&&... arguments) :
		safe{ std::forward<safe_arguments>(arguments)... }
	{}

	[[nodiscard]] constexpr auto
	get_count() const noexcept { return count; }

	constexpr void
	turn_dial(
		this count_incrementor auto &&self,
		const entrance_safe_rotation r) noexcept
	{ self.increment_count(self.safe.turn_dial(r)); }

	entrance_safe safe{};
	count_t       count{ 0 };
};

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_ENTRANCE_COUNTED_ENTRANCE_SAFE_HPP
