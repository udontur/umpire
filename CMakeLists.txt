cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)

project(umpire)

add_executable(um src/main.cpp)

target_link_libraries(um fmt::fmt)