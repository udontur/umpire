cmake_minimum_required(VERSION 3.13)
project(umpire LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread chrono system)
find_package(ftxui REQUIRED)

include_directories(src)

add_executable(um src/main.cpp)

target_link_libraries(um PRIVATE 
    fmt::fmt 
    Boost::thread 
    Boost::chrono
    Boost::system
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(um PRIVATE src)
