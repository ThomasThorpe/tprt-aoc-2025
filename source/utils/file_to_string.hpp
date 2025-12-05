#ifndef TPRT_AOC_2025_UTILS_FILE_TO_STRING_HPP
#define TPRT_AOC_2025_UTILS_FILE_TO_STRING_HPP

#include <cstddef>
#include <fstream>
#include <string>
#include <string_view>

namespace tprt
{

[[nodiscard]] auto
file_to_string(std::ifstream file) -> std::string
{
	auto s = std::string{};

	file.seekg(0, std::ios::end);
	s.reserve(static_cast<std::size_t>(file.tellg()));
	file.seekg(0, std::ios::beg);

	static_cast<void>(s.assign(
		std::istreambuf_iterator<char>{ file },
		std::istreambuf_iterator<char>{}));

	return s;
}

[[nodiscard]] auto
file_to_string(const std::string &filename) -> std::string
{ return file_to_string(std::ifstream{ filename }); }

[[nodiscard]] auto
file_to_string(const std::string_view filename) -> std::string
{ return file_to_string(std::string{ filename }); }

} // namespace tprt

#endif // ifndef TPRT_AOC_2025_UTILS_FILE_TO_STRING_HPP
