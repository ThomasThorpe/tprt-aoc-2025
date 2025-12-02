add_executable(tprt-aoc-2025)

set_target_properties(tprt-aoc-2025 PROPERTIES
	COMPILE_WARNING_AS_ERROR TRUE
	LINK_LIBRARIES_ONLY_TARGETS TRUE)

target_compile_features(tprt-aoc-2025 PRIVATE cxx_std_23)

target_compile_options(tprt-aoc-2025 PRIVATE
	-Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

target_sources(tprt-aoc-2025 PRIVATE FILE_SET HEADERS FILES
	dummy.hpp)

target_sources(tprt-aoc-2025 PRIVATE
	main.cpp)

get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if ((NOT is_multi_config) AND (NOT CMAKE_BUILD_TYPE))
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()
