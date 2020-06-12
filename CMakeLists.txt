cmake_minimum_required(VERSION 3.15)
project(csvtoany)

set(CMAKE_CXX_STANDARD 17)

add_executable(csvtoany main.cpp CsvEngine.h CsvEngine.cpp CsvEngine.h Convertable.h ConvertableJson.cpp ConvertableJson.h)
include_directories("../argparse")
include_directories("../json/include")


