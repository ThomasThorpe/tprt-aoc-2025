# tprt-aoc-2025

[Advent of code](https://adventofcode.com/2025) 2025 solutions.

## Technologies

This is a hobby project made to explore the latest C++ standards and compilers. As a result there is no minimum standard or compiler that this project will support. The project currently makes use of C++ 23 features.

The project uses cmake 3.28 as a build system.

The project has been successfully compiled and tested with the following compilers on [Kubuntu](https://kubuntu.org/) 24.04 LTS:
- [GCC 15.1](https://gcc.gnu.org/gcc-15/)

## Building & Running

1. git clone https://github.com/ThomasThorpe/tprt-aoc-2025.git
2. cd tprt-aoc-2025 && mkdir build && cd build
3. cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" ..
4. cmake --build . && ./source/tprt-aoc-2025

