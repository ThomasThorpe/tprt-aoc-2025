#ifndef TPRT_AOC_2025_ENTRANCE_GET_ENTRANCE_PASSWORD_HPP
#define TPRT_AOC_2025_ENTRANCE_GET_ENTRANCE_PASSWORD_HPP

#include "entrance/entrance_password.hpp"
#include "entrance/entrance_safe_rotation.hpp"
#include "utils/input_range_of_bytes.hpp"

#include <expected>

namespace tprt::aoc_2025
{

enum class entrance_method : bool { zero_counted, zero_visited };

using get_entrance_password_result = std::expected<
	entrance_password, entrance_safe_rotation::parse_exception>;

template <entrance_method>
[[nodiscard]] constexpr auto
get_entrance_password(input_range_of_bytes auto &&attached_document) noexcept
-> get_entrance_password_result;

} // namespace tprt::aoc_2025

#include "get_entrance_password.ipp"

#endif // ifndef TPRT_AOC_2025_ENTRANCE_GET_ENTRANCE_PASSWORD_HPP
