cmake_minimum_required(VERSION 3.10)
project(sitich-sql)
# Executable for the csv test program
add_executable(tok src/main.c src/test_tokenizer.c src/tokenizer.c)
# Set build type
set(CMAKE_BUILD_TYPE Debug)