cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(
    umpire 
    DESCRIPTION "A blazingly fast competitive programming helper"
    LANGUAGES CXX
)

find_package(fmt REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread chrono system process)
find_package(ftxui REQUIRED)

include_directories(src)

add_executable(umpire src/main.cpp)

target_link_libraries(umpire PRIVATE 
    fmt::fmt 
    Boost::thread 
    Boost::chrono
    Boost::system
    Boost::process
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(umpire PRIVATE src)
