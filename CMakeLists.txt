cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)


project(tel_book_learn)
add_executable(${PROJECT_NAME} src/main.cpp src/book.cpp src/book.hpp)
