cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)


project(tel_book_learn)

set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src")
set(PROJECT_CONTRIB_DIR "${CMAKE_SOURCE_DIR}/contrib/build/${PROJECT_BUILD_TYPE}")

if(WIN32)
    set(${BOOST_ROOT} "C:\\Program Files\\boost\\boost_1_61_0")
endif()

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
