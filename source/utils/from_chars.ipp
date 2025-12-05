#ifndef TPRT_AOC_2025_UTILS_FROM_CHARS_IPP
#define TPRT_AOC_2025_UTILS_FROM_CHARS_IPP

#include "utils/to_char.hpp"
#include "utils/to_contiguous_range.hpp"

#include <charconv>
#include <ranges>
#include <system_error>
#include <utility>

namespace tprt
{

template <std::integral T> requires (not std::same_as<T, bool>)
[[nodiscard]] constexpr auto
from_chars(input_range_of_bytes auto &&r, const int base)
noexcept -> from_chars_result<T>
{
	const auto contiguous = to_contiguous_range(
		std::forward<decltype(r)>(r) | std::views::transform(to_char));

	const auto first = std::ranges::data(contiguous);
	const auto last  = first + std::ranges::size(contiguous);

	auto value = T{};
	const auto result = std::from_chars(first, last, value, base);

	if ((result.ptr == last) and (result.ec == std::errc{}))
		return { value };
	else
		return {};
}

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_FROM_CHARS_IPP
