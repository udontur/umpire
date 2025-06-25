cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(
    umpire 
    DESCRIPTION "A blazingly fast competitive programming helper"
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.2.0
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui.git
    GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
    GIT_TAG v3.2
)
FetchContent_MakeAvailable(argparse)

include_directories(src)
add_executable(um src/main.cpp)

target_link_libraries(um PRIVATE 
    fmt::fmt 
    argparse
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(um PRIVATE src)
