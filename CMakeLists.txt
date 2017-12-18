cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(offer_book)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")	# C++11 & thread
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")
add_subdirectory(src)
