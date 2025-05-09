cmake_minimum_required(VERSION 3.25)
project(umpire LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread filesystem system)

#set(thisproject_headerdir ${PROJECT_SOURCE_DIR}/src/components CACHE FILEPATH "Header directory")

include_directories(src)
#include_directories(src/components)
#include_directories(${thisproject_headerdir})

add_executable(um src/main.cpp)

target_link_libraries(um PRIVATE 
    fmt::fmt 
    Boost::thread 
    Boost::filesystem
    Boost::system
)


target_include_directories(um PRIVATE src)

 # configurePhase = ''
          #   cmake .
          # '';
# src/components/cache.hpp src/components/util.hpp src/components/error.hpp src/components/help.hpp