#include "user_interface/print_solution.hpp"

#include "user_interface/print_entrance_password.hpp"

#include <iostream>

namespace tprt::aoc_2025
{

void print_solution(const day_t day, const arguments_t arguments)
{
	switch (day)
	{
		case 1: print_entrance_password(arguments); break;

		default: std::cout << day << " not supported" << std::endl;
	}
}

} // namespace tprt::aoc_2025
