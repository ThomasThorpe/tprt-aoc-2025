#ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_HPP
#define TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_HPP

#include "utils/contiguous_range_of_either.hpp"

namespace tprt
{

template <typename R, typename V>
concept contiguous_range_of = contiguous_range_of_either<R, V>;

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_CONTIGUOUS_RANGE_OF_HPP
