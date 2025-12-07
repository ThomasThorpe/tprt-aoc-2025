#ifndef TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP
#define TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP

#include "counted_entrance_safe.hpp"

namespace tprt::aoc_2025
{

class zero_counted_entrance_safe final : public counted_entrance_safe
{
public:
	using counted_entrance_safe::counted_entrance_safe;

private:
	friend class counted_entrance_safe;

	constexpr void
	increment_count(const auto) noexcept
	{ count += (0 == safe.get_dial()); }
};

} // namespace tprt::aoc_2025

#endif // ifndef TPRT_AOC_2025_ZERO_COUNTED_ENTRANCE_SAFE_HPP
