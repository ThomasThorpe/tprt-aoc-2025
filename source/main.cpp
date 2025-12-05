#include "arguments_t.hpp"
#include "day_t.hpp"
#include "user_interface/print_solution.hpp"
#include "utils/from_chars.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

namespace tprt::aoc_2025
{

void print_help()
{ std::cout << "tprt-aoc-2025 day_number [args...]" << std::endl; }

auto main(const arguments_t arguments) noexcept
{
	static auto print_solution =
		[args = arguments | std::views::drop(2)] [[nodiscard]]
		(const auto day) -> from_chars_result<day_t>
		{ tprt::aoc_2025::print_solution(day, args); return day; };

	static constexpr auto print_invalid_day =
		[] [[nodiscard]] () static -> from_chars_result<day_t>
		{ print_help(); return {}; };

	try
	{
		if (std::ranges::size(arguments) <= 2)
			{ print_help(); return EXIT_SUCCESS; }


		from_chars<day_t>(
			*std::ranges::next(std::ranges::begin(arguments)))
				.and_then(print_solution)
				.or_else(print_invalid_day);
	}
	catch (const std::exception &e)
	{
		std::cout << "tprt-aoc-2025 caught exception: "
		          << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

} // namespace tprt::aoc_2025

int main(int argc, char *argv[])
{
	auto arguments = std::vector<std::string_view>{};
	for (const auto i : std::views::iota(0, argc))
		static_cast<void>(arguments.emplace_back(argv[i]));

	return tprt::aoc_2025::main(arguments);
}
