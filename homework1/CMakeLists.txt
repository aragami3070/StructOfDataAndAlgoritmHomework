cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testCmake VERSION 1.0)

# file(GLOB_RECURSE CLASSES_FILES classes/*.cpp)

add_library(DateClass STATIC ./libs/Date/Date.cpp ./libs/Date/Date.h)
add_library(ListClass STATIC ./libs/List/List.cpp ./libs/List/List.h)
add_library(ProductsClass STATIC ./libs/Products/Product.cpp ./libs/Products/Product.h)

add_executable(testCmake main.cpp)

target_link_libraries(testCmake PUBLIC TestClass)
