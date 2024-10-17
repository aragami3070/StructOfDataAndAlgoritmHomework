cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TransportProject VERSION 1.0)

# file(GLOB_RECURSE CLASSES_FILES classes/*.cpp)

add_library(ListClass STATIC ./libs/List/List.cpp ./libs/List/List.h)
add_library(TransportsClass STATIC ./libs/Transports/Transport.cpp ./libs/Transports/Transport.h)

add_executable(TransportProject main.cpp)

target_link_libraries(TransportProject PUBLIC DateClass)
target_link_libraries(TransportProject PUBLIC ListClass)
target_link_libraries(TransportProject PUBLIC TransportsClass)
