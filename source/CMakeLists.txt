add_executable(tprt-aoc-2025)

set_target_properties(tprt-aoc-2025 PROPERTIES
	COMPILE_WARNING_AS_ERROR TRUE
	LINK_LIBRARIES_ONLY_TARGETS TRUE)

target_compile_features(tprt-aoc-2025 PRIVATE cxx_std_23)

target_compile_options(tprt-aoc-2025 PRIVATE
	-Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

target_sources(tprt-aoc-2025 PRIVATE FILE_SET HEADERS FILES
	arguments_t.hpp
	day_t.hpp
	entrance_password.hpp
	entrance_safe.hpp
	entrance_safe_rotation.hpp
	get_entrance_password.hpp
	get_entrance_password.ipp
	zero_counted_entrance_safe.hpp
	detail/entrance_safe_detail.hpp
	detail/to_contiguous_range_detail.hpp
	user_interface/print_entrance_password.hpp
	user_interface/print_solution.hpp
	utils/byte_like.hpp
	utils/contiguous_range_of_either.hpp
	utils/contiguous_range_of.hpp
	utils/contiguous_view_of.hpp
	utils/file_to_string.hpp
	utils/from_chars.hpp
	utils/from_chars.ipp
	utils/input_range_of_bytes.hpp
	utils/same_as_either.hpp
	utils/to_char.hpp
	utils/to_contiguous_range.hpp)

target_sources(tprt-aoc-2025 PRIVATE
	main.cpp
	user_interface/print_entrance_password.cpp
	user_interface/print_solution.cpp)

get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if ((NOT is_multi_config) AND (NOT CMAKE_BUILD_TYPE))
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()
