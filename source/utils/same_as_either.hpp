#ifndef TPRT_AOC_2025_UTILS_SAME_AS_EITHER_HPP
#define TPRT_AOC_2025_UTILS_SAME_AS_EITHER_HPP

#include <concepts>

namespace tprt
{

template <typename T, typename U, typename... R>
concept same_as_either =
	std::same_as<T, U> or (std::same_as<T, R> or ... );

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_SAME_AS_EITHER_HPP
