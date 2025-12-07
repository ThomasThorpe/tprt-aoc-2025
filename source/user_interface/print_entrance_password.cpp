#include "user_interface/print_entrance_password.hpp"

#include "entrance/get_entrance_password.hpp"
#include "utils/file_to_string.hpp"

#include <iostream>
#include <iterator>

namespace tprt::aoc_2025
{

namespace
{

void print_help()
{ std::cout << "tprt-aoc-2025 1 input_filename" << std::endl; }

constexpr auto print_result =
	[] [[nodiscard]] (const auto entrance_password) static
	-> get_entrance_password_result
{
	std::cout << "The entrance password is: "
	          << entrance_password << std::endl;

	return entrance_password;
};

constexpr auto print_error =
	[] [[nodiscard]] (const auto error) static
	-> get_entrance_password_result
{
	std::cout << "Error getting the entrance password: "
	          << error.what() << std::endl;

	return get_entrance_password_result::unexpected_type{ error };
};

template <entrance_method... methods>
void print_entrance_password(const arguments_t arguments)
{
	if (std::ranges::empty(arguments)) { print_help(); return; }

	((get_entrance_password<methods>(
			file_to_string(*std::ranges::begin(arguments)))
		.and_then(print_result)
		.or_else(print_error))
	, ...);
}

} // anonymous namespace

void print_entrance_password(const arguments_t arguments)
{
	using enum entrance_method;

	print_entrance_password<zero_counted, zero_visited>(arguments);
}

} // namespace tprt::aoc_2025
