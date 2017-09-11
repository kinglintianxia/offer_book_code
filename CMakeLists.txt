cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(offer_book)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)

add_subdirectory(src)
