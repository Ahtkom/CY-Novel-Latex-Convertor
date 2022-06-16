cmake_minimum_required(VERSION 3.0.0)
project(novel-convertor VERSION 0.1.0)

add_executable(novel main.cpp)

set(TARGET_NAME novel)

add_subdirectory(include)
add_subdirectory(src)

target_compile_features(novel PRIVATE cxx_std_17)
