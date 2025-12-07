#ifndef TPRT_AOC_2025_ZERO_VISITED_ENTRANCE_SAFE_HPP
#define TPRT_AOC_2025_ZERO_VISITED_ENTRANCE_SAFE_HPP

#include "counted_entrance_safe.hpp"

namespace tprt::aoc_2025
{

class zero_visited_entrance_safe final : public counted_entrance_safe
{
public:
	using counted_entrance_safe::counted_entrance_safe;

private:
	friend class counted_entrance_safe;

	constexpr void
	increment_count(const auto zv) noexcept
	{ count += zv; }
};

} // namespace tprt::aoc_2050

#endif // ifndef TPRT_AOC_2025_ZERO_VISITED_ENTRANCE_SAFE_HPP
