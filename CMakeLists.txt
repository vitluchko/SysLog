cmake_minimum_required(VERSION 3.16)
project(Task)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task main.cpp
        ServerSocket.cpp
        ServerSocket.h
        ClientHandler.cpp
        ClientHandler.h
)
