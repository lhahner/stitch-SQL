cmake_minimum_required(VERSION 3.10)
project(readcsv-c)
include(CTest)

# Executable for the csv test program
add_executable(o 
                    ./src/main.c 
                )

# Add tests
enable_testing()
add_test(NAME TEST_CSV COMMAND csv)

# Set build type
set(CMAKE_BUILD_TYPE Debug)