cmake_minimum_required(VERSION 3.13)
project(umpire LANGUAGES CXX)

cmake_policy(SET CMP0167 NEW)
cmake_policy(SET CMP0156 NEW)
cmake_policy(SET CMP0179 NEW)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread chrono system process)
find_package(ftxui REQUIRED)

include_directories(src)

add_executable(um src/main.cpp)

target_link_libraries(um PRIVATE 
    fmt::fmt 
    Boost::thread 
    Boost::chrono
    Boost::system
    Boost::process
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(um PRIVATE src)
