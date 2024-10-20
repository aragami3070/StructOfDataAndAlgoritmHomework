cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TransportProject VERSION 1.0)


add_library(ListClass STATIC ./libs/List/List.cpp ./libs/List/List.h)
add_library(TransportsClass STATIC ./libs/Transports/Transport.cpp ./libs/Transports/Transport.h)
add_library(CarTransportsClass STATIC ./libs/Transports/Car/Car.cpp ./libs/Transports/Car/Car.h)
add_library(PlaneTransportsClass STATIC ./libs/Transports/Plane/Plane.cpp ./libs/Transports/Plane/Plane.h)
add_library(TrainTransportsClass STATIC ./libs/Transports/Train/Train.cpp ./libs/Transports/Train/Train.h)

add_executable(TransportProject main.cpp)

target_link_libraries(TransportProject PUBLIC ListClass)
target_link_libraries(TransportProject PUBLIC TransportsClass CarTransportsClass PlaneTransportsClass TrainTransportsClass)
