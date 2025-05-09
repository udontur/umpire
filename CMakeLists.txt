cmake_minimum_required(VERSION 3.25)
project(umpire LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread filesystem system)

include_directories(src)

add_executable(um src/main.cpp)

target_link_libraries(um PRIVATE 
    fmt::fmt 
    Boost::thread 
    Boost::filesystem
    Boost::system
    Boost::compute
)

target_include_directories(um PRIVATE src)
