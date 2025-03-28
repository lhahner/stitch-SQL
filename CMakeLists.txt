cmake_minimum_required(VERSION 3.10)
project(sitich-sql)
# Executable for the csv test program
add_executable(tok 
    src/stitch-sql/stitch-sql.c 
    src/stitch-sql/tokenizer.c 
    src/test/test_tokenizer.c)
# Set build type
set(CMAKE_BUILD_TYPE Debug)