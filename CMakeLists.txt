cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(
    umpire 
    DESCRIPTION "A blazingly fast competitive programming helper"
    LANGUAGES CXX
)

include(FetchContent)

if (DEFINED ENV{fmt_src})
    message("Fetching fmt source from env var: $ENV{fmt_src}")
    FetchContent_Declare(
        fmt
        SOURCE_DIR "$ENV{fmt_src}"
    )
else ()
    message("Fetching fmt source from git")
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 11.2.0
    )
endif ()
FetchContent_MakeAvailable(fmt)

if (DEFINED ENV{ftxui_src})
    message("Fetching FTXUI source from env var: $ENV{ftxui_src}")
    FetchContent_Declare(
        ftxui
        SOURCE_DIR "$ENV{ftxui_src}"
    )
else ()
    message("Fetching FTXUI source from git")
    FetchContent_Declare(
        ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
    )
endif ()
FetchContent_MakeAvailable(ftxui)

if (DEFINED ENV{argparse_src})
    message("Fetching argparse source from env var: $ENV{argparse_src}")
    FetchContent_Declare(
        argparse
        SOURCE_DIR "$ENV{argparse_src}"
    )
else ()
    message("Fetching argparse source from git")
    FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse
        GIT_TAG v3.2
    )
endif ()
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
