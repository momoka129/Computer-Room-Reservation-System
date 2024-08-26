cmake_minimum_required(VERSION 3.28)
project(Computer_room_reservation_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(Computer_room_reservation_system main.cpp
        Identity.h
        Student.cpp
        Student.h)
