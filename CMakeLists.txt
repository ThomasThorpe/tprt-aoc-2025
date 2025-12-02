cmake_minimum_required(VERSION 3.28)

list(APPEND CMAKE_MESSAGE_CONTEXT tprt-aoc-2025)

set(CMAKE_COLOR_DIAGNOSTICS TRUE)

include(cmake/tprt_aoc_2025_version_detail.cmake)

project(tprt-aoc-2025
	VERSION ${tprt-aoc-2025_VERSION_DETAIL}
	DESCRIPTION "Advent of code 2025 solutions"
	HOMEPAGE_URL "https://github.com/ThomasThorpe/tprt-aoc-2025"
	LANGUAGES CXX)

add_subdirectory(source)

